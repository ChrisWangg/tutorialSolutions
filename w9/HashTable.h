#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

/**
 * @file HashTable.h
 * @brief Header file for the HashTable Abstract Data Type (ADT)
 *
 * This header file provides the interface for a hash table that stores
 * integer key-value pairs. It supports basic operations such as insertion,
 * deletion, search, and retrieval of values based on keys.
 */

/** Forward declaration of the HashTable structure */
typedef struct HashTableRep *HashTable;

/**
 * @brief Creates a new, empty hash table.
 *
 * Allocates memory for a new hash table and initializes its internal structures.
 *
 * @return A new `HashTable` instance.
 *
 * @note Remember to free the hash table using `HashTableFree` when done.
 */
HashTable HashTableNew(void);

/**
 * @brief Frees all memory associated with the hash table.
 *
 * Releases the memory allocated for the hash table and all its elements.
 *
 * @param ht The hash table to free.
 *
 * @pre `ht` must be a valid hash table created by `HashTableNew`.
 */
void HashTableFree(HashTable ht);

/**
 * @brief Inserts or updates a key-value pair in the hash table.
 *
 * If the key already exists in the hash table, its associated value is updated.
 * Otherwise, a new key-value pair is added.
 *
 * @param ht    The hash table into which to insert the key-value pair.
 * @param key   The key to insert.
 * @param value The value to associate with the key.
 *
 * @pre `ht` must be a valid hash table created by `HashTableNew`.
 *
 * @note The hash table allows integer keys and values, including negative numbers.
 */
void HashTableInsert(HashTable ht, int key, int value);

/**
 * @brief Checks if the hash table contains a given key.
 *
 * Searches the hash table for the specified key.
 *
 * @param ht  The hash table to search.
 * @param key The key to look for.
 * @return `true` if the key exists in the hash table, `false` otherwise.
 *
 * @pre `ht` must be a valid hash table created by `HashTableNew`.
 */
bool HashTableContains(HashTable ht, int key);

/**
 * @brief Retrieves the value associated with a given key.
 *
 * Fetches the value corresponding to the specified key in the hash table.
 * If the key does not exist, the function will terminate the program with an error message.
 *
 * @param ht  The hash table from which to retrieve the value.
 * @param key The key whose associated value is to be returned.
 * @return The value associated with the key.
 *
 * @pre `ht` must be a valid hash table created by `HashTableNew`.
 * @pre The key must exist in the hash table (use `HashTableContains` to check).
 *
 * @note It is recommended to check if the key exists using `HashTableContains`
 *       before calling this function to avoid unexpected termination.
 */
int HashTableGet(HashTable ht, int key);

/**
 * @brief Deletes a key-value pair from the hash table.
 *
 * Removes the key and its associated value from the hash table.
 * If the key does not exist, the function does nothing.
 *
 * @param ht  The hash table from which to delete the key-value pair.
 * @param key The key to delete.
 *
 * @pre `ht` must be a valid hash table created by `HashTableNew`.
 */
void HashTableDelete(HashTable ht, int key);

/**
 * @brief Returns the number of key-value pairs in the hash table.
 *
 * @param ht The hash table.
 * @return The number of elements stored in the hash table.
 *
 * @pre `ht` must be a valid hash table created by `HashTableNew`.
 */
int HashTableSize(HashTable ht);

#endif // HASHTABLE_H
