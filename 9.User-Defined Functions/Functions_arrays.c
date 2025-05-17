//Passing of arrays to a function
//FUNCTIONS WITH ARRAYS
#include <stdio.h>
#include <math.h>

#define SIZE 5

// Function prototypes
float std_dev(float a[], int n);
float mean(float a[], int n);

int main() {
    float value[SIZE];
    int i;

    printf("Enter %d float values:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%f", &value[i]);
    }

    printf("Standard Deviation is: %f\n", std_dev(value, SIZE));

    return 0;
}

// Function to compute standard deviation
float std_dev(float a[], int n) {
    float avg = mean(a, n);
    float sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += (a[i] - avg) * (a[i] - avg);
    }

    return sqrt(sum / (float)n);
}

// Function to compute mean
float mean(float a[], int n) {
    float sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum / (float)n;
}

