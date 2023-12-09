#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include "queue.h"
#include "log.h"

#define PORT 8080
#define THREAD_POOL_SIZE 4

pthread_t thread_pool[THREAD_POOL_SIZE];
queue_t *request_queue;

void handleGetRequest(int client_fd, char *filename) {
    log_message(LOG_INFO, "Handling GET request for %s", filename);
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        char *response = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
        send(client_fd, response, strlen(response), 0);
        return;
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(fsize + 1);
    fread(buffer, 1, fsize, file);
    fclose(file);

    char header[1024];
    sprintf(header, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n", fsize);
    send(client_fd, header, strlen(header), 0);
    send(client_fd, buffer, fsize, 0);

    free(buffer);
}


void handlePutRequest(int client_fd, char *filename, char *content, long content_length) {
    log_message(LOG_INFO, "Handling PUT request for %s", filename);
    FILE *file = fopen(filename, "rb");
    bool isNewFile = false;
    if (file == NULL) {
        isNewFile = true;
    } else {
        fclose(file);
    }

    file = fopen(filename, "wb");
    if (file == NULL) {
        char *response = "HTTP/1.1 500 Internal Server Error\r\nContent-Length: 0\r\n\r\n";
        send(client_fd, response, strlen(response), 0);
        return;
    }

    fwrite(content, 1, content_length, file);
    fclose(file);

    char *response;
    if (isNewFile) {
        response = "HTTP/1.1 201 Created\r\nContent-Length: 0\r\n\r\n";
    } else {
        response = "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n";
    }
    send(client_fd, response, strlen(response), 0);
}

void *worker_thread_function(void *arg) {
    log_message(LOG_INFO, "Worker thread started");
    while (1) {
        int *client_fd;
        queue_pop(request_queue, (void **)&client_fd);
        if (client_fd != NULL) {
            log_message(LOG_INFO, "Processing connection: %d", *client_fd);
            char buffer[1024] = {0};
            int bytes_read = read(*client_fd, buffer, sizeof(buffer));
            printf("Bytes read from connection %d: %d\n", *client_fd, bytes_read);
            if (bytes_read > 0) {
                log_message(LOG_INFO, "Request: %s", buffer);
                char method[8], filename[256], http_version[16];
                sscanf(buffer, "%s %s %s", method, filename, http_version);

                char *trimmed_filename = filename;
                if (filename[0] == '/') {
                    trimmed_filename++;
                }

                if (strcmp(method, "GET") == 0) {
                    log_message(LOG_INFO, "Handling GET request for %s", trimmed_filename);
                    handleGetRequest(*client_fd, trimmed_filename);
                } else if (strcmp(method, "PUT") == 0) {
                    log_message(LOG_INFO, "Handling PUT request for %s", trimmed_filename);
                    char *content = strstr(buffer, "\r\n\r\n");
                    long content_length = 0;
                    if (content != NULL) {
                        content += 4;  // Skip over "\r\n\r\n"
                        content_length = bytes_read - (content - buffer);
                    }
                    handlePutRequest(*client_fd, trimmed_filename, content, content_length);
                } else if (bytes_read < 0) {
                    perror("Read error");
                }
            }

            close(*client_fd);
            log_message(LOG_INFO, "Closed connection: %d", *client_fd);
            free(client_fd);
        }
    }
    (void)arg;
    return NULL;
}

void create_thread_pool(void) {
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_create(&thread_pool[i], NULL, worker_thread_function, NULL);
    }
}

void join_thread_pool(void) {
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_join(thread_pool[i], NULL);
    }
}

int main(void) {
    open_log_file();
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    request_queue = queue_new(10);
    create_thread_pool();

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    log_message(LOG_INFO, "Listening on port %d", PORT);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }
        log_message(LOG_INFO, "Accepted connection: %d", client_fd);

        int *client_fd_ptr = malloc(sizeof(int));
        *client_fd_ptr = client_fd;
        log_message(LOG_INFO, "Pushing connection %d to queue", *client_fd_ptr);
        queue_push(request_queue, client_fd_ptr);
    }

    join_thread_pool();
    queue_delete(&request_queue);

    close_log_file();
    return 0;
}
