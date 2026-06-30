# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Source files
SRC = src/main.c src/decoder.c src/memory.c

# Output executable
TARGET = decoder

# Default target
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Clean generated files
clean:
	rm -f $(TARGET) decoder.exe *.o