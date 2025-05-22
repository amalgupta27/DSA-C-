// #include<bits/stdc++.h> 
// using namespace std;     

// int main() {  // Main function where the program execution begins
//     int arr[]={7,1,2,5,8,4,9,3,6};  // Initialize an array of integers
//     int n = sizeof(arr)/sizeof(arr[0]);  // Calculate the number of elements in the array
//     int k = 3;  // Define the number of consecutive elements to sum (k consecutive elements)
//     int maxSum = INT_MIN;  // Initialize the maximum sum to the smallest possible integer value
//     int maxIdx = -1;  // Initialize the index of the subarray with the maximum sum to -1

//     for(int i = 0; i <= n - k; i++) {  // Loop through the array to find the sum of every 'k' consecutive elements
//         int sum = 0;  // Initialize the sum variable for the current subarray
//         for(int j = i; j < i + k; j++) {  // Loop to calculate the sum of k consecutive elements starting from index i
//             sum += arr[j];  // Add the current element to the sum
//         }

//         if(sum > maxSum) {  // If the current sum is greater than the maximum sum found so far
//             maxSum = sum;  // Update the maximum sum to the current sum
//             maxIdx = i;  // Update the index where the maximum sum starts
//         }
//     }

//     cout << "Maximum sum of " << k << " consecutive elements is " << maxSum << endl;  // Output the maximum sum
//     cout << "Starting index is " << maxIdx << endl;  // Output the starting index of the subarray with the maximum sum

//     return 0;  // Return 0 to indicate the program ended successfully
// }

//SLIDING WINDOW USED HERE
#include<bits/stdc++.h>  // Include all standard C++ libraries at once
using namespace std;     // Use the standard namespace to avoid writing 'std::' before every function

int main() {  // The starting point of the program
    int arr[]={7,1,2,5,8,4,9,3,6};  // Initialize an array of integers
    // Example: arr = [7, 1, 2, 5, 8, 4, 9, 3, 6]
    
    int n = sizeof(arr)/sizeof(arr[0]);  // Calculate the number of elements in the array
    // Example: n = 9, because the array has 9 elements

    int k = 3;  // Define the size of the window (number of consecutive elements to sum)
    // Example: k = 3, meaning we are summing 3 consecutive elements at a time
    
    int maxSum = INT_MIN;  // Set the maximum sum to the smallest possible integer value initially
    // Example: maxSum starts as a very small number
    
    int maxIdx = -1;  // Initialize the index where the maximum sum starts
    // Example: maxIdx starts as -1, meaning we haven't found the maximum sum yet
    
    int prevSum = 0;  // To store the sum of the first 'k' elements (window sum)
    // Example: we will calculate the sum of the first 3 elements
    
    for(int i = 0; i < k; i++){  // Calculate the sum of the first 'k' elements in the array
        prevSum += arr[i];  // Add the elements one by one to form the sum of the first 'k' elements
    }
    // Example: prevSum = 7 + 1 + 2 = 10 (sum of first 3 elements)
    
    maxSum = prevSum;  // Now set maxSum to be equal to the sum of the first 'k' elements
    // Example: maxSum = 10 (initial max sum is the sum of the first 3 elements)
    
    int i = 1;  // The starting index of the window will shift after every iteration
    int j = k;  // 'j' will point to the next element to be added into the window

    while(j < n) {  // Continue as long as the end of the window doesn't go beyond the array
        int currSum = prevSum + arr[j] - arr[i-1];  // Calculate the new sum by sliding the window
        // Example: 
        // prevSum = 10 (from previous window),
        // arr[j] = 8 (next element to add),
        // arr[i-1] = 7 (element to remove),
        // currSum = 10 + 8 - 7 = 11
        
        if(currSum > maxSum) {  // Check if the current sum is greater than the max sum found so far
            maxSum = currSum;  // Update the maxSum if the current sum is larger
            maxIdx = i;  // Update the starting index of the new subarray
        }
        // Example: if currSum = 11 is greater than maxSum = 10, maxSum will be updated to 11 and maxIdx will be updated to i.
        
        prevSum = currSum;  // Update prevSum to the current sum for the next iteration
        i++;  // Shift the start of the window to the next index
        j++;  // Shift the end of the window to the next index
    }

    cout << "Maximum sum of " << k << " consecutive elements is " << maxSum << endl;  // Output the maximum sum
    // Example: Output: Maximum sum of 3 consecutive elements is 18
    
    cout << "Starting index is " << maxIdx << endl;  // Output the starting index of the subarray with the maximum sum
    // Example: Output: Starting index is 4
    
    return 0;  // Return 0 to indicate the program ended successfully
}
