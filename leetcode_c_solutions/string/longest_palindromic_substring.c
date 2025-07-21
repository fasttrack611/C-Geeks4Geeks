char * longestPalindrome(char * s){
    int n = strlen(s);
    if (n == 0) {
        return "";
    }
    int start = 0;
    int maxLen = 1;
    bool dp[n][n];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            start = i;
            maxLen = 2;
        }
    }

    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if (dp[i+1][j-1] && s[i] == s[j]) {
                dp[i][j] = true;
                if (k > maxLen) {
                    start = i;
                    maxLen = k;
                }
            }
        }
    }

    char* result = (char*)malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}
