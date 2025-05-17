#include <stdio.h>
#include <stdlib.h>

struct linked_list {
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;

// Function prototypes
void create(node *p);
int count(node *p);
void print(node *p);

int main() {
    node *head;

    head = (node *)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    create(head);

    printf("\nLinked List:\n");
    print(head);

    printf("\n\nNumber of items = %d\n", count(head));

    return 0;
}

// Function to create the linked list recursively
void create(node *list) {
    printf("Input a number (type -999 to end): ");
    scanf("%d", &list->number);

    if (list->number == -999) {
        list->next = NULL;
    } else {
        list->next = (node *)malloc(sizeof(node));
        if (list->next == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        create(list->next);
    }
}

// Function to print the linked list
void print(node *list) {
    if (list->next != NULL) {
        printf("%d -> ", list->number);
        if (list->next->next == NULL)
            printf("%d", list->next->number);
        print(list->next);
    }
}

// Function to count the number of items in the linked list
int count(node *list) {
    if (list->next == NULL)
        return 0;
    else
        return (1 + count(list->next));
}
