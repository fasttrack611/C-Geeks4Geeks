#include <stdio.h>
#include <stdlib.h>

// Reverses the digits of a signed integer
int reverse_digits(int number) {
    int reversed = 0;
    int sign = number < 0 ? -1 : 1;
    number = abs(number);  // Handle negative input safely

    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    return sign * reversed;
}

int main(void) {
    int input;
    printf("Enter an integer to reverse: ");

    if (scanf("%d", &input) != 1) {
        fprintf(stderr, "❌ Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    int result = reverse_digits(input);
    printf("✅ Reversed number: %d\n", result);

    return 0;
}
