#include <stdio.h>
#include <string.h>

// Function to find the length of the last word in a string
int lengthOfLastWord(char *s) {
    int len = 0;
    int i = strlen(s) - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters until the next space or start of string
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }

    return len;
}

int main() {
    char s[1000];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove trailing newline from fgets
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }

    int result = lengthOfLastWord(s);
    printf("Length of the last word: %d\n", result);

    return 0;
}
