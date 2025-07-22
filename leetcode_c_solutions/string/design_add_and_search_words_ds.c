typedef struct WordDictionary {
    struct WordDictionary* children[26];
    bool isEndOfWord;
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
    WordDictionary* node = (WordDictionary*)malloc(sizeof(WordDictionary));
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    WordDictionary* curr = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = wordDictionaryCreate();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    // ... implementation ...
    return false;
}

void wordDictionaryFree(WordDictionary* obj) {
    if (obj == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        wordDictionaryFree(obj->children[i]);
    }
    free(obj);
}
