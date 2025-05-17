//Use of function prototypes
#include <stdio.h>

// Function prototype declared before main
double power(int x, int y);

int main() {
    int x, y, m, n;
    double p, q;

    x = 16; y = 2;
    p = power(x, y);  // p = 16^2 = 256

    m = 16; n = -2;
    q = power(m, n);  // q = 1 / (16^2) = 0.00390625

    printf("\np = %f\nq = %f\n", p, q);

    return 0;
}

// Function definition
double power(int a, int b) {
    double p = 1.0;

    if (b >= 0) {
        while (b--)
            p *= a;
    } else {
        while (b++)
            p /= a;
    }

    return p;
}
