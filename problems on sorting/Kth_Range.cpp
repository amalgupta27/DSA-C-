#include <iostream>     // For input-output operations
#include <bits/stdc++.h> // Includes all standard libraries (not recommended for portability)
#include <climits>      // For INT_MIN and INT_MAX
using namespace std;

// Custom max function (not needed since std::max exists)
int max(float a, float b) {
    if (a >= b) return a;
    else return b;
}

// Custom min function (not needed since std::min exists)
int min(float a, float b) {
    if (a < b) return a;
    else return b;
}

int main() {
    // Initialize an integer array
    int arr[] = {5, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Print the elements of the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Initialize kmin and kmax to extreme values
    float kmin = (float)(INT_MIN); // Smallest integer value converted to float
    float kmax = (float)(INT_MAX); // Largest integer value converted to float
    bool flag = true; // To check whether a valid range of k exists

    // Iterate through the array elements
    for (int i = 0; i < n - 1; i++) { // Use n-1 to avoid out-of-bounds access
        if (arr[i] >= arr[i + 1]) {
            // Update kmin to the maximum value satisfying the condition
            kmin = max(kmin, (arr[i] + arr[i + 1]) / 2.0);
        } 
        else if (arr[i] < arr[i + 1]) {
            // Update kmax to the minimum value satisfying the condition
            kmax = min(kmax, (arr[i] + arr[i + 1]) / 2.0);
        }  

        // If kmin exceeds kmax, the range is invalid
        if (kmin > kmax) {
            flag = false;
            break; // Exit the loop early as no valid k exists
        }
    }

    // Output the result
    if (!flag) 
    cout << -1; // No valid range found, so output -1.
    
else if (kmin == kmax) { // If kmin and kmax are the same, check further conditions
    if (kmin - (int)kmin == 0) { // If kmin is a whole number (no decimal part)
        cout << "There is only one value of k: " << kmin << endl; // Print the single valid k value
    }
    else 
        cout << -1; // If kmin is not an integer, there is no valid k, so output -1
}

else {
    // If kmin is not a whole number (i.e., it has a decimal part)
    if (kmin - (int)kmin > 0) {  
        kmin = (int)kmin + 1; // Round kmin up to the next integer
    }

    // Print the valid range of k:
    // - kmin is rounded up if necessary
    // - kmax is converted to an integer (truncating the decimal part)
    cout << "Range of k is: " << kmin << " " << (int)kmax;
}


    return 0;
}
