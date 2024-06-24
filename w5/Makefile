CC = clang
CFLAGS = -Wall -Wvla -Werror -g

##############################################################################

asan: CFLAGS += -fsanitize=address,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

##############################################################################

all: problematicList

problematicList: problematicList.c
	$(CC) $(CFLAGS) -o problematicList problematicList.c
fixedList: fixedList.c
	$(CC) $(CFLAGS) -o fixedList fixedList.c

##############################################################################

clean:
	rm -f problematicList fixedList
