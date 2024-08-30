#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node * deleteAtIndex(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

  
    head->data = 4;
    head->next = second;

 
    second->data = 3;
    second->next = third;

   
    third->data = 8;
    third->next = fourth;


    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    Traversal(head);

   
    head = deleteAtIndex(head,8);
    printf("Linked list after deletion\n");
   Traversal(head);

    return 0;
}