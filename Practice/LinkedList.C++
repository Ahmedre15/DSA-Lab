#include<iostream>
using namespace std;
class Node{
 int data;
 Node* next;
 Node* prev;
 public:
 Node(int val){
    data=val;
    next=NULL;
    prev=NULL;
 }
};
class LinkedList{
    public:
    Node* head;
    Node* tail;
    LinkedList(){
        head=NULL;
        tail=NULL;
    }

    void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

    void insertathead(int val){
   Node *temp=new Node(val);
if(head==NULL){
    head=tail=temp;
}
else{
    temp->next=head;
    head->prev=temp;
    head=temp;
}
    }

void insertattail(int val){
    Node* temp=new Node(val);
   if(tail==NULL){
    head=tail=temp;
 }
  else{
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
  }
    }
void insertatpos(int val,int pos){
    if(pos==1){
        insertathead(val);
    }
    Node* temp=head;
    int count=1;
    while(temp=!NULL && count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        cout<<"Position does not exist"<<endl;
        return;
    }
    Node* newNode=new Node(val);
    
    if(temp->next==NULL){
        temp->next=newNode;
        newNode->prev=temp;
tail=newNode;
    }
    else{
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;}
}
void deletenode(int pos){
    Node* temp=head;
int count=1;
    while(count<pos){
        temp=temp->next;
        count++;
    }
    temp->next=temp->next->next;
    temp->next->next->prev=temp;
    delte temp->next;
}
};
