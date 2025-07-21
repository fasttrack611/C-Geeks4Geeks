int compress(char* chars, int charsSize){
    int index = 0;
    int i = 0;
    while (i < charsSize) {
        char c = chars[i];
        int count = 0;
        while (i < charsSize && chars[i] == c) {
            i++;
            count++;
        }
        chars[index++] = c;
        if (count > 1) {
            char s[10];
            sprintf(s, "%d", count);
            for (int j = 0; j < strlen(s); j++) {
                chars[index++] = s[j];
            }
        }
    }
    return index;
}
