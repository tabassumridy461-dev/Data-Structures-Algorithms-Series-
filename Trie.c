// ============================================
// File: 24_Trie.c
// Topic: Trie (Prefix Tree)
// Concepts:
// 1. Insert Word
// 2. Search Word
// 3. Prefix Matching (startsWith)
// ============================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26   // a-z

// ------------------------------
// Trie Node
// ------------------------------
struct TrieNode {

    struct TrieNode *children[SIZE];
    int isEndOfWord;

};

// ------------------------------
// Create a new Trie Node
// ------------------------------
struct TrieNode* createNode() {

    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));

    node->isEndOfWord = 0;

    // Initialize all children as NULL
    for (int i = 0; i < SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

// ------------------------------
// Insert a word into Trie
// ------------------------------
void insert(struct TrieNode *root, char word[]) {

    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {

        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }

        current = current->children[index];
    }

    // Mark end of word
    current->isEndOfWord = 1;
}

// ------------------------------
// Search a complete word
// Returns 1 if found
// Returns 0 if not found
// ------------------------------
int search(struct TrieNode *root, char word[]) {

    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {

        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            return 0;
        }

        current = current->children[index];
    }

    return current->isEndOfWord;
}

// ------------------------------
// Check Prefix
// Returns 1 if prefix exists
// Returns 0 otherwise
// ------------------------------
int startsWith(struct TrieNode *root, char prefix[]) {

    struct TrieNode *current = root;

    for (int i = 0; prefix[i] != '\0'; i++) {

        int index = prefix[i] - 'a';

        if (current->children[index] == NULL) {
            return 0;
        }

        current = current->children[index];
    }

    return 1;
}

// ------------------------------
// Main Function
// ------------------------------
int main() {

    struct TrieNode *root = createNode();

    // Insert words
    insert(root, "cat");
    insert(root, "car");
    insert(root, "cart");
    insert(root, "dog");

    // Search words
    printf("Search 'cat'  : %s\n",
           search(root, "cat") ? "Found" : "Not Found");

    printf("Search 'cow'  : %s\n",
           search(root, "cow") ? "Found" : "Not Found");

    // Prefix Matching
    printf("Prefix 'ca'   : %s\n",
           startsWith(root, "ca") ? "Exists" : "Not Exists");

    printf("Prefix 'do'   : %s\n",
           startsWith(root, "do") ? "Exists" : "Not Exists");

    printf("Prefix 'ap'   : %s\n",
           startsWith(root, "ap") ? "Exists" : "Not Exists");

    return 0;
}
