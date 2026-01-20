#include <iostream>
using namespace std;

// Function to sort array using Selection Sort

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // found a smaller element
            }
        }
        swap(arr[i], arr[minIndex]); 
    }
}

// Function to search element using Interpolation Search

int interpolationSearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    // While target is within the range of arr[left] to arr[right]
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        
        // If all values are equal, just check once
        if (arr[left] == arr[right]) {
            if (arr[left] == target)
                return left;
            else
                break;
        }

        // Estimate the probable position of target
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == target) {
            return pos; // found target
        }
        else if (arr[pos] < target) {
            left = pos + 1; // move to right side
        }
        else {
            right = pos - 1; // move to left side
        }
    }

    return -1; // target not found
}

int main() {
    int arr[6] = {5, 6, 1, 9, 11, 2};
    int n = 6;

    //  Sort array using Selection Sort
    selectionsort(arr, n);

    cout << "Sorted array using Selection Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //  Take input for target element
    int target;
    cout << "Enter target value to search: ";
    cin >> target;

    // Apply Interpolation Search
    int result = interpolationSearch(arr, n, target);

    // Print final result
    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found (returned -1)" << endl;
    }

    return 0;
}
