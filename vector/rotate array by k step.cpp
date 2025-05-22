#include <iostream>  
#include <vector>   

using namespace std;

// Function to swap two integer values using reference
void swap(int &x, int &y) {
    int temp = x;  // Store the value of x in a temporary variable
    x = y;         // Assign the value of y to x
    y = temp;      // Assign the value of temp (original x) to y
}

// Function to reverse a portion of the array from index 'start' to 'end'
void reversePart(vector<int> &a, int start, int end) {
    while (start < end) { // Swap elements while start index is less than end index
        swap(a[start], a[end]);  // Swap elements at positions start and end
        start++;  // Move start index forward
        end--;    // Move end index backward
    }
}

// Function to display the elements of the vector
void display(const vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {  // Loop through each element of the vector
        cout << a[i] << " ";  // Print the element
    }
    cout << endl;  // Print a new line after displaying the array
}

int main() {
    vector<int> arr = {1, 6, 2, 3, 7, 4}; // Initialize a vector with given elements
    int k;  // Variable to store number of steps for rotation

    // Prompt user to enter the number of steps to rotate
    cout << "Enter k steps: ";
    cin >> k;

    int n = arr.size();  // Get the size of the array

    // Handle cases where k is greater than the array size
    k = k % n;  // Reduce k to within the array size (rotation beyond size is redundant)

    // Handle negative values of k (though user is expected to enter a non-negative integer)
    if (k < 0) {
        cout << "Invalid value for k. Please enter a non-negative integer." << endl;
        return 0;
    }

    // Perform the three-step reversal process to rotate the array right by k steps:
    reversePart(arr, 0, n - k - 1); // Reverse the first part of the array (0 to n-k-1)
    reversePart(arr, n - k, n - 1); // Reverse the second part of the array (n-k to n-1)
    reversePart(arr, 0, n - 1);     // Reverse the whole array to get the final rotated array

    // Display the rotated array
    cout << "Array after rotating " << k << " steps to the right: ";
    display(arr);

    return 0; 
}
