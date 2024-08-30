#include<stdio.h>

int linear_search(int arr[],int size,int element){

    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[]={1,35,12,11,98,16,20};
int size=sizeof(arr)/sizeof(arr[0]);
int element=12;
int search_index=linear_search(arr,size,element);
printf("the index is %d",search_index);
    return 0;
}