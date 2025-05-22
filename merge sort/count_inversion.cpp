#include <bits/stdc++.h>  // This includes all standard C++ libraries
using namespace std;      // Allows using standard functions without prefixing "std::"


//brute force
/* int main() {
    // Initialize a vector (dynamic array) with some numbers
    vector<int> v = {5, 1, 3, 0, 4, 9, 6}; 
    
    int n = v.size();  // Get the size of the vector
    int count = 0;     // Variable to count the number of "inversions" (out-of-order pairs)

    // Print the original vector elements one by one
    cout << "Original Vector:" << endl;
    for (int i = 0; i < n; i++) { 
        cout << v[i] << " ";  // Print each element
    }
    cout << endl << endl;  // Print an extra line for better readability

    // Nested loop to check how many pairs (i, j) are out of order (v[i] > v[j])
    for (int i = 0; i < n - 1; i++) {  // Outer loop iterates through each element
        for (int j = i + 1; j < n; j++) {  // Inner loop checks all elements after i
            if (v[i] > v[j]) count++;  // If v[i] is greater than v[j], increment count
        }
    }

    // Print the total count of inversions (out-of-order pairs)
    cout << "Number of inversions: " << count << endl;

    return 0; // Indicate successful program execution
}
    */
