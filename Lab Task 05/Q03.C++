#include <iostream>
using namespace std;

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // After each pass, biggest element goes to the end
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap if current is bigger than next
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Linear Search function
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // found, return index
        }
    }
    return -1; // not found
}

int main() {
    int arr[6] = {5, 6, 1, 9, 11, 2};
    int n = 6;

    // Sort array using Bubble Sort
    bubbleSort(arr, n);

    cout << "Sorted array using Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Take target input
    int target;
    cout << "Enter target value to search: ";
    cin >> target;

    // Apply Linear Search
    int result = linearSearch(arr, n, target);

    // Show result
    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found (returned -1)" << endl;
    }

    return 0;
}
