//ACCESSING ADDRESSES OF VARIABLES
#include <stdio.h>

int main() {
    char a; 
    int x;
    float p, q;

    a = 'A';
    x = 125;
    p = 10.25;
    q = 18.76;

    printf("%c is stored at addr %p.\n", a, (void*)&a);
    printf("%d is stored at addr %p.\n", x, (void*)&x);
    printf("%.2f is stored at addr %p.\n", p, (void*)&p);
    printf("%.2f is stored at addr %p.\n", q, (void*)&q);

    return 0;
}

