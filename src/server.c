#include "server.h"
#include "utils.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int server_init(ServerConfig* config) {
    config->port = DEFAULT_PORT;
    config->max_clients = MAX_CLIENTS;
    return 0;
}

int server_start(ServerState* state) {
    state->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (state->socket == -1) {
        log_message(ERROR, "Failed to create socket");
        return -1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(state->config.port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(state->socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        log_message(ERROR, "Bind failed");
        return -1;
    }

    if (listen(state->socket, state->config.max_clients) < 0) {
        log_message(ERROR, "Listen failed");
        return -1;
    }

    state->status = SERVER_RUNNING;

    return 0;
}

int server_handle_client(int client_socket) {
    char response[] = "Hello, client!";
    send(client_socket, response, sizeof(response), 0);
    return 0;
}

int server_stop(ServerState* state) {
    if (state->status != SERVER_RUNNING) {
        return -1;
    }

    close(state->socket);
    state->status = SERVER_STOPPED;

    return 0;
}

int server_cleanup(ServerState* state) {
    state->status = SERVER_STOPPED;

    return 0;
}