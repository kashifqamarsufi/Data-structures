#include<stdio.h>

int index_insertion(int arr[],int size,int element,int capacity,int index){
if(size>capacity){
    return -1;
}
else
    for(int i=size-1;i>=index;i--){
arr[i+1]=arr[i];
    }
arr[index]=element;
return 1;
}
int main(){

int arr[100]={7,8,12,27,88};
int size=5;
int element=45;
int index=3;

int index_insert=index_insertion(arr,size,element,100,index);
size++;
for(int i=0;i<size;i++){
    printf("%d\t",arr[i]);
}
    return 0;
}