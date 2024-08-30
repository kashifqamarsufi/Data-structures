#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* pre;
};

// Function to traverse and print the doubly linked list
void traverse_list(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Generalized insertion function
struct Node* insert_node(struct Node* head, int data, int position) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->data = data;

    // Handle insertion at the beginning
    if (position == 0) {
        p->next = head;
        p->pre = NULL;
        if (head != NULL) {
            head->pre = p;
        }
        return p; // New node is now the head
    }

    // Handle insertion at the end or middle
    struct Node* q = head;
    int i;
    for (i = 0; q != NULL && i < position - 1; i++) {
        q = q->next;
    }

    if (q == NULL) {
        // Position is out of range (not enough nodes)
        printf("Position out of range.\n");
        free(p);
        return head;
    }

    // Handle insertion at the end
    if (q->next == NULL) {
        q->next = p;
        p->pre = q;
        p->next = NULL;
    } else {
        // Insert in the middle
        p->next = q->next;
        p->pre = q;
        q->next->pre = p;
        q->next = p;
    }

    return head;
}

// Function to free the doubly linked list
void free_list(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Create initial doubly linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->next = second;
    head->pre = NULL;

    second->data = 2;
    second->next = third;
    second->pre = head;

    third->data = 3;
    third->next = NULL;
    third->pre = second;

    printf("Initial list:\n");
    traverse_list(head);

    // Insert at beginning
    head = insert_node(head, 0, 0);
    printf("After insertion at beginning:\n");
    traverse_list(head);

    // Insert at middle
    head = insert_node(head, 5, 2); // Position 2 means insertion after the second node
    printf("After insertion at position 2:\n");
    traverse_list(head);

    // Insert at end
    head = insert_node(head, 6, 100); // Position greater than length of the list
    printf("After insertion at end:\n");
    traverse_list(head);

    // Free the allocated memory
    free_list(head);

    return 0;
}
