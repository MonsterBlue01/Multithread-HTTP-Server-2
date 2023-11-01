#ifndef SERVER_H
#define SERVER_H

#define DEFAULT_PORT 8080
#define MAX_CLIENTS 100

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

typedef enum {
    SERVER_STOPPED,
    SERVER_RUNNING,
    SERVER_PAUSED
} ServerStatus;

typedef struct {
    int port;
    int max_clients;
} ServerConfig;

typedef struct {
    ServerStatus status;
    ServerConfig config;
    int socket;
    int clients[MAX_CLIENTS];
    int clients_count;
} ServerState;

int server_init(ServerConfig* config);

int server_start(ServerState* state);

int server_handle_client(int client_socket);

int server_stop(ServerState* state);

int server_cleanup(ServerState* state);

#endif // SERVER_H