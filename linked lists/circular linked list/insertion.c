#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to traverse and print the circular linked list
void circular_traversal(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* ptr = head;
    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
}

// Generalized insertion function
struct node* insert_node(struct node* head, int data, int position) {
    // Allocate memory for the new node
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    ptr->data = data;

    if (head == NULL) {
        // If the list is empty
        ptr->next = ptr; // Point to itself
        return ptr;
    }

    // Handle insertion at the beginning
    if (position == 0) {
        struct node* p = head;
        // Traverse to the last node
        while (p->next != head) {
            p = p->next;
        }
        ptr->next = head;
        p->next = ptr;
        head=ptr;
        return head; // New node is now the head
    }

    // Traverse to the node just before the desired position
    struct node* p = head;
    int i;
    for (i = 0; i < position - 1 && p->next != head; i++) {
        p = p->next;
    }

    // Insert at the end or in the middle
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Function to free the circular linked list
void free_list(struct node* head) {
    if (head == NULL) return;
    struct node* temp;
    struct node* ptr = head;
    do {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    } while (ptr != head);
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    printf("The elements before insertion are:\n");
    circular_traversal(head);

    // Insertions at various positions
    head = insert_node(head, 55, 0); // Insert at beginning
    printf("The elements after insertion at beginning are:\n");
    circular_traversal(head);

    head = insert_node(head, 77, 2); // Insert at position 2 (middle)
    printf("The elements after insertion at position 2 are:\n");
    circular_traversal(head);

    head = insert_node(head, 99, 100); // Insert at end (position greater than length)
    printf("The elements after insertion at end are:\n");
    circular_traversal(head);

    // Free the allocated memory
    free_list(head);

    return 0;
}
