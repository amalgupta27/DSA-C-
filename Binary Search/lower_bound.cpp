#include <iostream>
#include <bits/stdc++.h> // Unnecessary header, can be removed
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5, 9, 15, 18, 21, 24}; // Sorted input array
    int n = sizeof(arr) / sizeof(arr[0]); // Finding the size of the array
    int x; 
    cin >> x; // Taking input for the target value
    
    int l = 0; // Left pointer
    int h = n - 1; // Right pointer
    bool flag = false; // Flag to check if element is found

    while (l <= h) {
        int mid = l + (h - l) / 2; // Calculating mid index

        if (arr[mid] == x) { // If x is found in the array
            flag = true;
            cout << arr[mid-1] << endl; // Print the previous value
            break;
        } 
        else if (arr[mid] < x) { // If mid element is smaller than x, search in the right half
            l = mid + 1;
        } 
        else { // If mid element is greater than x, search in the left half
            h = mid - 1;
        }
    }

    if (!flag) { // If x is not found, print the lower bound
        cout << arr[h] << endl; //i.e h=mid-1;
        //for upper bound cout<<arr[l]; i.e l=mid+1
    }
}
  