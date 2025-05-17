//Illustration of return of float values
//POWER FUNCTIONS
#include <stdio.h>
// Function prototype
double power(int x, int y);

int main() {
    int x, y;

    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);

    printf("%d to the power of %d is %f\n", x, y, power(x, y));

    return 0;
}

// Function to compute x to the power of y
double power(int x, int y) {
    double p = 1.0;

    if (y >= 0) {
        for (int i = 0; i < y; i++) {
            p *= x;
        }
    } else {
        for (int i = 0; i < -y; i++) {
            p /= x;
        }
    }

    return p;
}


