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
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("(head)\n");
}

// Generalized insertion function
struct node* insert_node(struct node* head, int data, int position) {
    // Allocate memory for the new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;

    if (head == NULL) {
        // If the list is empty
        new_node->next = new_node; // Point to itself
        return new_node;
    }

    // Handle insertion at the beginning
    if (position == 0) {
        struct node* p = head;
        // Traverse to the last node
        while (p->next != head) {
            p = p->next;
        }
        new_node->next = head;
        p->next = new_node;
        return new_node; // New node is now the head
    }

    // Traverse to the node just before the desired position
    struct node* p = head;
    int i;
    for (i = 0; i < position - 1 && p->next != head; i++) {
        p = p->next;
    }

    // Insert at the end or in the middle
    new_node->next = p->next;
    p->next = new_node;

    return head;
}

// Function to delete a node at a given position
struct node* delete_node(struct node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    // Handle deletion of the head node
    if (position == 0) {
        if (head->next == head) { // Only one node in the list
            free(head);
            return NULL;
        }

        // Find the last node
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        // Update head and the last node's next
        last->next = head->next;
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Traverse to the node just before the position
    int i;
    for (i = 0; i < position && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    /*i is used as a counter to keep track of the current position in the list.
temp starts at head and will be moved through the list.

prev is used to store the node just before temp as temp advances.

The loop continues while i is less than position and temp->next is not pointing back to head.

After the loop, temp points to the node to be deleted, and prev points to the node just before temp.
*/

    if (temp->next == head && i < position) {
        // Position is out of range
        printf("Position out of range.\n");
        return head;
    }

    // Delete the node
    prev->next = temp->next;
    free(temp);

    return head;
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

    // Deletions at various positions
    head = delete_node(head, 0); // Delete head
    printf("The elements after deletion at beginning are:\n");
    circular_traversal(head);

    head = delete_node(head, 2); // Delete at position 2 (middle)
    printf("The elements after deletion at position 2 are:\n");
    circular_traversal(head);

    head = delete_node(head, 100); // Delete at end (position greater than length)
    printf("The elements after deletion at end are:\n");
    circular_traversal(head);

   

    return 0;
}
