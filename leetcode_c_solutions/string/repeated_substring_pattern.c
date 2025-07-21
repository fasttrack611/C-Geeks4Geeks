bool repeatedSubstringPattern(char * s){
    int n = strlen(s);
    for (int i = n / 2; i >= 1; i--) {
        if (n % i == 0) {
            int repeats = n / i;
            char* sub = (char*)malloc(i + 1);
            strncpy(sub, s, i);
            sub[i] = '\0';
            char* temp = (char*)malloc(n + 1);
            temp[0] = '\0';
            for (int j = 0; j < repeats; j++) {
                strcat(temp, sub);
            }
            if (strcmp(temp, s) == 0) {
                free(sub);
                free(temp);
                return true;
            }
            free(sub);
            free(temp);
        }
    }
    return false;
}
