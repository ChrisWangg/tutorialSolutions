# Makefile to compile adt.c into queue_test and tree.c into tree

CC = gcc
CFLAGS = -Wall -g  # -Wall for warnings, -g for debugging

# Executable targets
TARGET_QUEUE_TEST = queue_test
TARGET_TREE = tree

# Source files for each target
SRCS_QUEUE_TEST = adt.c stack.c queue.c
SRCS_TREE = tree.c

# Default target to compile both executables
all: $(TARGET_QUEUE_TEST) $(TARGET_TREE)

# Compile queue_test target from adt.c
$(TARGET_QUEUE_TEST): $(SRCS_QUEUE_TEST)
	$(CC) $(CFLAGS) -o $(TARGET_QUEUE_TEST) $(SRCS_QUEUE_TEST)

# Compile tree target from tree.c
$(TARGET_TREE): $(SRCS_TREE)
	$(CC) $(CFLAGS) -o $(TARGET_TREE) $(SRCS_TREE)

# Clean target to remove both executables
clean:
	rm -f $(TARGET_QUEUE_TEST) $(TARGET_TREE)

.PHONY: all clean
