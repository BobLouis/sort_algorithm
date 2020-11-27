#include <stdio.h>
#include <stdlib.h>

#define N (sizeof(a)/sizeof(a[0]))
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int split(int a[],int low,int high,int pivot){
    pivot=a[pivot];
    while(low<high){
        while(a[low]<pivot&&low<high){
            low++;
        }
        while(a[high]>pivot&&low<high){
            high--;
        }
        if(a[high]<a[low]){
            swap(&a[high],&a[low]);
        }
    }
    return low;
}
void sort(int a[] ,int low,int high){
    int pivot,index;
    if(low>=high){
        return;
    }
    pivot=(low+high)/2;
    index=split(a,low,high,pivot);
    sort(a,low,index-1);
    sort(a,index+1,high);
}


int main() {
    int a[] = {3, 1, 5, 4, 2, 9, 8, 7, 6,44,33,35,32,11,23,15};
    int index, pivot;
    sort(a, 0, N - 1);
    for(int i=0;i<N;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
