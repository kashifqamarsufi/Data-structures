#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
struct node* next;
};

int main(){

struct node* head;
struct node* second;
struct node* third;
// allocate memory for nodes in linked list in heap
head=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));

//link first and second node
head->data=7;
head->next=second;

second->data=11;
second->next=third;

third->data=28;
third->next=NULL;
   
    return 0;
}
