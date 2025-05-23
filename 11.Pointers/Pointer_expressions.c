//ILLUSTRATION OF POINTER EXPRESSIONS
#include <stdio.h>

int main() {
    int a, b, *p1, *p2, x, y, z;
    a = 12;
    b = 4;
    p1 = &a;
    p2 = &b;

    x = *p1 * *p2 - 6;
    y = 4 * - *p2 / *p1 + 10;

    printf("Address of a = %p\n", (void*)p1);
    printf("Address of b = %p\n", (void*)p2);
    printf("\n");

    printf("a = %d, b = %d\n", a, b);
    printf("x = %d, y = %d\n", x, y);

    *p2 = *p2 + 3;
    *p1 = *p2 = 5;

    z = *p1 * *p2 - 6;
    printf("\na = %d, b = %d, z = %d\n", a, b, z);

    return 0;
}
