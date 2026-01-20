#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int v){
        value=v;
        next=NULL;
    }
};
class Single{
    public:
    Node* head;
    Node* tail;
    Single(){
        head=NULL;
        tail=NULL;
    }
    void first(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void Last(int val){
        Node* newNode=new Node(val);
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=tail;
    }
    void middle(int pos,int val){
        Node* newNode=new Node(val);
        Node* cur;
        Node* pre;
        cur=head;
        for(int i=0;i<pos;i++){
            pre=cur;
            cur->next;
        }
        pre->next =newNode;
        newNode->next=cur;

    }
    void delHead(){
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    void delTail(){
        Node* temp=head;
         while (temp->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
     temp->next = NULL;
    }
 
};
int main() {
Single list;
    list.first(3);
    list.first(2);
    list.first(1);
    list.Last(4);
    list.middle(2, 5);

    return 0;
}