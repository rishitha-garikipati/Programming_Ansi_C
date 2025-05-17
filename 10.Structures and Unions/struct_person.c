#include <stdio.h>

struct personal {
    char name[20];
    int day;
    char month[10];
    int year;
    float salary;
};

int main() {
    struct personal person;

    printf("Input Name Day Month Year Salary (e.g., John 15 July 1990 25000.50):\n");
    scanf("%19s %d %9s %d %f", person.name, &person.day, person.month, &person.year, &person.salary);

    printf("%s %d %s %d %.2f\n", person.name, person.day, person.month, person.year, person.salary);

    return 0;
}
