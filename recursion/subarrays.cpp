#include<iostream>  // Include standard input-output stream library
#include<bits/stdc++.h>  // Include all standard libraries (not recommended for good practice)
using namespace std;  // Use the standard namespace

// Recursive function to generate and print all subarrays
void subArray(vector<int> v, int arr[], int n, int idx) { 
    // Do not use & (pass-by-reference) in vector because we need to update it separately in each function call

    // Base case: When idx reaches the array size, print the subarray and return
    if(idx == n) { 
       for(int i = 0; i < v.size(); i++) { // Print the elements of the vector (subarray)
           cout << v[i] << " ";
       }
       cout << endl;  // Print newline for formatting
       return; // End of function call when base case is met
    } 
   
    subArray(v, arr, n, idx + 1); // Recursive case: Exclude current element and move to next index

    // If the vector is empty or last included element follows correct indexing sequence
    // it is for distint elements of given array not dublicate one 
    if(v.size() == 0 || arr[idx - 1] == v.size() - 1) { 
        v.push_back(arr[idx]); // Include the current element (backtracking)
        subArray(v, arr, n, idx + 1); // Recursive case: Include current element and move forward
    }
}

// Main function
int main() {
    int arr[] = {1, 2, 3}; // Define an array of integers
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    vector<int> v; // Initialize an empty vector to store subarrays
    subArray(v, arr, n, 0); // Call recursive function to generate subarrays

    return 0; // Indicate successful program termination
}

/* 
Expected Output:

1 2 3  // Subarray containing all elements
1 2    // Subarray excluding last element
1 3    // Subarray excluding second element
1      // Single element subarray
2 3    // Subarray excluding first element
2      // Single element subarray
3      // Single element subarray

Recursive calls breakdown:

1. Start with an empty vector v = {}
2. Recursive function explores all combinations:
   - {} (Empty subarray)
   - {1}
   - {2}
   - {1, 2}
   - {3}
   - {1, 3}
   - {2, 3}
   - {1, 2, 3}
*/
// Method 2
// for(int i=0; i<n; i++){ 
//   for(int k=i; k<n; k++){
//       for(int j=i; j <= k; j++){
// cout << arr[j];
// }
// cout << endl;
// }
// }