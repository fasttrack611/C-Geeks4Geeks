#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool is_palindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    const char *word = "abba";

    if (is_palindrome(word)) {
        printf("\"%s\" is a palindrome\n", word);
    } else {
        printf("\"%s\" is not a palindrome\n", word);
    }

    return 0;
}
