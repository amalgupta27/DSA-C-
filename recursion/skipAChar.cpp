#include <iostream>  // Include iostream for input-output operations
#include <string>    // Include string library for string manipulation
using namespace std;  

// Recursive function to remove all occurrences of 'a' from a string
// ans -> Processed string without 'a'
// original -> Original input string
// idx -> Current index being checked
void removeChar(string ans, string original, int idx) {  
    if (idx == original.size()) {  // Base case: If index reaches the end of the string, print the result
        cout << ans;  // Output the modified string
        return;
    }

    char ch = original[idx];  // Get the current character from the original string

    if (ch == 'a')  
        removeChar(ans, original, idx + 1);  // Skip 'a' and move to the next character
    else  
        removeChar(ans + ch, original, idx + 1);  // Keep the character and move to the next character
}

int main() {
    string str = "amal gupta";  // Define the input string
    removeChar("", str, 0);  // Call the function to remove 'a' from the string
    cout << endl;  // Print a newline after output
    return 0;  // End of the program
}

/*
Example 1:
Input:  "amal gupta"
Output: "ml gupt"

Example 2:
Input:  "banana"
Output: "bnn"

Example 3:
Input:  "abcabc"
Output: "bcbc"

Example 4:
Input:  "hello"
Output: "hello" (since no 'a' is present)

Explanation:
- The function recursively processes the string, checking each character.
- If the character is 'a', it is skipped.
- Otherwise, it is added to the `ans` string.
- The process continues until the entire string is checked.
- Finally, the modified string is printed.

**Time Complexity Analysis:**
- The function iterates through the string **once**, processing each character exactly **one time**.
- **Each recursive call checks one character**, making `n` calls for a string of length `n`.
- String concatenation (`ans + ch`) **creates a new string each time**, which takes **O(k)** time (where `k` is the length of `ans`).
- In the worst case (when no 'a' is present), we create a new string of increasing length in each step, leading to **O(n²) complexity**.
  
**Best Case Complexity:** O(n) (if the string is empty or contains only 'a')  
**Worst Case Complexity:** O(n²) (if no 'a' is found, leading to excessive string concatenations)  
**Average Case Complexity:** Between O(n) and O(n²)  

To optimize this, we can avoid string concatenation and use **pass-by-reference or in-place modification**.
*/
