#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if (q->r==q->size-1)        
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("the queue is full");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}
int main(){
    struct queue q;
    q.size=4;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));

    enqueue(&q,12);
    enqueue(&q,33);
    enqueue(&q,89);
if (isFull(&q))
{
    printf("queue is full");

}
else {
    printf("queue is not full");
}

    return 0;
}