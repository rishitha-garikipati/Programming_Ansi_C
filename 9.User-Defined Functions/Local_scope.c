#include <stdio.h>

// Function prototypes
void function1();
void function2();

int main() {
    int m = 1000;
    function2();
    printf("%d\n", m);
    return 0;
}

void function1() {
    int m = 10;
    printf("%d\n", m);
}

void function2() {
    int m = 100;
    function1();
    printf("%d\n", m);
}

