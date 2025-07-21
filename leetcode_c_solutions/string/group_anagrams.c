/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (strsSize == 0) {
        return NULL;
    }
    char*** result = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    int* visited = (int*)calloc(strsSize, sizeof(int));

    for (int i = 0; i < strsSize; i++) {
        if (visited[i]) {
            continue;
        }
        result[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
        (*returnColumnSizes)[*returnSize] = 0;
        result[*returnSize][(*returnColumnSizes)[*returnSize]] = strs[i];
        (*returnColumnSizes)[*returnSize]++;
        visited[i] = 1;

        for (int j = i + 1; j < strsSize; j++) {
            if (isAnagram(strs[i], strs[j])) {
                result[*returnSize][(*returnColumnSizes)[*returnSize]] = strs[j];
                (*returnColumnSizes)[*returnSize]++;
                visited[j] = 1;
            }
        }
        (*returnSize)++;
    }
    return result;
}

bool isAnagram(char * s, char * t){
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen != tLen) {
        return false;
    }
    int count[26] = {0};
    for (int i = 0; i < sLen; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}
