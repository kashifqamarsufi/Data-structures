#include<stdio.h>

int binary_search(int arr[],int size,int element){
    int low=0,mid,high=size-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){   // ie element is on right side
            low=mid+1;
        }
        else
        high=mid-1;      // i.e element is on left side
    }
    return -1;
}

int main(){
int arr[]={22,45,47,56,59,67,77,89,94,104,200};
int size=sizeof(arr)/sizeof(arr[0]);
int element =89;

int binarysearch=binary_search(arr,size,element);

printf("the index is %d",binarysearch);

    return 0;
}