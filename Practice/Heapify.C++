#include<iostream>
using namespace std;
void down(int heap[],int i,int n){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&&heap[left]>heap[largest]){
        largest=left;
    }
     if(right<=n&&heap[right]>heap[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp=heap[i];
        heap[i]=heap[largest];
        heap[largest]=temp;
        down(heap,largest,n);
    }
}
void upward(int heap[],int i){
    if(i>1 && heap[i]>heap[i/2]){
        int temp=heap[i];
        heap[i]=heap[i/2];
        heap[i/2]=temp;
        upward(heap,i/2);
    }
}
void insert(int heap[],int n,int value){
    n++;
    heap[n]=value;
    upward(heap,n);
}
int deleteH(int heap[],int n){
    int maxvalue=heap[1];
    heap[1]=heap[n];
    n--;
    down(heap,1,n);
    return maxvalue;
}
void buildheap(int heap[],int n){
    for(int i=n/2;i>=1;i--){
        down(heap,i,n);
    }
}
void heapsort(int heap[],int n){
 buildheap(heap,n);
 for(int i=n;i>1;i--){
    int temp=heap[1];
    heap[1]=heap[i];
    heap[i]=temp;

    down(heap,1,i-1);
 }
}