# Use clang to compile graph.c and graph.h

CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c11 -g

all: graph

graph: graph.c graph.h
	$(CC) $(CFLAGS) -o graph graph.c

clean:
	rm -f graph