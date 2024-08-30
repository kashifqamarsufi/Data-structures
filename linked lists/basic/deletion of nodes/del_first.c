#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* del_first(struct node* head){
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

void traversal(struct node* ptr){
    while(ptr != NULL){
        printf("The elements are: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    printf("The elements before deletion are:\n");
    traversal(head);

    head = del_first(head);

    printf("The elements after deletion are:\n");
    traversal(head);

    return 0;
}
