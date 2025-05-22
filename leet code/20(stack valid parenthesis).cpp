/*
👨‍🏫====================== PROBLEM LOGIC IN HINGLISH ======================👨‍🏫

🧩 Problem:
Hume check karna hai ki ek string s jisme brackets hain — (), {}, []
kya wo **valid** hai ya nahi.
Valid ka matlab:
1️⃣ Har opening bracket ka closing pair ho (aur sahi order me ho)
2️⃣ Nested brackets bhi sahi tarike se close ho

🧠 Example:
Input: "{[()]}"     ✅ Valid
Input: "((]"        ❌ Invalid
Input: "({[})"      ❌ Invalid
Input: "()"         ✅ Valid

🚀 Kaise karenge?
Stack ka use karke.
👉 Jaise hi opening bracket mile, stack me daal do.
👉 Jaise hi closing bracket mile:
   ➤ Stack empty ho to invalid
   ➤ Stack ke top se match karo (top aur current ka pair valid hai ya nahi)
   ➤ Agar pair match kare to pop karo
   ➤ Agar galat ho to invalid

📊================== FLOWCHART (HINGLISH) ==================

           +-------------------+
           |   Start Function  |
           +-------------------+
                    |
                    v
     +------------------------------+
     | Length odd? -> Return false |
     +------------------------------+
                    |
                    v
     <----- For each char in string ----->
                    |
                    v
        +----------------------------+
        | Opening bracket?           |
        | Yes --> stack.push(char)   |
        +----------------------------+
                    |
                    | No
                    v
        +----------------------------+
        | Stack empty?               |
        | Yes --> Return false       |
        +----------------------------+
                    |
                    v
        +------------------------------------------+
        | Top of stack match karta hai closing se? |
        | No --> Return false                      |
        | Yes --> stack.pop()                      |
        +------------------------------------------+
                    |
                    v
             End of Loop ✅
                    |
                    v
          +------------------------+
          | Stack empty?           |
          | Yes --> Return true ✅  |
          | No  --> Return false ❌ |
          +------------------------+

===============================================================
💻 TIME COMPLEXITY:
• Time: O(n) - Each character ek hi baar check ho raha hai
• Space: O(n) - Worst case me sab characters stack me ho sakte hain

===============================================================
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        // Agar length odd hai, valid ho hi nahi sakta
        if(s.size() % 2 != 0) return false;

        // Loop through each character
        for(int i = 0; i < s.size(); i++) {
            // Agar opening bracket hai, to stack me push karo
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else {
                // Agar closing bracket mile aur stack empty ho gaya ho to galat
                if(st.size() == 0) return false;

                // Agar bracket ka pair galat hai to bhi invalid
                if(s[i] == ')' && st.top() != '(') return false;
                else if(s[i] == '}' && st.top() != '{') return false;
                else if(s[i] == ']' && st.top() != '[') return false;
                else {
                    // Agar sahi pair hai to stack se hata do
                    st.pop();
                }
            }
        }

        // Agar last me stack empty hai, matlab sab pair sahi the
        return st.size() == 0;
    }
};

// ✅ Sample Driver Code
int main() {
    Solution sol;
    string s = "{[()]}"; // Try other examples too: "((])", "[({})]", "((("
    cout << (sol.isValid(s) ? "Valid ✅" : "Invalid ❌") << endl;
    return 0;
}
