#include <iostream>
#include <bits/stdc++.h> // Unnecessary header, can be removed
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 3, 4, 8, 9, 12}; // Sorted input array
    int n = sizeof(arr) / sizeof(arr[0]); // Finding the size of the array
    int x; 
    cin >> x; // Taking input for the target value (not used in the logic)

    int l = 0; // Left pointer (starting index)
    int h = n - 1; // Right pointer (ending index)
    int ans = -1; // To store the first index where arr[mid] ≠ mid

    while (l <= h) {  
        int mid = l + (h - l) / 2; // Calculating the mid index to avoid overflow  

        if (arr[mid] == mid) // If the element matches its index, continue searching in the right half
            l = mid + 1;  
        else { 
            ans = mid; // Store the first index where arr[mid] ≠ mid
            h = mid - 1; // Continue searching in the left half for a smaller index with this property
        }
    }
    
    cout << ans << endl; // Output the first index where arr[mid] ≠ mid
}
