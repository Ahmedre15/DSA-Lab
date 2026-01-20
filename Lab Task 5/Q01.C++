#include <iostream>
using namespace std;
// Function to check if a subset with the given target sum exists
bool SubSum(int arr[], int n, int target) {
    // Base Cases
    if (target == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than target, ignore it
    if (arr[n - 1] > target)
        return SubSum(arr, n - 1, target);

    // Check two cases: Exclude the current element and Include the current element (reduce target)
    return isSubSum(arr, n - 1, target) ||
           SubSum(arr, n - 1, target - arr[n - 1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    if (SubSum(arr, n, target))
        cout << "True";
    else
        cout << "False";

    return 0;
}
