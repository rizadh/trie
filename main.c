#include "trie.h"

int main(int argc, char** argv) {
    TrieNode root = createTrieNode();

    for (int i = 1; i < argc; i++) {
        addToTrie(&root, argv[i]);
    }

    printTrie(root);
}
