#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insert_at_mid(struct node*head,int data,int index){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;// for not losing our head value 
    int i=0;
    while (i!=index-1){
p=p->next;
i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr; 
    return head;
}

void traversal(struct node*ptr){
    while(ptr!=NULL){
        printf("Elements are : \n %d\n",ptr->data);
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

head=insert_at_mid(head,55,2);
printf("the linked list after insertion is:\n");
traversal(head);
    return 0;
}