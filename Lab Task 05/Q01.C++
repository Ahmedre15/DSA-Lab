#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];   // pick the current element
        int j = i - 1;      // check elements before it

        // shift elements bigger than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // place key in the correct position
        arr[j + 1] = key;
    }
}

// Function to perform Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    // keep checking until left crosses right
    while (left <= right) {
        int mid = left + (right - left) / 2; // middle index

        if (arr[mid] == target) {
            return mid;  // found target, return index
        } else if (arr[mid] < target) {
            left = mid + 1;  // search right half
        } else {
            right = mid - 1; // search left half
        }
    }

    return -1; // target not found
}

int main() {
    int brr[6] = {5, 6, 1, 9, 11, 2};

    // Step 1: Sort the array
    insertionsort(brr, 6);

    cout << "Sorted array using Insertion Sort:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << brr[i] << " ";
    }
    cout << endl;

    // Step 2: Ask user for a target value
    int target;
    cout << "Enter target value to search: ";
    cin >> target;

    // Step 3: Use Binary Search
    int result = binarySearch(brr, 6, target);

    // Step 4: Print result
    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found (returned -1)" << endl;
    }

    return 0;
}
