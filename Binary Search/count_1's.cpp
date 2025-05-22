#include <iostream>  
#include <bits/stdc++.h> // Unnecessary header, can be removed
using namespace std;

int main() {
    // Sorted input array containing only 0s and 1s
    int arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1}; 
    
    // Finding the size of the array
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    int l = 0; // Left pointer (starting index)
    int h = n - 1; // Right pointer (ending index)
    
    int firstIndex = -1; // Variable to store the index of the first occurrence of 1

    // Binary search to find the first occurrence of 1
    while (l <= h) { 
        int mid = l + (h - l) / 2; // Calculating the mid index to avoid overflow  

        if (arr[mid] == 1) { // If the middle element is 1
            if (mid == 0) { // If the mid index is 0, it is the first occurrence
                firstIndex = mid; // Store the index
                break; // Exit the loop
            }
            else if (arr[mid - 1] != 1) { // Check if it's the first occurrence of 1
                firstIndex = mid; // Store the index of first occurrence
                break; // Exit the loop
            }
            else h = mid - 1; // If not the first occurrence, move left
        }
        else if (arr[mid] < 1) { // If the mid element is 0
            l = mid + 1; // Move to the right half to find 1
        } 
        else { // If the mid element is greater than 1 (which won't happen in a 0-1 array)
            h = mid - 1; // Move to the left half
        }
    }

    // If first occurrence of 1 is not found, print 0 (meaning no 1s in the array)
    if (firstIndex == -1) cout << 0;
    else cout << n - firstIndex; // Number of 1s in the array

    return 0; // Return 0 to indicate successful execution of the program
}
