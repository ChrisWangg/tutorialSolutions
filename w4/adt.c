#include <stdio.h>
#include "stack.h"
#include "queue.h"

// ANSI color codes for pretty output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

// Function to print test results with colors
void print_result(int actual, int expected, const char *test_name) {
    printf(CYAN "%s: " RESET, test_name);
    if (actual == expected) {
        printf(GREEN "PASSED" RESET "\n");
    } else {
        printf(RED "FAILED" RESET " (expected %d, got %d)\n", expected, actual);
    }
}

int main(void) {
    int test_count = 0;
    int pass_count = 0;

    Stack s = StackNew();

    StackPush(s, 10);
    StackPush(s, 20);
    StackPush(s, 30);

    // Test StackSize
    test_count++;
    int expected_stack_size = 3;
    int actual_stack_size = StackSize(s);
    print_result(actual_stack_size, expected_stack_size, "Stack size after pushes");
    if (actual_stack_size == expected_stack_size) pass_count++;

    // Test StackPop
    test_count++;
    int expected_pop = 30;
    int actual_pop = StackPop(s);
    print_result(actual_pop, expected_pop, "Stack pop");
    if (actual_pop == expected_pop) pass_count++;

    // Test StackSize after pop
    test_count++;
    expected_stack_size = 2;
    actual_stack_size = StackSize(s);
    print_result(actual_stack_size, expected_stack_size, "Stack size after pop");
    if (actual_stack_size == expected_stack_size) pass_count++;

    Queue q = QueueNew();
    QueueEnqueue(q, 10);
    QueueEnqueue(q, 20);
    QueueEnqueue(q, 30);

    // Test QueueDequeue
    test_count++;
    expected_pop = 10;
    actual_pop = QueueDequeue(q);
    print_result(actual_pop, expected_pop, "Queue dequeue 1");
    if (actual_pop == expected_pop) pass_count++;

    test_count++;
    expected_pop = 20;
    actual_pop = QueueDequeue(q);
    print_result(actual_pop, expected_pop, "Queue dequeue 2");
    if (actual_pop == expected_pop) pass_count++;

    test_count++;
    expected_pop = 30;
    actual_pop = QueueDequeue(q);
    print_result(actual_pop, expected_pop, "Queue dequeue 3");
    if (actual_pop == expected_pop) pass_count++;

    QueueEnqueue(q, 40);
    // Test QueueDequeue after enqueue
    test_count++;
    expected_pop = 40;
    actual_pop = QueueDequeue(q);
    print_result(actual_pop, expected_pop, "Queue dequeue after enqueue");
    if (actual_pop == expected_pop) pass_count++;

    QueueEnqueue(q, 20);
    QueueEnqueue(q, 30);

    test_count++;
    expected_pop = 20;
    actual_pop = QueueDequeue(q);
    print_result(actual_pop, expected_pop, "Queue dequeue 4");
    if (actual_pop == expected_pop) pass_count++;

    test_count++;
    expected_pop = 30;
    actual_pop = QueueDequeue(q);
    print_result(actual_pop, expected_pop, "Queue dequeue 5");
    if (actual_pop == expected_pop) pass_count++;

    // Free the structures
    StackFree(s);
    QueueFree(q);

    // Print final test results summary
    printf(YELLOW "\nTest Summary:\n" RESET);
    printf(GREEN "Passed: %d" RESET " / %d\n", pass_count, test_count);
    if (pass_count == test_count) {
        printf(GREEN "All tests passed!\n" RESET);
    } else {
        printf(RED "Some tests failed.\n" RESET);
    }

    return 0;
}
