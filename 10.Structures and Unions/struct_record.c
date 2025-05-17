#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For atoi()

struct record {
    char author[20];
    char title[30];
    float price;
    struct {
        char month[10];
        int year;
    } date;
    char publisher[10];
    int quantity;
};

// Function prototypes
int look_up(struct record table[], char s1[], char s2[], int m);
void get_string(char string[]);

int main() {
    char title[30], author[20];
    int index, no_of_records;
    char response[10], quantity_str[10];

    static struct record book[] = {
        {"Ritche", "C Language", 45.00, {"May", 1977}, "PHI", 10},
        {"Kochan", "Programming in C", 75.50, {"July", 1983}, "Hayden", 5},
        {"Balagurusamy", "BASIC", 30.00, {"January", 1984}, "TMH", 0},
        {"Balagurusamy", "COBOL", 60.00, {"December", 1988}, "Macmillan", 25}
    };

    no_of_records = sizeof(book) / sizeof(struct record);

    do {
        printf("Enter title and author name as per the list\n");

        printf("Title: ");
        get_string(title);

        printf("Author: ");
        get_string(author);

        index = look_up(book, title, author, no_of_records);

        if (index != -1) {
            printf("\n%s %s %.2f %s %d %s\n\n",
                   book[index].author,
                   book[index].title,
                   book[index].price,
                   book[index].date.month,
                   book[index].date.year,
                   book[index].publisher);

            printf("Enter number of copies: ");
            get_string(quantity_str);

            int qty = atoi(quantity_str);
            if (qty <= book[index].quantity && qty > 0) {
                printf("Cost of %d copies = %.2f\n\n", qty, book[index].price * qty);
            } else {
                printf("\nRequired copies not in stock or invalid quantity\n\n");
            }
        } else {
            printf("\nBook not in list\n\n");
        }

        printf("Do you want any other book? (YES/NO): ");
        get_string(response);

    } while (response[0] == 'Y' || response[0] == 'y');

    printf("\n\nThank you. Good bye!\n");

    return 0;
}

void get_string(char string[]) {
    char c;
    int i = 0;
    do {
        c = getchar();
        if (c != '\n' && c != EOF) {
            string[i++] = c;
        }
    } while (c != '\n' && c != EOF && i < 29);
    string[i] = '\0';  // Null terminate the string
}

int look_up(struct record table[], char s1[], char s2[], int m) {
    for (int i = 0; i < m; i++) {
        if (strcmp(s1, table[i].title) == 0 && strcmp(s2, table[i].author) == 0) {
            return i; // book found
        }
    }
    return -1; // book not found
}
