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

// Generalized delete function
struct Node* delete_node(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp;

    // Handle deletion at the beginning
    if (position == 0) {
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->pre = NULL;
        }
        free(temp);
        return head;
    }

    struct Node* p = head;
    int i;

    // Traverse to the node just before the desired position
    for (i = 0; p != NULL && i < position - 1; i++) {
        p = p->next;
    }

    if (p == NULL || p->next == NULL) {
        // Position is out of range
        printf("Position out of range.\n");
        return head;
    }

    temp = p->next;
    p->next = temp->next;
    if (temp->next != NULL) {
        temp->next->pre = p;
    }
    free(temp);

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

    fourth->data = 26;
    fourth->next = fifth;
    fourth->pre = third;

     fifth->data = 90;
    fifth->next = NULL;
    fifth->pre = fourth;

    printf("Initial list:\n");
    doubly_Traverse(head);
delete_node(head,0);

    printf("deleted list:\n");
    doubly_Traverse(head);
    return 0;
}

