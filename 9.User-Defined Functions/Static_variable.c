#include <stdio.h>

// Function prototype
void stat(); 

int main() {
    int i;
    for(i = 1; i <= 3; i++) {
        stat();  // calling stat() three times
    }
    return 0;
}

// Function with a static variable
void stat() {
    static int x = 0;  // retains value between calls
    x = x + 1;
    printf("x = %d\n", x);
}
