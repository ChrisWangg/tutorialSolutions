#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
// Function Declarations
int sumNodes(struct node *list);
struct node *deleteFirstInstance(struct node *list, int value);

// Function to create a node in memory
struct node *createNode(int value) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->value = value;
    new->next = NULL;
    return new;
}

// Function to add node to the head of the list
struct node *prependNode(int value, struct node *list) {
    struct node *new = createNode(value);
    new->next = list;
    return new;
}

// Function to free a linked list
void freeList(struct node *list) {
    while (list != NULL) {
        struct node *del = list; 
        list = list->next;
        free(del);
    }
}

// Function to print out a linked list
void printList(struct node *list) {
    printf("List contents:\n");
    while (list != NULL) {
        printf("%d->", list->value);
        list = list->next;
    }
    printf("X\n");
}

int main(void) {
    struct node *list = NULL;
    list = prependNode(5, list);
    list = prependNode(1, list);
    list = prependNode(2, list);
    list = prependNode(3, list);
    list = prependNode(3, list);
    printList(list);

    printf("Sum of nodes: %d\n", sumNodes(list));

    list = deleteFirstInstance(list, 0);
    printList(list);

    freeList(list);
    return 0;
}

// 2. Write a function to sum the values in the list
int sumNodes(struct node *list) {
    int sum = 0;
    while (list != NULL) {
        sum += list->value;
        list = list->next;
    }
    return sum;
}

// 3. Implement a function to delete the first instance of a value from a list
struct node *deleteFirstInstance(struct node *list, int value) {
    // Deleting 2 Cases
    // 1. Deleting the head
    // 2. Deleting everywhere else

    // Empty List
    if (list == NULL) return NULL;
    struct node *head = list; 

    // 1. Deleting at the head
    if (list->value == value) {
        struct node *del = list;
        list = list->next; 
        free(del);
        return list; 
    }
    struct node *prev = list;
    list = list->next;
    // 2. Deleting everywhere else
    while (list != NULL) {
        if (list->value == value) {
            struct node *del = list;
            prev->next = list->next;
            free(del);
            return head;
        }
        list = list->next;
        prev = prev->next;
    }

    return head; 
}