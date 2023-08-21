#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> // Include the necessary header for malloc

#define Alphabet_size 26

struct TrieNode {
    struct TrieNode *children[Alphabet_size];
    bool Is_EndofWord;
};

struct TrieNode *CreateNode() {
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (newNode) {
        newNode->Is_EndofWord = false; // Initialize to false
        for (int i = 0; i < Alphabet_size; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

void Insert(struct TrieNode *root, char *key) {
    struct TrieNode *tmp = root;
    for (int j = 0; key[j] != '\0'; j++) {
        int index = key[j] - 'a';
        if (tmp->children[index] == NULL)
            tmp->children[index] = CreateNode();
        tmp = tmp->children[index];
    }
    tmp->Is_EndofWord = true;
}

bool Search(struct TrieNode *root, char *key) {
    struct TrieNode *tmp = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (tmp->children[index] == NULL) {
            return false;
        }
        tmp = tmp->children[index];
    }
    return tmp->Is_EndofWord;
}

int main() {
    struct TrieNode *root = CreateNode();

    // Insert some words into the Trie
    Insert(root, "hello");
    Insert(root, "world");
    Insert(root, "trie");
    Insert(root, "programming");

    // Search for words
    printf("Search 'hello': %s\n", Search(root, "hello") ? "Found" : "Not Found");
    printf("Search 'world': %s\n", Search(root, "world") ? "Found" : "Not Found");
    printf("Search 'trie': %s\n", Search(root, "trie") ? "Found" : "Not Found");
    printf("Search 'programming': %s\n", Search(root, "programming") ? "Found" : "Not Found");
    printf("Search 'data': %s\n", Search(root, "data") ? "Found" : "Not Found");

    return 0;
}
