#include<iostream>
using namespace std;
class Queue{
    int* arr;
    int size;
    int capacity;
public:
Queue(int cap){
    size=0;
    arr=new int[size];
    capacity=cap;
}
    void enqueue(int data){
    if(capacity==size){
        cout<<"stack overflow"<<endl;
        return;
    }
    arr[size]=data;
    size++;
}
int dequeue(){
    if(size==0){
          cout<<"stack underflow"<<endl;
        return;
    }
for(int i=0;i<size;i++){
arr[i-1]=arr[i];
}
size--;}
};
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class QueueN{
public:
Node* top;
Node* last;
int count;
QueueN(){
    top=NULL;
    count=0;
    last=NULL;

}
void enqueue(int val){
Node* temp=new Node(val);
if(top==NULL){
    top=last=temp;
}
else{last->next=temp;
last=temp;
}count++;
}
int pop(){
if(top==NULL){
    cout<<"Stack Underflow"<<endl;
    return;
}
Node* temp=top;
top=top->next;
int val=temp->data;
delete temp;
return val;
}
};