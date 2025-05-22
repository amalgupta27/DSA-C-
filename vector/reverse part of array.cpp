#include <iostream>  // For input and output operations
#include <vector>    // For using the vector container

using namespace std;

// Function to swap two integer values using reference
void swap(int &x, int &y) {
    int temp = x;  // Store the value of x in a temporary variable
    x = y;         // Assign the value of y to x
    y = temp;      // Assign the value of temp (original x) to y
}

// Function to reverse a part of the vector from index 'start' to 'end'
void reversePart(vector<int> &a, int &start, int &end) {
    // Swap elements from start to end using two-pointer approach
    while (start < end) {
        swap(a[start], a[end]);  // Swap the elements at start and end indices
        start++;  // Move start index forward
        end--;    // Move end index backward
    }
    return; // Return after reversing the specified part
}

// Function to display the elements of the vector
int display(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {  // Loop through each element of the vector
        cout << a[i] << " ";  // Print the element
    }
    cout << endl;  // Print a new line after displaying the array
    return 0; 
}

// Main function - Entry point of the program
int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Initialize a vector with some elements
    int start, end;  // Declare variables to store user input for range

    // Prompt user to enter the start and end indices for reversing
    cout << "Enter start and end indices to reverse: ";
    cin >> start >> end;  // Take input for start and end indices

    // Reverse the specified portion of the vector
    reversePart(arr, start, end);

    // Display the modified vector after reversing
    cout << "Reversed array: ";
    display(arr);

    return 0;  
}
