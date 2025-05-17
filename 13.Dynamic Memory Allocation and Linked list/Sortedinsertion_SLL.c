#include <stdio.h>
#include <stdlib.h>

struct linked_list {
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;

// Function declarations
void create(node *list);
void print(node *list);
node *insert(node *head, int x);

int main() {
    int n;
    node *head;

    // Allocate head node
    head = (node *)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Create initial list
    create(head);

    printf("\nOriginal list: ");
    print(head);

    printf("\n\nInput number to be inserted: ");
    scanf("%d", &n);

    head = insert(head, n);

    printf("\nNew list: ");
    print(head);
    printf("\n");

    return 0;
}

// Recursively create a linked list
void create(node *list) {
    printf("Input a number (type -999 to end): ");
    scanf("%d", &list->number);

    if (list->number == -999) {
        list->next = NULL;
        return;
    } else {
        list->next = (node *)malloc(sizeof(node));
        if (list->next == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        create(list->next);
    }
}

// Recursively print the list
void print(node *list) {
    if (list == NULL || list->number == -999)
        return;

    printf("%d", list->number);
    if (list->next != NULL && list->next->number != -999)
        printf(" -> ");
    print(list->next);
}

// Insert in sorted order
node *insert(node *head, int x) {
    node *p1 = NULL, *p2 = head, *p;

    // Create new node
    p = (node *)malloc(sizeof(node));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    p->number = x;
    p->next = NULL;

    // Insert at beginning
    if (x < head->number) {
        p->next = head;
        head = p;
        return head;
    }

    // Traverse to find the correct position
    while (p2 != NULL && p2->number < x) {
        p1 = p2;
        p2 = p2->next;
    }

    // Insert in-between or at end
    p1->next = p;
    p->next = p2;

    return head;
}
