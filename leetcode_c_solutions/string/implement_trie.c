typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
} TrieNode;

TrieNode* trieCreate() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void trieInsert(TrieNode* obj, char * word) {
    TrieNode* curr = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = trieCreate();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool trieSearch(TrieNode* obj, char * word) {
    TrieNode* curr = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

bool trieStartsWith(TrieNode* obj, char * prefix) {
    TrieNode* curr = obj;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}

void trieFree(TrieNode* obj) {
    if (obj == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        trieFree(obj->children[i]);
    }
    free(obj);
}
