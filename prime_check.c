#include <math.h>
#include <stdio.h>

// Driver code
int main()
{
    int num;
    int check = 1;

    printf("Enter a number: \n");
    scanf("%d", &num);

    // Iterating from 2 to sqrt(num)
    for (int i = 2; i <= sqrt(num); i++) {
        // If the given number is divisible by
        // any number between 2 and n/2 then
        // the given number is not a prime number
        if (num % i == 0) {
            check = 0;
            break;
        }
    }

    if (num <= 1) {
        check = 0;
    }

    if (check == 1) {
        printf("%d is a prime number", num);
    }
    else {
        printf("%d is not a prime number", num);
    }

    return 0;
}
