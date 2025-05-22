#include<iostream>  // Standard input-output stream library
#include<vector>    // Vector library (not used in this code)
#include<bits/stdc++.h> // Includes all standard libraries (not necessary here)

using namespace std;  

int main() {
   // Initializing an array with 6 elements
   int arr[6] = {5, 4, 1, 2, 3, 8};
   int n = 6;  // Size of the array

   // Printing the original array before sorting
   cout << "Original array: ";
   for(int i = 0; i < n; i++) {
     cout << arr[i] << " ";
   }

   // Optimized Bubble Sort Algorithm
   for(int i = 0; i < n - 1; i++) {  // Outer loop runs for (n-1) passes
      bool flag = true; // Flag to track whether any swaps occur

      for(int j = 0; j < n - 1 - i; j++) {  // Inner loop runs for (n-1-i) comparisons in each pass
         if(arr[j] > arr[j + 1]) {  // Swap if the current element is greater than the next element
            swap(arr[j], arr[j + 1]);  // Swapping adjacent elements
            flag = false;  // Swap occurred, so the array is not fully sorted yet
         }
      }

      // If no swaps occurred in the inner loop, the array is already sorted
      if(flag == true) {
         break;
      }
   }

   // Printing the sorted array
   cout << "\nSorted array: ";
   for(int i = 0; i < n; i++) {
     cout << arr[i] << " ";
   }

   return 0;  // Returning 0 to indicate successful execution
}
