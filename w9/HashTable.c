#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

#define INITIAL_TABLE_SIZE 101  // Initial capacity of the hash table

// Node structure for the linked list in each hash table bucket
struct ListNode {
    int key;
    int value;
    struct ListNode *next;
};

// HashTable representation
struct HashTableRep {
    int size;                    // Number of elements in the hash table
    int capacity;                // Size of the hash table array
    struct ListNode **lists;     // Array of pointers to linked lists (buckets)
};

// Hash function to compute index
static int hashFunction(int key, int capacity) {
    int index = key % capacity;
    if (index < 0) index += capacity;  // Ensure index is non-negative
    return index;
}

// Create a new hash table
HashTable HashTableNew(void) {
    HashTable ht = malloc(sizeof(struct HashTableRep));
    if (ht == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    ht->size = 0;
    ht->capacity = INITIAL_TABLE_SIZE;
    ht->lists = malloc(ht->capacity * sizeof(struct ListNode *));
    if (ht->lists == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ht->capacity; i++) {
        ht->lists[i] = NULL;
    }
    return ht;
}

// Free the hash table
void HashTableFree(HashTable ht) {
    if (ht == NULL) return;
    for (int i = 0; i < ht->capacity; i++) {
        struct ListNode *node = ht->lists[i];
        while (node != NULL) {
            struct ListNode *tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(ht->lists);
    free(ht);
}

// Insert or update a key-value pair
void HashTableInsert(HashTable ht, int key, int value) {
    if (ht == NULL) return;
    int index = hashFunction(key, ht->capacity);

    struct ListNode *node = ht->lists[index];
    while (node != NULL) {
        if (node->key == key) {
            // Key already exists, update the value
            node->value = value;
            return;
        }
        node = node->next;
    }
    // Key not found, insert new node at the beginning
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->lists[index];
    ht->lists[index] = newNode;
    ht->size++;
}

// Check if the key exists in the hash table
bool HashTableContains(HashTable ht, int key) {
    if (ht == NULL) return false;
    int index = hashFunction(key, ht->capacity);

    struct ListNode *node = ht->lists[index];
    while (node != NULL) {
        if (node->key == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

// Get the value associated with a key
int HashTableGet(HashTable ht, int key) {
    if (ht == NULL) {
        fprintf(stderr, "Error: HashTable is NULL\n");
        exit(EXIT_FAILURE);
    }
    int index = hashFunction(key, ht->capacity);

    struct ListNode *node = ht->lists[index];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    fprintf(stderr, "Error: Key %d not found in HashTable\n", key);
    exit(EXIT_FAILURE);
}

// Delete a key-value pair from the hash table
void HashTableDelete(HashTable ht, int key) {
    if (ht == NULL) return;
    int index = hashFunction(key, ht->capacity);

    struct ListNode *node = ht->lists[index];
    struct ListNode *prev = NULL;
    while (node != NULL) {
        if (node->key == key) {
            // Key found, delete node
            if (prev == NULL) {
                ht->lists[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            ht->size--;
            return;
        }
        prev = node;
        node = node->next;
    }
    // Key not found, do nothing
}

// Get the number of elements in the hash table
int HashTableSize(HashTable ht) {
    if (ht == NULL) return 0;
    return ht->size;
}
