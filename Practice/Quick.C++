#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<=j){
        while(i<=high&&arr[i]>=pivot){
    i++;
        }
       while(j>=low&&arr[j]>=pivot){
    j++;
        }  
    }
    if(i>j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    int temp=arr[low];
arr[low]=arr[j];
arr[j]=temp;
return j;//pivot index
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,high,low);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main() {
    int arr[] = {33, 10, 55, 71, 29, 3, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}