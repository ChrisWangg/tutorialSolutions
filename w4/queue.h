#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <stdbool.h>

typedef struct queue *Queue;

// Creates a new empty queue
Queue QueueNew(void);

// Enqueues an item into the queue
void QueueEnqueue(Queue q, int item);

// Dequeues an item from the queue and returns it
// Assumes that the queue is not empty
int QueueDequeue(Queue q);

bool QueueIsEmpty(Queue q);

// Frees the queue
void QueueFree(Queue q);

#endif // QUEUE_H
