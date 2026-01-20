#include<iostream>
using namespace std;
class Stack{
    int* arr;
    int size;
    int top;
public:
Stack(int cap){
    size=cap;
    arr=new int[size];
    top=-1;
}
    void push(int data){
    if(top==size-1){
        cout<<"stack overflow"<<endl;
        return;
    }
    arr[++top]=data;
}
int pop(){
    if(top==-1){
          cout<<"stack underflow"<<endl;
        return;
    }
    top=top-1;
    return arr[top];
}
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
class StackN{
public:
Node* top;
int count;
StackN(){
    top=NULL;
    count=0;

}
void push(int val){
Node* temp=new Node(val);
temp->next=top;
top=temp;
count++;
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