#include<iostream>
#include<string>
using namespace std;

/**
✅ Question: Find the extra character
(Leetcode - 389)

🔵 Hinglish Simple Explanation:

- Tumhe 2 strings diye gaye hain: `s` aur `t`.
- `t` bana hai `s` ke characters ko shuffle karke, aur usme ek extra character add kiya gaya hai.
- Tumhe woh extra character find karna hai.

✅ Example:
Input: s = "abcd", t = "abcde"
Output: 'e'

Kyuki 'e' woh extra character hai jo sirf `t` me hai.

🔵 Approach:

1. Dono strings `s` aur `t` ko sort karo (alphabetical order mein).
2. Ab dono strings ko character by character compare karo.
3. Jaise hi koi character mismatched mile ➔ wahi extra character hai.
4. Agar sab match ho gaye, to last character of `t` extra hoga.

✅ Flow Chart (Hinglish mein):

    Start
      ↓
    sort(s), sort(t)
      ↓
    for each index i:
        if s[i] != t[i]:
            return t[i]
      ↓
    Return last character if no mismatch
      ↓
    End

🧠 Time Complexity:
- Sorting: O(n log n)
- Comparison: O(n)
- Total: O(n log n)

🧠 Space Complexity:
- O(1) (if ignoring sort space)

---------------------------------------------------
**/

#include <algorithm> // sorting ke liye

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        // Step 1: Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Step 2: Compare each character
        for (int i = 0; i < t.size(); i++) {
            // Agar koi character match nahi kar raha
            if (i >= s.size() || t[i] != s[i]) {
                return t[i]; // Yeh extra character hai
            }
        }
        
        // Step 3: Agar sab match ho gaye, to last character extra hoga
        return -1; // (Ye line kabhi practically nahi chalegi, bas formality ke liye hai)
    }
};
