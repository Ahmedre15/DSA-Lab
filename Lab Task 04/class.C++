#include<iostream>
using namespace std;
class node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class Doubly{
    Node* head;
    Node* tail;
    doubly(){
        head=NULL;
        tail=NULL;

    }
    void insert(int val){
Node* newNode=new Node(val);
  if (Head == NULL) {   
            Head = newNode;
        } else {
            Tail->next = newNode; 
            Tail = newNode;      
        }
    }
};