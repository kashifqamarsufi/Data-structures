#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* afterNode(struct node*head,struct node*prevNode,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}
void traversal(struct node* ptr){
while(ptr!=NULL){
    printf("the elements are : \n %d\n",ptr->data);
    ptr=ptr->next;
}
}

int main(){
struct node* head;
struct node* second;
struct node* third;

head=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));

head->data=7;
head->next=second;

second->data=11;
second->next=third;

third->data=25;
third->next=NULL;

printf("the linked list befor insertion is:\n");
traversal(head);

head=afterNode(head,second,55);
printf("the linked list after insertion is:\n");
traversal(head);
    return 0;
}