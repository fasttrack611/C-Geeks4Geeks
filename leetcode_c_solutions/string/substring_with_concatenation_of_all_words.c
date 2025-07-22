/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    *returnSize = 0;
    if (wordsSize == 0) {
        return NULL;
    }
    int wordLen = strlen(words[0]);
    int sLen = strlen(s);
    int windowSize = wordLen * wordsSize;
    int* result = (int*)malloc(sizeof(int) * sLen);

    // Create a hash map for words
    // ... implementation ...

    return result;
}
