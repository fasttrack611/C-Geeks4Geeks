int lengthOfLongestSubstring(char * s){
    int n = strlen(s);
    int maxLength = 0;
    int charIndex[128];
    for (int i = 0; i < 128; i++) {
        charIndex[i] = -1;
    }
    int left = 0;
    for (int right = 0; right < n; right++) {
        if (charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        maxLength = fmax(maxLength, right - left + 1);
    }
    return maxLength;
}
