#include <stdio.h>

int main()
{
    int var1 = 50;
    int var2 = 60;

    printf(
        "Values before swap are var1 = %d and var2 = %d\n",
        var1, var2);

    var1 = var1 + var2;
    var2 = var1 - var2;
    var1 = var1 - var2;

    printf("Values after swap are var1 = %d  and var2 = %d",
           var1, var2);

    return 0;
}
