char * convert(char * s, int numRows){
    if (numRows == 1) {
        return s;
    }

    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int cycleLen = 2 * numRows - 2;
    int k = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            result[k++] = s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) {
                result[k++] = s[j + cycleLen - i];
            }
        }
    }
    result[k] = '\0';
    return result;
}
