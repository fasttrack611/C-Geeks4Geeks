#include <stdio.h>
#include <string.h>

// In-place compression of char array using run-length encoding
int compress(char *chars, int charsSize) {
    int write = 0;  // Index to write compressed characters
    int read = 0;   // Index to read characters

    while (read < charsSize) {
        char current = chars[read];
        int count = 0;

        // Count consecutive occurrences
        while (read < charsSize && chars[read] == current) {
            read++;
            count++;
        }

        // Write the character
        chars[write++] = current;

        // Write the count as individual digits (if > 1)
        if (count > 1) {
            // Convert integer count to string representation
            char buffer[12];  // Enough for max 32-bit int
            int len = sprintf(buffer, "%d", count);
            for (int i = 0; i < len; i++) {
                chars[write++] = buffer[i];
            }
        }
    }

    return write;  // Final length of compressed array
}

int main(void) {
    // Sample input: character array with duplicates
    char chars[] = {'a','a','b','b','c','c','c'};
    int charsSize = sizeof(chars) / sizeof(chars[0]);

    printf("Original array: ");
    for (int i = 0; i < charsSize; i++) {
        printf("%c ", chars[i]);
    }
    printf("\n");

    // Compress in-place and get new length
    int compressedSize = compress(chars, charsSize);

    printf("Compressed array: ");
    for (int i = 0; i < compressedSize; i++) {
        printf("%c ", chars[i]);
    }
    printf("\nNew length after compression: %d\n", compressedSize);

    return 0;
}
