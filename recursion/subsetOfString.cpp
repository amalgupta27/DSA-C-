#include <iostream>  // Include iostream for input-output operations
#include <string>    // Include string library for string manipulation
using namespace std;  

// Recursive function to generate and print all subsets of a string
// ans -> Processed subset of characters
// original -> Original input string
// idx -> Current index being checked

//concept used in leetcode 78
void printSubset(string ans, string original, int idx) {  
    if (idx == original.size()) {  // Base case: If index reaches the end of the string, print the subset
        cout << ans << endl;  // Output the subset
        return;
    }

    char ch = original[idx];  // Get the current character from the original string

    // Recursive call **without** including the current character
    printSubset(ans, original, idx + 1);  

    // Recursive call **including** the current character
    printSubset(ans + ch, original, idx + 1);  
}

int main() {
    string str = "abc";  // Define the input string
    printSubset("", str, 0);  // Call the function to generate all subsets
    
    return 0;  // End of the program
}

/*
Example 1:
Input: "abc"
Output:
""  (empty subset)
"c"
"b"
"bc"
"a"
"ac"
"ab"
"abc"

Example 2:
Input: "ab"
Output:
""  (empty subset)
"b"
"a"
"ab"

**Explanation:**
- The function **recursively generates all possible subsets** of the input string.
- At each step, we have **two choices**:
  1. **Exclude** the current character and move forward.
  2. **Include** the current character and move forward.
- This ensures that **all subsets** (including the empty subset) are printed.

**Time Complexity Analysis:**
- At every character, we have **two choices** (include or exclude).
- For a string of length `n`, the number of recursive calls made is **2^n**.
- **Time Complexity:** O(2^n) (since we generate 2^n subsets)
- **Space Complexity:** O(n) (for recursion stack)

This approach correctly generates all possible subsets of a given string! 🚀
*/
