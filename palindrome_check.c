#include <stdio.h>
#include <string.h>

void Palindrome(char s[])
{
    int start = 0;
    int end = strlen(s) - 1;

    while (end > start) {
        if (s[start++] != s[end--]) {
            printf("%s is not a Palindrome \n", s);
            return;
        }
    }
    printf("%s is a Palindrome \n", s);
}

int main()
{
    Palindrome("abba");
    return 0;
}
