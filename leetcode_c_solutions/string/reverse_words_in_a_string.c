void reverse(char* s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

char * reverseWords(char * s){
    int len = strlen(s);
    reverse(s, 0, len - 1);

    int storeIndex = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != ' ') {
            if (storeIndex != 0) {
                s[storeIndex++] = ' ';
            }
            int j = i;
            while (j < len && s[j] != ' ') {
                s[storeIndex++] = s[j++];
            }
            reverse(s, storeIndex - (j - i), storeIndex - 1);
            i = j;
        }
    }
    s[storeIndex] = '\0';
    return s;
}
