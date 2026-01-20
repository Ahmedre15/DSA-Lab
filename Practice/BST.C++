#include<iostream>
using namespace std;
class Node{
    private:
    int data;
    Node* right;
    Node* left;
    int height;
    public:
    Node(int val){
data=val;
left=right=NULL;
height=1;
    }
    Node* insert(Node* root,int key){
if(root==NULL){
    return new Node(key);
}
if(key<root->data){
    root->left=insert(root->left,key);
}
else if(key>root->data){
    root->right=insert(root->right,key);
}
return root;
    }
    bool search(Node* root,int key){
        if(root==NULL){
    return false;
}
if(key==root->data){
    return true;
}else if(key<root->data){
 return search(root->left,key);
}else{return search(root->right,key);}

}

void Inorder(Node* root){
    if(root=NULL)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Preorder(Node* root){
    if(root=NULL)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node* root){
    if(root=NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int getheight(Node* n){
    if(n==NULL)return 0;
    return n->height;
}
int getbalance(Node* n){
if(n==NULL)return 0;
return getheight(n->left)-getheight(n->right);
}
void rightrotate(Node* y){
Node* x=y->left;
Node* T2=x->right;
x->right=y;
y->left=T2;
   y->height = max(getheight(y->left), getheight(y->right)) + 1;
   x->height = max(getheight(x->left), getheight(x->right)) + 1;
}
};
