typedef struct TrieNode {
    char val;
    int children_count;
    struct TrieNode* children;
} TrieNode;

extern TrieNode createTrieNode();
extern void addToTrie(TrieNode* trie, char* str);
extern void printTrie(TrieNode trie);
