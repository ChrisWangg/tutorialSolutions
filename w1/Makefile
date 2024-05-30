# Makefile for compiling listCode.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source file
SRC = listCode.c

# Output executable
OUT = listCode

# Default target
all: $(OUT)

# Rule to compile the source file into an executable
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean target to remove the executable
clean:
	rm -f $(OUT)

# PHONY targets
.PHONY: all clean
