#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void linkedlist_traversal(struct node* ptr){
    printf("printing the elements of linked list");
    while(ptr!=NULL){
        printf("elements : %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node *f,*r;
void enqueue(int val){
    struct node* n=(struct node*)malloc(sizeof(struct node));
if(n==NULL){
    printf("Queue is full");
}
else{
n->data=val;
n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
}
}
int dequeue(){
    int val=-1;
    struct node*ptr=f;
    if(f==NULL){
        printf("queue is empty");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

int main(){

linkedlist_traversal(f);
printf("dequeuing element %d\n",dequeue());
enqueue(3);
enqueue(23);
enqueue(35);
enqueue(38);
linkedlist_traversal(f);
printf("dequeuing element %d\n",dequeue());

    return 0;
}