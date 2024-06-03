#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};
// Function Declarations
int listLength(struct node *l);
int listCountOdds(struct node *l);
bool listIsSorted(struct node *l);
struct node *listDelete(struct node *l, int value);

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
    list = prependNode(1, list);
    list = prependNode(2, list);
    list = prependNode(3, list);
    printf("The list length is %d\n", listLength(list));
    printf("The number of odds is %d\n", listCountOdds(list));
    printList(list);
    // 0 is false   1 is true
    printf("Boolean is list sorted: %d\n", listIsSorted(list));

    struct node *sortedList = NULL;
    sortedList = prependNode(3, sortedList);
    sortedList = prependNode(2, sortedList);
    sortedList = prependNode(1, sortedList);

    printf("Boolean is sortedList sorted: %d\n", listIsSorted(sortedList));

    list = listDelete(list, 3);
    printList(list);

    return 0;
}

// 1. Write a recursive function to compute the length of a linked list
int listLength(struct node *l) {
    if (l == NULL) {
        return 0;
    }
    return 1 + listLength(l->next);
}

// 2. Write a recursive function to count the number of odd numbers in a linked
// list
int listCountOdds(struct node *l) {
    if (l == NULL) {
        return 0;
    }
    else if (l->value % 2 == 1) {
        return 1 + listCountOdds(l->next);
    }
    else {
        return listCountOdds(l->next);
    }
}
// 3. Write a recursive function to check if a list is sorted in ascending order
bool listIsSorted(struct node *l) {
    if (l == NULL || l->next == NULL) {
        return true;
    }
    else if (l->next->value > l->value) {
        return listIsSorted(l->next);
    }
    else {
        return false;
    }
}
// 4. Write a recursive function to delete the first instance from a value from
// a linked list
struct node *listDelete(struct node *l, int value) {
    if (l == NULL) {
        return NULL;
    }
    else if (value == l->value) {
        struct node *del = l;
        l = l->next;
        free(del);
        l = listDelete(l, value);
    }
    else {
        l->next = listDelete(l->next, value);
    }
    return l;
}