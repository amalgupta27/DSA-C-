#include <iostream>  // Include the iostream library for input and output operations
#include <bits/stdc++.h> // Include all standard C++ libraries (not necessary for this program)
using namespace std;  
// Function to recursively print the elements of an array
// arr[] -> Array to be printed
// n -> Size of the array
// idx -> Current index in the array
void display(int arr[], int n, int idx) {
    if (idx == n) return; // Base case: If index reaches array size, stop recursion
    cout << arr[idx] << " "; // Print the current element
    display(arr, n, idx + 1); // Recursive call to print the next element
}
int main() {
    int arr[] = {2, 1, 6, 3, 9, 0, 2, 7}; // Define an array of integers
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    display(arr, n, 0); // Call the function to print the array starting from index 0
    return 0; // Indicate successful program execution
}

/*
Example Output:
2 1 6 3 9 0 2 7 

Explanation:
- The function starts printing from the first index and recursively calls itself to print the next elements until the end of the array.
*/
