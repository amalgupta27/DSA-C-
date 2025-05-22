#include<iostream>  // Include the input-output stream library for input and output operations
using namespace std;  // Use the standard namespace to avoid needing to prefix std::

int main() {  // Main function, entry point of the program
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13};  // Initialize the array with integers from 1 to 13
    int n = sizeof(arr)/sizeof(arr[0]);  // Calculate the number of elements in the array (total size of the array divided by size of one element)
    bool flag = false;  // Initialize a flag variable to false. This will help track whether a partition is found.
    int idx = -1;  // Initialize an index variable for the partition point. It is set to -1 initially, meaning no partition is found yet.

    // Create a prefix sum array
    for(int i = 1; i < n; i++) {  // Start from the second element (index 1) since the first element is already itself a prefix sum
        arr[i] = arr[i] + arr[i-1];  // Update each element to store the sum of itself and all previous elements (prefix sum)
    }

    // Check if there's a partition such that the sum of the left part equals the sum of the right part
    for(int i = 1; i < n; i++) {  // Iterate through the array to find the partition point
        if(arr[i] == arr[n-1] - arr[i]) {  // Check if the prefix sum at index 'i' equals the total sum minus the prefix sum at index 'i'
            idx = i;  // If a partition is found, store the index in 'idx' and break out of the loop
            break;  // Exit the loop as we found a valid partition point
        }
    }

    // Output the result based on whether a partition was found or not
    if(idx != -1)  // If idx is not -1, it means a partition was found
        cout << "Yes, it can be partitioned at index " << idx << endl;  // Output the index of the partition
    else  // If no partition was found (idx is still -1)
        cout << "No, it cannot be partitioned" << endl;  // Output "No it cannot be partitioned"

    return 0;  // Return 0 to indicate successful program termination
}
