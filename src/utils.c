#include "utils.h"
#include <stdarg.h>
#include <string.h>

static LogLevel current_log_level = INFO;
static FILE* log_file = NULL;

void init_logging(FILE* file) {
    if (file != NULL) {
        log_file = file;
    } else {
        log_file = stderr;
    }
}

void set_log_level(LogLevel level) {
    current_log_level = level;
}

void log_message(LogLevel level, const char* message, ...) {
    if (level < current_log_level) {
        return;
    }

    va_list args;
    va_start(args, message);

    vfprintf(log_file, message, args);
    fprintf(log_file, "\n");

    va_end(args);
}

void handle_error(const char* message, int exit_code) {
    log_message(ERROR, message);
    if (exit_code != 0) {
        exit(exit_code);
    }
}

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        handle_error("Memory allocation failed", 1);
    }
    return ptr;
}

void* safe_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        handle_error("Memory reallocation failed", 1);
    }
    return new_ptr;
}

void safe_free(void** ptr) {
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}