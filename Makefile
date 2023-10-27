CC = gcc
CFLAGS = -Iinclude -Wall -g
LDFLAGS =

OBJ = src/client_handler.o src/server.o src/thread_pool.o src/utils.o
TEST_OBJ = tests/test_utils.o src/utils.o

all: server client

server: $(OBJ) src/main.o
	$(CC) -o $@ $^ $(LDFLAGS)

client:
	@echo "Build your client target here"

tests: $(TEST_OBJ)
	$(CC) -o test_program $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f src/*.o tests/*.o server client tests
