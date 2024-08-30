#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* end_insertion(struct node* head, int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
void traversal(struct node* ptr){
    while (ptr!=NULL)
    {
        printf("elements are:\n %d\n",ptr->data);
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

head=end_insertion(head,55);
printf("the linked list after insertion is:\n");
traversal(head);
    return 0;
}