#include <bits/stdc++.h>  // Includes all standard C++ libraries
#include <iostream>        // (Redundant, since <bits/stdc++.h> already includes it)
using namespace std;

int main() {
    int arr[] = {5, 2, 7, 4, 8, 3, 1};  // Initialize an array with unsorted elements
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    // Print the original array
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    // Insertion Sort Algorithm
    for (int i = 1; i <= n - 1; i++) {  // Start from the second element (index 1)
        int j = i;  // Store the index of the current element

        // Move the current element to its correct position in the sorted part
        while (j >= 1) {
            if (arr[j] >= arr[j - 1]) break;  // If the order is correct, stop shifting
            
            if (arr[j] < arr[j - 1]) {  // If the previous element is greater,//or directly write else , swap
                swap(arr[j], arr[j - 1]);
            }
            j--;  // Move to the previous element
        }
    }

    // Print the sorted array
    for (int ele : arr) {
        cout << ele << " ";
    }
}
