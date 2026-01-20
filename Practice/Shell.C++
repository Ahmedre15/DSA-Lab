#include<iostream>
using namespace std;
void shellsort(int arr[],int n){
    
    for(int gap=n/2;gap>0;gap/=2){
for(int i=gap;i<n;i++){
    int temp=arr[i];
    int j;
    for(j=i;j>=gap&&temp<arr[j-gap];j-=gap){
        arr[j]=arr[j-gap];
    }
    arr[j]=temp;
}
    }
}
// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    shellsort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
