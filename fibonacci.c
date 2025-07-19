#include <stdio.h>

// Recursive Function to print
// Fibonacci Series
void Fibonacci(int num, int first, int second, int third)
{
    if (num > 0) {
        third = first + second;
        first = second;
        second = third;

        printf("%d ", third);

        // Recursive call for it's
        // n-1 value
        Fibonacci(num - 1, first, second, third);
    }
}

// Driver code
int main()
{
    int num;

    printf("Please Enter number of Elements: ");
    scanf("%d", &num);

    printf(
        "Fibonacci Series with the help of Recursion:\n");

    printf("%d %d ", 0, 1);

    // we are passing n-2 because we have
    // already printed 2 numbers i.e, 0 and 1

    Fibonacci(num - 2, 0, 1, 0);

    printf("\nFibonacci Series without Using Recursion:\n");

    int first = 0, second = 1, third = 0;

    printf("%d %d ", 0, 1);

    // Loop will start from 2 because we have
    // already printed 0 and 1
    for (int i = 2; i < num; i++) {
        third = first + second;

        printf("%d ", third);

        first = second;
        second = third;
    }

    return 0;
}
