#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>

#define PORT 8080

void handleGetRequest(int client_fd, char *filename) {
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

int main(void) {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

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

    printf("Listening on port %d\n", PORT);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        char buffer[1024] = {0};
        int bytes_read = read(client_fd, buffer, 1024);
        
        char method[8], filename[256], http_version[16];
        sscanf(buffer, "%s %s %s", method, filename, http_version);
        char *trimmed_filename = filename;
        if (filename[0] == '/') {
            trimmed_filename++;
        }

        char *content = strstr(buffer, "\r\n\r\n");
        long content_length = 0;
        if (content != NULL) {
            content += 4;
            content_length = bytes_read - (content - buffer);
        }

        if (strcmp(method, "GET") == 0) {
            handleGetRequest(client_fd, trimmed_filename);
        } else if (strcmp(method, "PUT") == 0) {
            handlePutRequest(client_fd, trimmed_filename, content, content_length);
        } else {
            printf("Unsupported HTTP method: %s\n", method);
        }

        close(client_fd);
    }

    return 0;
}
