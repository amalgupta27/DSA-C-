#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Function: printSubset
Purpose: Find and print all groups (subsets) of exactly `k` numbers from the list.
Parameters:
    - arr[]  : The list of numbers.
    - n      : The total number of numbers in the list.
    - idx    : The current position in the list.
    - ans    : A list that stores numbers we pick for a subset.
    - k      : The required number of numbers in a subset.
*/
void printSubset(int arr[], int n, int idx, vector<int> ans, int k) {
    // If we checked all numbers in the list
    if (idx == n) {
        // If we picked exactly `k` numbers, print them
        if (ans.size() == k) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";  // Print the numbers in the subset
            }
            cout << endl;  // Move to the next line for the next subset
        }
        return;  // Stop checking further
    }

    // If it's impossible to form a subset of size `k`, stop (optimization)
    if (ans.size() + (n - idx) < k) return; 

    // Ignore the current number and move to the next
    printSubset(arr, n, idx + 1, ans, k);

    // Pick the current number and move to the next
    ans.push_back(arr[idx]);  // Add the number to the subset
    printSubset(arr, n, idx + 1, ans, k);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};  // The list of numbers
    int n = sizeof(arr) / sizeof(arr[0]);  // Find how many numbers are in the list
    vector<int> v;  // This will store each subset
    int k = 3;  // We want to find groups of 3 numbers

    printSubset(arr, n, 0, v, k);  // Start finding subsets

    return 0;
}

/*
==========================================
Example Walkthrough for Input: {1, 2, 3, 4, 5}, k = 3
==========================================

Step-by-step explanation:

1. Start with an empty group `[]`.
2. Either take or skip each number in the list.
3. Stop when we find a group of exactly 3 numbers.

Possible groups of 3 numbers:

- [1, 2, 3]
- [1, 2, 4]
- [1, 2, 5]
- [1, 3, 4]
- [1, 3, 5]
- [1, 4, 5]
- [2, 3, 4]
- [2, 3, 5]
- [2, 4, 5]
- [3, 4, 5]

==========================================
Expected Output:
==========================================
1 2 3  
1 2 4  
1 2 5  
1 3 4  
1 3 5  
1 4 5  
2 3 4  
2 3 5  
2 4 5  
3 4 5  
==========================================
*/
