CC = gcc
CFLAGS = -Iinclude -Wall -g
LDFLAGS = -pthread

# Object files for the main server program
OBJ = src/client_handler.o src/server.o src/thread_pool.o src/utils.o
# Object files for the utils test
TEST_UTILS_OBJ = tests/test_utils.o src/utils.o
# Object files for the thread pool test
TEST_THREAD_POOL_OBJ = tests/test_thread_pool.o src/thread_pool.o src/utils.o

all: server client tests

server: $(OBJ) src/main.o
	$(CC) -o $@ $^ $(LDFLAGS)

client:
	@echo "Build your client target here"

# Compile the utils test program
test_utils: $(TEST_UTILS_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile the thread pool test program
test_thread_pool: $(TEST_THREAD_POOL_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Generic rule for compiling object files
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f src/*.o tests/*.o server client test_utils test_thread_pool
