#include<iostream>
using namespace std;
int hashtable[10];
void init(){
    for(int i=0;i<10;i++){
        hashtable[i]=-1;
    }
}
int hashfunc(int key){
    return key%10;
}
void insert(int key){
    int index=hashfunc(key); 
    while(hashtable[index]==-1){
    index=(index+1)%10;
    } 
    hashtable[index]=key;
}
bool search(int key){
    int index=hashfunc(key);
    return hashtable[index];
}
int main(){
    init();
    insert(15);
    insert(207);
    cout<<"Found: "<<search(207)<<endl;
    return 0;

}