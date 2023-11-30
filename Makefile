CC = clang
CFLAGS = -Wall -Wextra -Werror -pedantic

TARGET = memory

all: $(TARGET)

$(TARGET): memory.c
	$(CC) $(CFLAGS) memory.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
