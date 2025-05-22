#include<bits/stdc++.h>  // Include all standard libraries (not recommended in production code)
using namespace std;

int main() {
    int arr[] = {5, 3, 1, 4, 2};  // Initialize an array with 5 elements
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    // Print the original array
    for (int ele : arr) {
        cout << ele << " "; 
    }
    cout << endl;

    // Selection Sort Algorithm
    for (int i = 0; i < n - 1; i++) {  // Outer loop for each pass
        int min = INT_MAX;  // Initialize minimum value to a very large number
        int min_idx = -1;  // Initialize index of the minimum element

        // Find the minimum element in the unsorted part of the array
        for (int j = i; j < n; j++) {
            if (arr[j] < min) {  // If a smaller element is found
                min = arr[j];  // Update the minimum value
                min_idx = j;  // Update the index of the minimum value
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[i], arr[min_idx]);
    }

    // Print the sorted array
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;  // Indicate successful execution
}
