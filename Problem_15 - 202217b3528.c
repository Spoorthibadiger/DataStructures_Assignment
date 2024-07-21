#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct ListNode {
    char* key;
    char* value;
    struct ListNode* next;
};

// Function to set node values
void initializeNode(struct ListNode* node, char* key, char* value) {
    node->key = key;
    node->value = value;
    node->next = NULL;
}

// Hash map structure
struct HashTable {
    int size;
    int capacity;
    struct ListNode** buckets;
};

// Function to initialize the hash table
void createHashTable(struct HashTable* table) {
    table->capacity = 100;
    table->size = 0;
    table->buckets = (struct ListNode*)malloc(sizeof(struct ListNode) * table->capacity);
    for (int i = 0; i < table->capacity; i++) {
        table->buckets[i] = NULL;
    }
}

// Hash function to generate index for a key
int getHashIndex(struct HashTable* table, char* key) {
    int hash = 0;
    int prime = 31;
    for (int i = 0; i < strlen(key); i++) {
        hash = (hash * prime + key[i]) % table->capacity;
    }
    return hash;
}

// Function to insert key-value pair into the hash table
void addEntry(struct HashTable* table, char* key, char* value) {
    int index = getHashIndex(table, key);
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    initializeNode(newNode, key, value);

    if (table->buckets[index] == NULL) {
        table->buckets[index] = newNode;
    } else {
        newNode->next = table->buckets[index];
        table->buckets[index] = newNode;
    }
}

// Function to delete a key from the hash table
void removeEntry(struct HashTable* table, char* key) {
    int index = getHashIndex(table, key);
    struct ListNode* current = table->buckets[index];
    struct ListNode* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous == NULL) {
                table->buckets[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

// Function to search for a value by key in the hash table
char* findValue(struct HashTable* table, char* key) {
    int index = getHashIndex(table, key);
    struct ListNode* current = table->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return "Oops! No data found.\n";
}

// Driver code
int main() {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
    createHashTable(table);

    addEntry(table, "Yogaholic", "Anjali");
    addEntry(table, "pluto14", "Vartika");
    addEntry(table, "elite_Programmer", "Manish");
    addEntry(table, "GFG", "BITS");
    addEntry(table, "decentBoy", "Mayank");

    printf("%s\n", findValue(table, "elite_Programmer"));
    printf("%s\n", findValue(table, "Yogaholic"));
    printf("%s\n", findValue(table, "pluto14"));
    printf("%s\n", findValue(table, "decentBoy"));
    printf("%s\n", findValue(table, "GFG"));
    printf("%s\n", findValue(table, "randomKey"));

    printf("\nAfter deletion:\n");
    removeEntry(table, "decentBoy");
    printf("%s\n", findValue(table, "decentBoy"));

    return 0;
}