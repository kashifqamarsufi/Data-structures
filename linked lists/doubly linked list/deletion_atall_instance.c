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

// Function to delete all nodes with the specified value
struct Node* delete_node(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp;
    
    // Delete nodes with matching value at the beginning
    while (head != NULL && head->data == value) {
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->pre = NULL;
        }
        free(temp);
    }

    // Now head is the new head of the list after deletions
    struct Node* q = NULL;

    // Traverse the list and delete nodes with matching value
    while (head != NULL) {
        if (head->data == value) {
            // Node to delete is found
            temp = head;
            q->next = head->next;
            if (head->next != NULL) {
                head->next->pre = q;
            }
            head = head->next;
            free(temp);
        } else {
            // Move to the next node
            q = head;
            head = head->next;
        }
    }

    return head;
}

int main() {
    // Create initial doubly linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    head->pre = NULL;

    second->data = 2;
    second->next = third;
    second->pre = head;

    third->data = 3;
    third->next = fourth;
    third->pre = second;

    fourth->data = 2; // Node with value to be deleted
    fourth->next = fifth;
    fourth->pre = third;

    fifth->data = 2; // Node with value to be deleted
    fifth->next = NULL;
    fifth->pre = fourth;

    printf("Initial list:\n");
    doubly_Traverse(head);

    int value_to_delete;
    printf("Enter value to delete: ");
    scanf("%d", &value_to_delete);

    head = delete_node(head, 2);

    printf("List after deletion:\n");
    doubly_Traverse(head);



    return 0;
}
