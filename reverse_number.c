#include <stdio.h>

// Function to reverse digits of an integer
int reverseDigits(int n) {
    int rev = 0;
    while (n != 0) {
        int r = n % 10;
        rev = rev * 10 + r;
        n /= 10;
    }
    return rev;
}

int main() {
    int n;
    printf("Enter number to be reversed: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // non-zero return for error
    }

    int reversed = reverseDigits(n);
    printf("Number after reversing digits is: %d\n", reversed);

    return 0;
}
