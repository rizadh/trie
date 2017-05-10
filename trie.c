#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define INDENT 2

TrieNode createTrieNode() {
    TrieNode newNode;
    newNode.val = '\0';
    newNode.children_count = 0;
    newNode.children = NULL;

    return newNode;
}

void addToTrie(TrieNode* trie, char* str) {
    TrieNode* currentNode = trie;
    char currentChar;

    while ((currentChar = *(str++)) != '\0') {
        char childChar = '\0';
        int i = 0;
        while (i < currentNode->children_count && currentChar != childChar) {
            childChar = currentNode->children[i].val;
            i++;
        }

        if (currentChar != childChar) {
            TrieNode newNode = createTrieNode();
            newNode.val = currentChar;

            currentNode->children = realloc(currentNode->children, sizeof(TrieNode) * (i + 1));

            currentNode->children[i] = newNode;
            currentNode->children_count = i + 1;
            currentNode = currentNode->children + i;
        } else {
            currentNode = currentNode->children + i - 1;
        }
    }
}

void _printTrie(TrieNode trie, int indent) {
    for (int i = 0; i < indent; i++)
        printf(" ");

    printf("%c\n", trie.val);

    for (int i = 0; i < trie.children_count; i++)
        _printTrie(trie.children[i], indent + INDENT);
}

void printTrie(TrieNode trie) {
    _printTrie(trie, 0);
}
