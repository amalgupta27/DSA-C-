#include <iostream>  // Include the standard input-output library
using namespace std;

int main() {
    // Define an array with sorted elements
    int arr[] = {1, 2, 3, 4, 4, 5, 6, 7};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Binary search initialization
    int lo = 0;     // Low pointer (starting index)
    int hi = n - 1; // High pointer (ending index)

    // Perform binary search
    while (lo <= hi) {
        // Calculate the middle index to avoid overflow
        int mid = lo + (hi - lo) / 2;

        // If the value at mid matches its position (1-based index), move right
        if (arr[mid] == mid + 1) 
            lo = mid + 1;

        // If the value at mid is equal to its index (0-based index)
        if (arr[mid] == mid) {
            // Check if the previous element is the same (duplicate found)
            if (arr[mid] == arr[mid - 1]) {
                cout << arr[mid]; // Print the duplicate element
                break;            // Exit the loop after finding the duplicate
            } else {
                hi = mid - 1; // Move left if no duplicate is found
            }
        }
    }
}
