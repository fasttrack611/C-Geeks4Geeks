char * minWindow(char * s, char * t){
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen < tLen) {
        return "";
    }
    int freq[128] = {0};
    for (int i = 0; i < tLen; i++) {
        freq[t[i]]++;
    }
    int count = tLen;
    int left = 0;
    int minLen = 2147483647;
    int start = 0;
    for (int right = 0; right < sLen; right++) {
        if (freq[s[right]] > 0) {
            count--;
        }
        freq[s[right]]--;
        while (count == 0) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            freq[s[left]]++;
            if (freq[s[left]] > 0) {
                count++;
            }
            left++;
        }
    }
    if (minLen == 2147483647) {
        return "";
    }
    char* result = (char*)malloc(minLen + 1);
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return result;
}
