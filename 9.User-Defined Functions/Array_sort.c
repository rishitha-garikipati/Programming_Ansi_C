//Sorting of array elements using a function
//SORTING OF ARRAY ELEMENTS
#include <stdio.h>

// Function prototype
void sort(int m, int x[]);

int main() {
    int i;
    static int marks[5] = {40, 90, 73, 81, 35};

    printf("Marks before sorting:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", marks[i]);
    }

    sort(5, marks);  // Call the sort function

    printf("\n\nMarks after sorting:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", marks[i]);
    }

    printf("\n");

    return 0;
}

// Function to sort the array in ascending order
void sort(int m, int x[]) {
    int i, j, t;
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (x[j] > x[j + 1]) {
                t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
    }
}

