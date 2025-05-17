//Computing area under a curve
#include <stdio.h>

// Function prototypes
void input(void);
float find_area(float a, float b, int n);
float trap_area(float h1, float h2, float base);
float function_x(float x);

// Global variables for user input
float start_point, end_point;
int numtraps;

int main() {
    float total_area;

    printf("AREA UNDER A CURVE\n");

    // Get input values from the user
    input();

    // Calculate the area using the trapezoidal rule
    total_area = find_area(start_point, end_point, numtraps);

    // Display the result
    printf("TOTAL AREA = %f\n", total_area);

    return 0;
}

// Function to take input from the user
void input(void) {
    printf("Enter lower limit: ");
    scanf("%f", &start_point);

    printf("Enter upper limit: ");
    scanf("%f", &end_point);

    printf("Enter number of trapezoids: ");
    scanf("%d", &numtraps);
}

// Function to calculate area under the curve using trapezoidal rule
float find_area(float a, float b, int n) {
    float base, lower, h1, h2, area = 0.0;

    base = (b - a) / n;

    for (lower = a; lower < b; lower += base) {
        h1 = function_x(lower);
        h2 = function_x(lower + base);
        area += trap_area(h1, h2, base);
    }

    return area;
}

// Function to calculate area of a single trapezoid
float trap_area(float height_1, float height_2, float base) {
    return 0.5 * (height_1 + height_2) * base;
}

// Function to define f(x) = x^2 + 1
float function_x(float x) {
    return (x * x + 1);
}
