//POINTERS AND TWO-DIMENSIONAL ARRAYS
#include <stdio.h>
#include <string.h>

#define STUDENTS 5
#define SUBJECTS 4

void get_list(char string[][20], int array[][SUBJECTS + 1], int m, int n);
void get_sum(int array[][SUBJECTS + 1], int m, int n);
void get_rank_list(char string[][20], int array[][SUBJECTS + 1], int m, int n);
void print_list(char string[][20], int array[][SUBJECTS + 1], int m, int n);
void swap_int(int *p, int *q);
void swap_string(char s1[], char s2[]);

int main() {
    char name[STUDENTS][20];
    static int marks[STUDENTS][SUBJECTS + 1];

    printf("Input students names & their marks in four subjects\n");
    get_list(name, marks, STUDENTS, SUBJECTS);

    get_sum(marks, STUDENTS, SUBJECTS + 1);
    printf("\n");

    print_list(name, marks, STUDENTS, SUBJECTS + 1);

    get_rank_list(name, marks, STUDENTS, SUBJECTS + 1);

    printf("\nRanked List\n\n");
    print_list(name, marks, STUDENTS, SUBJECTS + 1);

    return 0;
}

void get_list(char string[][20], int array[][SUBJECTS + 1], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        scanf("%s", string[i]);
        for (j = 0; j < SUBJECTS; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}

void get_sum(int array[][SUBJECTS + 1], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        array[i][n - 1] = 0;
        for (j = 0; j < n - 1; j++) {
            array[i][n - 1] += array[i][j];
        }
    }
}

void get_rank_list(char string[][20], int array[][SUBJECTS + 1], int m, int n) {
    int i, j, k;
    for (i = 1; i < m; i++) {
        for (j = 0; j < m - i; j++) {
            if (array[j][n - 1] < array[j + 1][n - 1]) {
                swap_string(string[j], string[j + 1]);
                for (k = 0; k < n; k++) {
                    swap_int(&array[j][k], &array[j + 1][k]);
                }
            }
        }
    }
}

void print_list(char string[][20], int array[][SUBJECTS + 1], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        printf("%-20s", string[i]);
        for (j = 0; j < n; j++) {
            printf("%5d", array[i][j]);
        }
        printf("\n");
    }
}

void swap_int(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void swap_string(char s1[], char s2[]) {
    char temp[20];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}
