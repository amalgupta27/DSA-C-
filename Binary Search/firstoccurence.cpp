#include <iostream>
#include <bits/stdc++.h> // Unnecessary header, can be removed
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 9}; // Sorted input array
    int n = sizeof(arr) / sizeof(arr[0]); // Finding the size of the array
    int x; 
    cin >> x; // Taking input for the target value
    
    int l = 0; // Left pointer (starting index)
    int h = n - 1; // Right pointer (ending index)
    bool flag = false; // Flag to check if the element is found

    while (l <= h) { 
        int mid = l + (h - l) / 2; // Calculating the mid index to avoid overflow  
        
        if (arr[mid] == x) { // If the mid element is equal to x
            if(arr[mid-1] != x){ // Check if it is the first occurrence of x
                cout << "Element found at index " << mid << endl; // Print the index of first occurrence
                flag = true; // Set flag to true since the element is found
                break; // Exit the loop after finding the first occurrence
            }
            if(arr[mid-1] == x) h = mid - 1; // Move left to find the first occurrence
        }
        else if (arr[mid] < x) { // If the mid element is smaller than x
            l = mid + 1; // Move to the right half
        } else { // If the mid element is greater than x
            h = mid - 1; // Move to the left half
        }
    }
}
