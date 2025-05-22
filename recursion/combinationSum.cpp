#include <iostream>  // This library allows input and output operations (like printing to the screen)
#include <vector>    // This library is used for the "vector" data structure (a dynamic array)
using namespace std; // This allows us to use standard functions like cout and cin without prefixing "std::"

/*
This function finds all possible combinations of numbers from the given array (arr[])
that sum up to a target value. The same number can be used multiple times.
It uses recursion to try different possibilities.

Parameters:
- v: A vector that temporarily holds the numbers being used in the current combination.
- arr: The array of numbers that we can use to form the sum.
- n: The size of the array (total number of elements in arr[]).
- target: The remaining sum we need to achieve.
- idx: The current index in arr[] that we are considering (to avoid repeating combinations in different orders).
*/
void combination(vector<int> v, int arr[], int n, int target, int idx) {
    // Base case: If target becomes exactly 0, it means we have found a valid combination
    if (target == 0) {
        for (int i = 0; i < v.size(); i++) { // Loop through the vector and print the combination
            cout << v[i] << " ";  // Print each number in the current valid combination
        }
        cout << endl; // Print a newline after printing the combination
        return; // Exit this function call since we found a valid combination
    }

    // Base case: If target becomes negative or there are no more elements to consider, stop further recursion
    if (target < 0 || n == 0) return;

    // Loop through each element in the array starting from the given index 'idx'
    for (int i = idx; i < n; i++) {
        v.push_back(arr[i]); // Add the current number (arr[i]) to the combination
        combination(v, arr, n, target - arr[i], i); // Recursive call: Reduce target and allow the same number to be picked again
        v.pop_back(); // Remove the last added number to try the next possibility (Backtracking)
    }
}

int main() {
    int arr[] = {2, 3, 5}; // Array of available numbers to form the target sum
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in arr[]
    int target = 8; // The target sum we need to achieve
    vector<int> v; // A vector to store the current combination

    // Call the function with an empty vector, full array, target sum, and start index 0
    combination(v, arr, n, target, 0);

    return 0; // Exit the program
}

/*
**Example Walkthrough:**

Input:
arr[] = {2, 3, 5}, target = 8

Output:
2 2 2 2
2 2 3
2 3 3
3 5

**Step-by-step Execution:**
1. Start with an empty combination: []
2. Try adding 2:
   - [2] → Remaining target: 6
   - [2, 2] → Remaining target: 4
   - [2, 2, 2] → Remaining target: 2
   - [2, 2, 2, 2] → Remaining target: 0 → **Valid combination!**
3. Backtrack and try adding 3:
   - [2, 2, 3] → Remaining target: 0 → **Valid combination!**
4. Backtrack and try other possibilities:
   - [2, 3, 3] → Remaining target: 0 → **Valid combination!**
   - [3, 5] → Remaining target: 0 → **Valid combination!**

The program explores all possible ways to form 8 using {2, 3, 5} while allowing repetition.

This is a **backtracking algorithm** because it tries different possibilities, and if a choice does not work, it undoes the last step (backtracks) and tries another option.
*/
