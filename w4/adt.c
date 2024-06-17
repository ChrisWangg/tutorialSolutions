#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main(void) {
    Stack *s = StackNew();

    StackPush(s, 10);
    StackPush(s, 20);
    StackPush(s, 30);

    printf("Stack size: %d\n", StackSize(s)); // Output: 3
    printf("Popped item: %d\n", StackPop(s)); // Output: 30
    printf("Stack size: %d\n", StackSize(s)); // Output: 2

    Queue q = QueueNew();
    QueueEnqueue(q, 10);
    QueueEnqueue(q, 20);
    QueueEnqueue(q, 30);

    printf("test\n");
    printf("Popped item: %d\n", QueueDequeue(q)); // Output: 10
    printf("Popped item: %d\n", QueueDequeue(q)); // Output: 20
    printf("Popped item: %d\n", QueueDequeue(q)); // Output: 30

    QueueEnqueue(q, 40);
    printf("Popped item: %d\n", QueueDequeue(q)); // Output: 40

    QueueEnqueue(q, 20);
    QueueEnqueue(q, 30);
    printf("Popped item: %d\n", QueueDequeue(q)); // Output: 20
    QueueEnqueue(q, 50);
    printf("Popped item: %d\n", QueueDequeue(q)); // Output: 30


    StackFree(s);
    QueueFree(q);
    return 0;
}
