#include <stdio.h>

int main()
{
    int n, rev = 0;

    printf("Enter Number to be reversed : ");
    scanf("%d", &n);

    int r = 0;
      while (n != 0)
    {
        r = n % 10;
        rev = rev * 10 + r;
        n /= 10;
    }

    printf("Number After reversing digits is: %d", rev);

    return 0;
}
