#include <iostream>  // Include the input-output library
#include <vector>    // Include the vector library for using dynamic arrays

using namespace std; // Use the standard namespace to avoid writing std:: before cout, vector, etc.

// Function to merge two sorted arrays into a single sorted array
void merge(vector<int>& a, vector<int>& b, vector<int>& res) {
    int i = 0, j = 0, k = 0;  // i = index for array a, j = index for array b, k = index for result array
    int n = a.size(), m = b.size();  // Get sizes of the two arrays
    res.resize(n + m);  // Resize result array to hold all elements

    // Example:
    // a = [1, 3, 5]
    // b = [2, 4, 6]
    // res will be resized to size 6 (3+3)

    // Merge elements of both arrays until one of them is completely processed
    while (i < n && j < m) { 
        if (a[i] < b[j]) {  // If current element of 'a' is smaller, add it to res
            res[k++] = a[i++];
        } else {  // Otherwise, add current element of 'b' to res
            res[k++] = b[j++];
        }
    }

    // If elements are left in array 'a', copy them into 'res'
    while (i < n) {  
        res[k++] = a[i++];
    }

    // If elements are left in array 'b', copy them into 'res'
    while (j < m) {  
        res[k++] = b[j++];
    }
}

// Main function - the starting point of our program
int main() {
    // Declare two sorted arrays
    vector<int> a = {1, 3, 5, 7};  // Sorted array 1
    vector<int> b = {2, 4, 6, 8};  // Sorted array 2
    vector<int> res;  // Empty array where we will store the merged result

    merge(a, b, res);  // Call the merge function

    // Print the merged sorted array
    cout << "Merged Sorted Array: ";
    for (int num : res) {  // Loop through each element in the merged array
        cout << num << " "; // Print each number followed by a space
    }
    cout << endl;  // Move to the next line after printing the array

    return 0;  // Indicate successful program execution
}
