#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    int n;
    printf("Enter Number: \n");
    scanf("%d", &n);

    int var = n;
    int sum = 0;

    int D = countDigits(n);

    while (n > 0) {
        int rem = n % 10;
        sum += pow(rem, D);
        n = n / 10;
    }

    if (var == sum) {
        printf("%d is an Armstrong number \n", var);
    } else {
        printf("%d is not an Armstrong number \n", var);
    }

    return 0;
}
