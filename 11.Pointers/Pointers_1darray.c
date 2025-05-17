//POINTERS IN ONE-DIMENSIONAL ARRAY
#include <stdio.h>

int main()
{
    int *p, sum, i;
    static int x[5] = {5, 9, 6, 3, 7};
    i = 0;
    p = x;
    sum = 0;

    printf("Element\tValue\tAddress\n\n");
    while (i < 5)
    {
        printf("x[%d]\t%d\t%p\n", i, *p, (void*)p);
        sum = sum + *p;
        i++;
        p++;
    }

    printf("\nSum = %d\n", sum);
    printf("\n&x[0] = %p\n", (void*)&x[0]);
    printf("p = %p\n", (void*)p);

    return 0;
}
