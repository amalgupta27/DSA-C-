#include<bits/stdc++.h>  
using namespace std;    

int main() {  
    int arr[] = {2, -3, 4, 4, -7, -1, 4, -2, 6};  // Define the array of integers
    int n = sizeof(arr)/sizeof(arr[0]);  // Calculate the number of elements in the array
    
    // Print the array elements one by one
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  
    }
    cout << endl;  // Print a newline after the array
    
    int k = 4;  // Define the size of the window
    int p = -1;  // Variable to store the index of the first negative element in the window
    int ans[n - k + 1];  // Array to store the result for each window
    
    // Loop through the first 'k' elements to find the first negative element in the first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {  // If we find a negative element
            p = i;  // Store its index in 'p'
            break;  // Exit the loop once we find the first negative element
        }
    }
    
    // If no negative element was found in the first window, assign 1 to the first result
    if (p == -1) 
        ans[0] = 1;  // No negative element in the first window, so assign 1
    else 
        ans[0] = arr[p];  // If a negative element was found, store that element in the result array
    
    int i = 1;  // The starting index of the window, will shift after every iteration
    int j = k;  // The ending index of the window
    
    // Sliding window logic to calculate the first negative number in each window of size 'k'
    while (j < n) {
        if (p >= i) {  // If the first negative number is still in the current window
            ans[i] = arr[p];  // Store that negative number in the result array
        } else {  
            p = -1;  // Reset the 'p' index to -1, since we need to find the first negative number again
            // Loop through the new window to find the first negative number
            for (int x = i; x <= j; x++) {
                if (arr[x] < 0) {  // If we find a negative element
                    p = x;  // Store its index in 'p'
                    break;  // Exit the loop once we find the first negative element
                }
            }
            // If a negative number is found in the current window, store it in the result array
            if (p != -1) 
                ans[i] = arr[p];
            else 
                ans[i] = 1;  // If no negative number is found, store 1 in the result
        }
        i++;  // Shift the start of the window to the next index
        j++;  // Shift the end of the window to the next index
    }
    
    // Print the resultant array that stores the first negative element in each window
    for (int i = 0; i < n - k + 1; i++) 
        cout << ans[i] << " ";  
    
    cout << endl;  // Print a newline after the output to separate the results
    
    return 0;  // Return 0 to indicate the program ended successfully
}
