//Use of subscripted members in structures
#include <stdio.h>

struct marks {
    int sub[3];
    int total;
};

int main() {
    int i, j;

    // Initialize student marks and zero total
    struct marks student[3] = {
        {{45, 67, 81}, 0},
        {{75, 53, 69}, 0},
        {{57, 36, 71}, 0}
    };

    struct marks total = { {0, 0, 0}, 0 };

    // Calculate totals
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            student[i].total += student[i].sub[j];     // Student total
            total.sub[j] += student[i].sub[j];         // Subject total
        }
        total.total += student[i].total;                // Grand total
    }

    printf("STUDENT          TOTAL\n\n");
    for (i = 0; i < 3; i++) {
        printf("Student[%d]          %d\n", i + 1, student[i].total);
    }

    printf("\nSUBJECT            TOTAL\n\n");
    for (j = 0; j < 3; j++) {
        printf("Subject-%d          %d\n", j + 1, total.sub[j]);
    }

    printf("\nGrand Total          %d\n", total.total);

    return 0;
}
