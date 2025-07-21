int strStr(char * haystack, char * needle){
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    if (needleLen == 0) {
        return 0;
    }
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        if (strncmp(haystack + i, needle, needleLen) == 0) {
            return i;
        }
    }
    return -1;
}
