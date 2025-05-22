#include <bits/stdc++.h> // Unnecessary, <iostream> & <algorithm> are enough
#include <iostream>
#include <algorithm> // For sort function

using namespace std;

int main() {
    int arr[] = {5, 1, 5, 5, 2, 3}; // Given array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    
    sort(arr, arr + n); // Sort the array in ascending order

    // Storing the sorted array into an integer 'x' (first minimum)
    int x = 0;
    for (int i = 0; i < n; i++) {
        x *= 10;    // Shift left to make space for the next digit
        x += arr[i]; // Append the next digit
    }
    cout << x << endl; // Print the first minimum integer

    // Finding the second minimum number by swapping the rightmost unequal adjacent digits
    for (int i = n - 1; i >= 1; i--) {
        if (arr[i] != arr[i - 1]) { // Find the first distinct pair from the right
            swap(arr[i], arr[i - 1]); // Swap them
            break; // Stop after one swap
        }
    }

    // Convert modified array into an integer 'y' (second minimum)
    int y = 0;
    for (int i = 0; i < n; i++) { // Iterate from left to right (not reverse)
        y *= 10;    // Shift left
        y += arr[i]; // Append digit
    }
    
    cout << y << endl; // Print the second minimum integer
    cout << "Minimum sum is " << (x + y) << endl; // Print the sum with correct spacing
    
    return 0;
}
