#include <iostream>  
#include <bits/stdc++.h> // Unnecessary header, can be removed
using namespace std;

int main() {
    // 2D sorted binary matrix containing only 0s and 1s
    int arr[5][6] = { {0, 0, 0, 0, 1, 1}, 
                      {0, 0, 1, 1, 1, 1}, 
                      {0, 1, 1, 1, 1, 1}, 
                      {0, 0, 0, 0, 0, 1}, 
                      {0, 0, 0, 1, 1, 1} };

    int m = 5; // Number of rows
    int n = 6; // Number of columns

    int row = 0;      // Variable to store the row index with the maximum number of 1s
    int maxOnes = 0;  // Variable to store the maximum count of 1s found in any row

    // Iterate over each row of the matrix
    for (int i = 0; i < m; i++) {  
        int count = 0; // Variable to store the count of 1s in the current row
        int l = 0;     // Left pointer (starting index)
        int h = n - 1; // Right pointer (ending index)

        int firstIndex = -1; // Variable to store the index of the first occurrence of 1 in the row

        // Binary search to find the first occurrence of 1 in the current row
        while (l <= h) { 
            int mid = l + (h - l) / 2; // Calculate mid index to avoid overflow  

            if (arr[i][mid] == 1) { // If the middle element is 1
                if (mid == 0) { // If mid index is 0, it's the first occurrence
                    firstIndex = mid; // Store the index
                    break; // Exit the loop
                }
                else if (arr[i][mid - 1] != 1) { // Check if it's the first occurrence of 1
                    firstIndex = mid; // Store the index of the first occurrence
                    break; // Exit the loop
                }
                else h = mid - 1; // If not the first occurrence, move left
            }
            else if (arr[i][mid] < 1) { // If the mid element is 0
                l = mid + 1; // Move to the right half to find 1
            } 
            else { // If the mid element is greater than 1 (which won't happen in a 0-1 array)
                h = mid - 1; // Move to the left half
            }
        }

        // If first occurrence of 1 is not found, the row has no 1s
        if (firstIndex == -1) count = 0;
        else count = n - firstIndex; // Calculate the number of 1s in the row

        // Update maxOnes and row index if the current row has more 1s than the previous maximum
        if (maxOnes < count) {
            maxOnes = count; // Update max number of 1s
            row = i;         // Store the row index
        }
    }

    // Print the row index with the maximum number of 1s
    cout << "Row index with maximum number of 1s: " << row << endl;  
    cout << "Maximum number of 1s: " << maxOnes << endl;  

    return 0; // Return 0 to indicate successful execution of the program
}
