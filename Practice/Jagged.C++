#include<iostream>
using namespace std;
int main(){
    int rows;

cout<<"Enter Number of Rows"<<endl;
cin>>rows;
int* cols=new int[rows];
for(int i=0;i<rows;i++){
    cout<<"Enter number of columns for row "<<i+1<<": "<<endl;
    cin>>cols[i];
}
    int** arr=new int*[rows];
    for(int i=0;i<rows;i++){
        arr[i]=new int[cols[i]];
    }  
    cout<<"Enter Values for Jagged Array"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols[i];j++){
            cout<<"Element at ["<<i+1<<"]["<<j+1<<"] : "<<endl;
            cin>>arr[i][j];
        }
    }
    cout<<"Jagged Array: "<<endl;
     for(int i=0;i<rows;i++){
        for(int j=0;j<cols[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
     for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] cols;

    return 0;
}