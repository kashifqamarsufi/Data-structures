#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q){
    if (q->r==q->f)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
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

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("queue is empty");
    }
    else{
        q->f++;
        return q->arr[q->f];
    }
}
int main(){
    struct queue q;
    q.size=3;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));

    enqueue(&q,12);
    enqueue(&q,33);
    enqueue(&q,89);

    printf("dequeuing element is %d\n",dequeue(&q));
if (isFull(&q))
{
    printf("queue is full\n");

}
else {
    printf("queue is not full\n");
}
if (isEmpty(&q))
{
    printf("queue is empty\n");

}
else {
    printf("queue is not empty\n");
}

    return 0;
}