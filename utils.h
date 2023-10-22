#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    INFO,
    WARNING,
    ERROR,
    DEBUG
} LogLevel;

void init_logging(FILE* log_file);

void set_log_level(LogLevel level);

void log_messge(LogLevel level, const char* message, ...);

void handle_error(const char* message, int exit_code);

void safe_malloc(size_t size);

void safe_realloc(void* ptr, size_t size);

void safe_free(void** ptr);

#endif