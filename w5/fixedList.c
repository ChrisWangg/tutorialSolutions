#include <stdio.h>
#include <stdlib.h>

// Function declarations
struct node *appendList(struct node *a, int data);
struct node *createNode(int data);
void printList(struct node *node);
void freeList(struct node *head);

struct node {
	int data;
	struct node *next;
};

int main() {
	struct node *head = NULL;
	head = appendList(head, 1);
	head = appendList(head, 2);
	head = appendList(head, 3);
	head = appendList(head, 4);
	printList(head);
	freeList(head);
	return 0;
}

/*
	Appending a node to the end of a linked list
*/
struct node *appendList(struct node *a, int data) {
	struct node *newNode = createNode(data);
	if (a == NULL) {
		a = newNode;
	} else {
		struct node *lastNode = a;
		while (lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
	return a;
}

/*
	Helper to create a linked list node
*/
struct node *createNode(int data) {
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;

}
/*
	Prints a list out to stdout
*/
void printList(struct node *node) {
	while (node->next != NULL) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("%d\n", node->data);
}
/*
	Free's the memory associated to a linked list
*/
void freeList(struct node *head) {
	if (head == NULL) {
		return;
	}
	struct node *temp = head;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}





