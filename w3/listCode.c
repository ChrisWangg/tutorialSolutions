#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node {
    int value;
    struct node *next;
};
// Function Declarations
struct node *selectionSort(struct node *list);
static struct node *listMax(struct node *list);
static struct node *listUnlinkNode(struct node *list, struct node *node);

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
    printList(list);
    list = selectionSort(list);
    printList(list);

    return 0;
}

struct node *selectionSort(struct node *list) {
	struct node *old = list;
	struct node *sorted = NULL; // result
	
	while (old != NULL) {
		// find largest node in old list
		struct node *max = listMax(old);
		
		// unlink largest node in old list
		old = listUnlinkNode(old, max);
		
		// add node to beginning of list
		max->next = sorted;
		sorted = max;
	}
	
	return sorted;
}

// Returns a pointer to the node containing the largest
// element of the given list.
static struct node *listMax(struct node *list) {
	struct node *max = list;
	for (struct node *curr = list; curr != NULL; curr = curr->next) {
		if (curr->value > max->value) {
			max = curr;
		}
	}
	return max;
}

// Removes a given node from a list without freeing it.
static struct node *listUnlinkNode(struct node *list, struct node *node) {
	if (list == node) {
		return list->next;
	} else {
		list->next = listUnlinkNode(list->next, node);
		return list;
	}
}



