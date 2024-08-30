#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* mid_del(struct node* head, int index){
struct node*p=head;
struct node*q=head->next;
for(int i=1;i<index-1;i++){
    p=p->next;
    q=q->next;
}
p->next=q->next;
free(q);
return head;

}


void traversal(struct node* ptr){
    while (ptr!=NULL)
    {
        printf("The elements are: \n %d\n",ptr->data);
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
int idx;
    printf("enter the index in which you want to delete the element: \n");
    scanf("%d",&idx);

    printf("the elements before deleting the %d index is:\n ",idx);
    traversal(head);

    head=mid_del(head,idx);
    printf("the elements after deleting %d index is:\n",idx);
    traversal(head);
    
    return 0;
}