//ACCESSING VARIABLES USING POINTERS
#include <stdio.h>

int main() {
    int x, y;
    int *ptr;

    x = 10;
    ptr = &x;    // ptr points to x
    y = *ptr;    // y gets value of x through pointer

    printf("Value of x is %d\n\n", x);

    printf("%d is stored at addr %p\n", x, (void*)&x);
    printf("%d is stored at addr %p\n", *&x, (void*)&x); // *&x is x itself
    printf("%d is stored at addr %p\n", *ptr, (void*)ptr); // value at ptr, address stored in ptr
    printf("%d is stored at addr %p\n", y, (void*)&*ptr);  // address of what ptr points to
    printf("%p is stored at addr %p\n", (void*)ptr, (void*)&ptr); // value of ptr and its own address
    printf("%d is stored at addr %p\n", y, (void*)&y);

    *ptr = 25;  // change x via pointer
    printf("\nNow x = %d\n", x);

    return 0;
}

