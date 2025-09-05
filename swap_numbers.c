#include <stdio.h>

int main()
{
    int var1 = 50;
    int var2 = 60;

    // Display values before swapping
    printf("Values before swap are var1 = %d and var2 = %d\n", var1, var2);

    // Swapping logic using arithmetic operations
    var1 = var1 + var2;  // var1 = 50 + 60 = 110
    var2 = var1 - var2;  // var2 = 110 - 60 = 50 (original var1)
    var1 = var1 - var2;  // var1 = 110 - 50 = 60 (original var2)

    // Display values after swapping
    printf("Values after swap are var1 = %d and var2 = %d\n", var1, var2);

    return 0;
}
