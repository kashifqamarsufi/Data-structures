#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* end_del(struct node* head){
struct node*p=head;
struct node*q=head->next;
while(q->next!=NULL){
p=p->next;
q=q->next;
}
p->next=NULL;
free(q);

    return head;
}


void traversal(struct node* ptr){
    while(ptr!=NULL){
        printf("the elements are : \n %d\n",ptr->data);
        ptr=ptr->next;
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
printf("the elemets after deletinf last index are :");
head=end_del(head);
traversal(head);
return 0;

}
