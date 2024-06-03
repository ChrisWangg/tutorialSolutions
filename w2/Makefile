# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRC1 = listCode.c
SRC2 = palindrome.c
SRC3 = twoSum.c
SRC4 = towerofHanoi.c

# Output executables
OUT1 = listCode
OUT2 = palindrome
OUT3 = twoSum
OUT4 = towerofHanoi

# Default target
all: $(OUT1) $(OUT2) $(OUT3) $(OUT4)

# Rule to compile listCode.c into an executable
$(OUT1): $(SRC1)
	$(CC) $(CFLAGS) -o $(OUT1) $(SRC1)

# Rule to compile palindrome.c into an executable
$(OUT2): $(SRC2)
	$(CC) $(CFLAGS) -o $(OUT2) $(SRC2)

# Rule to compile twoSum.c into an executable
$(OUT3): $(SRC3)
	$(CC) $(CFLAGS) -o $(OUT3) $(SRC3)

# Rule to compile towerofHanoi.c into an executable
$(OUT4): $(SRC4)
	$(CC) $(CFLAGS) -o $(OUT4) $(SRC4)

# Clean target to remove the executables
clean:
	rm -f $(OUT1) $(OUT2) $(OUT3) $(OUT4)

# PHONY targets
.PHONY: all clean
