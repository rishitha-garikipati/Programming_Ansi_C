#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct linked_list {
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;

// Function prototypes
node *insert(node *head);
node *find(node *p, int key);

// Main function to demonstrate insertion
int main() {
    node *head = (node *)malloc(sizeof(node));
    if (!head) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Creating a sample list: 10 -> 20 -> 30
    head->number = 10;
    head->next = (node *)malloc(sizeof(node));
    head->next->number = 20;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->number = 30;
    head->next->next->next = NULL;

    // Insertion
    head = insert(head);

    // Print updated list
    printf("\nUpdated List:\n");
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->number);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

// Insert a new node after a given key
node *insert(node *head) {
    int key, x;
    node *new_node, *n1;

    printf("Value of new item? ");
    scanf("%d", &x);
    printf("Value of key item? (type -999 if inserting at beginning): ");
    scanf("%d", &key);

    if (key == -999 || head->number == key) {
        // Insert at beginning
        new_node = (node *)malloc(sizeof(node));
        new_node->number = x;
        new_node->next = head;
        head = new_node;
    } else {
        // Insert after the node containing key
        n1 = find(head, key);
        if (n1 == NULL) {
            printf("Key not found.\n");
        } else {
            new_node = (node *)malloc(sizeof(node));
            new_node->number = x;
            new_node->next = n1->next;
            n1->next = new_node;
        }
    }
    return head;
}

// Find the node containing the key
node *find(node *list, int key) {
    while (list != NULL && list->next != NULL) {
        if (list->number == key)
            return list;
        list = list->next;
    }
    return NULL;
}
