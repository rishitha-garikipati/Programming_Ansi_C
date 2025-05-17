#include <stdio.h>
#include <stdlib.h>

struct linked_list {
    int number;
    struct linked_list *next;
};
typedef struct linked_list node;

// Function declarations
node *insert_sort(node *list, int x);
void print(node *list);

int main() {
    int n;
    node *head = NULL;

    printf("Input the list of numbers.\n");
    printf("At end, type -999\n");

    scanf("%d", &n);
    while (n != -999) {
        head = insert_sort(head, n);
        scanf("%d", &n);
    }

    printf("\nSorted Linked List:\n");
    print(head);
    printf("NULL\n");

    return 0;
}

// Function to insert a node into a sorted linked list
node *insert_sort(node *list, int x) {
    node *p1 = NULL, *p2 = list, *p;

    // Create new node
    p = (node *)malloc(sizeof(node));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    p->number = x;
    p->next = NULL;

    // Insert at the beginning
    if (list == NULL || x < list->number) {
        p->next = list;
        return p;
    }

    // Find the position to insert
    while (p2 != NULL && p2->number < x) {
        p1 = p2;
        p2 = p2->next;
    }

    // Insert between p1 and p2
    p1->next = p;
    p->next = p2;

    return list;
}

// Function to print the linked list
void print(node *list) {
    while (list != NULL) {
        printf("%d -> ", list->number);
        list = list->next;
    }
}
