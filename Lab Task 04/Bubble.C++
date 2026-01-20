#include<iostream>
using namespace std;

int main(){
    int arr[5]={3,2,5,1,6};
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}