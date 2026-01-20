#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* table[10];
int hashfunc(int key){
    return key%10;
}
void insert(int key){
    int index=hashfunc(key);
    Node* newnode=new Node;
    newnode->data=key;
    newnode->next=table[index];
    table[index]=newnode;
}
