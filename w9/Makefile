# Makefile for compiling HashTable ADT with gcc

CC = gcc
CFLAGS = -Wall -Werror -O2

# The executable file to be generated
TARGET = hashtable_test

# Source files
SRCS = main.c HashTable.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile main.c into main.o
main.o: main.c HashTable.h
	$(CC) $(CFLAGS) -c main.c

# Compile HashTable.c into HashTable.o
HashTable.o: HashTable.c HashTable.h
	$(CC) $(CFLAGS) -c HashTable.c

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
