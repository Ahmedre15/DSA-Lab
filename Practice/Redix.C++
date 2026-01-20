#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
data=val;
next=NULL;
    }
};
void addnewnode(Node* head,int val){
    head=nullptr;
    Node* newnode=new Node(val);
    
    if(head==NULL){
        head=newnode;
    }
    Node* temp=head; 
    while(temp->next!=NULL){
        temp=temp->next;
    }   
    temp->next=newnode;

}
void deletenode(Node* head){
    Node* temp;
    while(head!=NULL){
    head=temp;
    head=head->next;
    delete temp;
    }
}
int max(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            arr[i]=max;
            return max;
        }
    }
}

void redixsort(int arr[],int n){
    int maxnum=max(arr,n);
    int exp=1;//number of current position 1=ones,10=tens etc
    Node* buckets[10];
    while(maxnum/exp>0){
    for(int i=0;i<n;i++ ){
        buckets[i]=NULL;
    }
    for (int i=0;i<n;i++){
        int digit=(arr[i]/exp)%10;
    addnewnode(buckets[digit],arr[i]);
    }
    int idx=0;
for(int i=0;i<n;i++){
    Node* temp=buckets[i];

    while(temp->next!=NULL){
arr[idx++]=temp->data;
temp=temp->next;
        }
    deletenode(buckets[i]); 
}
   exp*=10; }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    redixsort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}


