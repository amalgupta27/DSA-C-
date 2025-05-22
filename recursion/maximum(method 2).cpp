#include <iostream>  // Include iostream for input-output operations
#include <climits>   // Include climits for INT_MIN
using namespace std;  

// Function to find the maximum value in an array recursively
// arr[] -> Input array
// n -> Size of the array
// idx -> Current index being checked
int maxInArray(int arr[], int n, int idx) {
    if (idx == n) return INT_MIN; // Base case: When idx reaches n, return INT_MIN

    // Compare current element with the maximum from the remaining array
    return max(arr[idx], maxInArray(arr, n, idx + 1));
}

int main() {
    int arr[] = {2, 1, 6, 31, 9, 0, 220, 100}; // Define an array of integers
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    cout << maxInArray(arr, n, 0); // Call function and print the maximum value

    return 0; // Indicate successful program execution
}

/*
Example Output:
220

Explanation:
- The function recursively traverses the array, comparing elements to find the maximum.
- Once all elements are checked, the largest value is returned and printed.

Example 1:
Input: arr[] = {5, 8, 3, 12, 7}
Output: 12

Example 2:
Input: arr[] = {-1, -5, -3, -10}
Output: -1 (because -1 is the maximum among negative numbers)

Example 3:
Input: arr[] = {100}
Output: 100 (only one element, so it’s the maximum)

*/
