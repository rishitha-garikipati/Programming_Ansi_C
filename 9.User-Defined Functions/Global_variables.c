#include <stdio.h>

// Global variable
int x;

// Function prototypes
int fun1();
int fun2();
int fun3();

int main() {
    x = 10;
    printf("x = %d\n", x);        // 10
    printf("x = %d\n", fun1());   // 20
    printf("x = %d\n", fun2());   // 1 (local x)
    printf("x = %d\n", fun3());   // 30
    return 0;
}

int fun1() {
    x = x + 10;   // modifies global x
    return x;
}

int fun2() {
    int x;        // local x, shadows global
    x = 1;
    return x;     // returns local x
}

int fun3() {
    x = x + 10;   // modifies global x again
    return x;
}
