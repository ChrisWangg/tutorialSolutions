# Makefile

CC = gcc
CFLAGS = -Wall -Werror -std=c11

OBJS = Graph.o Set.o reachable.o

all: testReachable

testReachable: testReachable.o $(OBJS)
	$(CC) $(CFLAGS) -o testReachable testReachable.o $(OBJS)

Graph.o: Graph.c Graph.h
	$(CC) $(CFLAGS) -c Graph.c

Set.o: Set.c Set.h
	$(CC) $(CFLAGS) -c Set.c

reachable.o: reachable.c Graph.h Set.h
	$(CC) $(CFLAGS) -c reachable.c

testReachable.o: testReachable.c Graph.h Set.h
	$(CC) $(CFLAGS) -c testReachable.c

clean:
	rm -f *.o testReachable

