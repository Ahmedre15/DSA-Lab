#include<iostream>
#include<vector>
using namespace std;


void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];//key=6
        int j=i-1;//j=0
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int linear(int arr[], int target, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;  
}

int binarySearch(int arr[], int target,int n) {
    int left = 0;
    int right = n-1;

    while (left <= right) {
        
        int mid = left + (right - left) / 2; 

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1; 
}

//Interpolation search is a search algorithm which improves upon binary search by estimating the position of the target 
//element based on its value relative to the values at the boundaries of the search space.Based on Formula:-pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low])

int interpolation(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        int position = left + ((right - left) / (arr[right] - arr[left])) * (target - arr[left]);

        if (arr[position] == target) {
            return position;
        }

        if (arr[position] < target) {
            left = position + 1;
        }

        else {
            right = position - 1;
        }
    }
    
    return -1; 
}
int main(){
    int arr[5]={2,8,3,5,6};
selectionsort(arr,5);
cout<<"Slection Sort:-"<<endl;
 for(int i=0;i<5;i++){
 cout<<arr[i]<<endl;}
  int brr[6]={5,6,1,9,11,2};
insertionsort(brr,6);
 cout<<"Insertion Sort:-"<<endl;
 for(int i=0;i<6;i++){
 cout<<brr[i]<<endl;}
cout<<"Target by Binary Search:"<<binarySearch(arr,5,5)<<endl;
cout<<"Target by Linear Search:"<<linear(brr,9,6)<<endl;
cout<<"Target by Interpolation Search:"<<interpolation(brr,9,6)<<endl;

}


void comsort(int arr[],int n){
    int gap=n;
    bool swapped=true;
    while(gap!=1||swapped){
        gap=gap/1.3;
        if(gap<1){gap=1;}
        swapped=false;
        for(int i=0;i+gap<n;i++){
            if(arr[i]>arr[i+gap]){
                int temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
                swapped=true;
            }
        }
    }
}
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=i;
        j=i-1;
       while(j>=0&&key<arr[j]){
        arr[j+1]=arr[j];
        j--;
       }
       arr[j+1]=key;
    }
}
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
     int key=i;
     int j=i-1;
     while(j>=0 && key<arr[j]){
        j--;
     }
     arr[i+1]=key;
    }
}
void combsort(int arr[],int n){
    int gap=n;
    bool swapped=true;
    while(swapped){
        gap=gap/1.3;
        if(gap<1){gap=1;}
        for(int i=0;gap+i<n;i++){
            swap(arr[i],arr[i+gap]);
            swapped=true;
        }
    }
}