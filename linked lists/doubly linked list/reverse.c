#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* pre;
    struct Node* next;
};

// Function to traverse and print the doubly linked list
void doubly_Traverse(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to reverse the doubly linked list
struct Node* reverse_list(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;
    struct Node* new_head = NULL;

    // Traverse the list and reverse the pointers
    while (current != NULL) {
        // Swap the next and pre pointers
        temp = current->pre;
        current->pre = current->next;
        current->next = temp;

        // Move to the next node (which was previous)
        new_head = current;
        current = current->pre;
    }

    return new_head;
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

    printf("Original list:\n");
    doubly_Traverse(head);

    // Reverse the list
    head = reverse_list(head);

    printf("Reversed list:\n");
    doubly_Traverse(head);

    // Free the allocated memory
    free(third);
    free(second);
    free(head);

    return 0;
}
