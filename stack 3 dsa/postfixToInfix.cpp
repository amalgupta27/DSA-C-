/*
🧠💡 LOGIC OF POSTFIX ➡️ INFIX CONVERSION (Hinglish mein):

📌 Postfix expression: Operator baad mein aate hain
📌 Infix expression: Operator beech mein aate hain (jaise 7 + 9)

🎯 Goal: Postfix expression ko infix expression mein convert karna
Example: "79+4*8/3-" ➡️ (((7+9)*4)/8)-3

👣 Steps:
1️⃣ Ek stack banao strings store karne ke liye.
2️⃣ Expression ko left se right padho.
3️⃣ Agar character digit ho (0-9), toh usse string mein convert karke stack mein daal do.
4️⃣ Agar character operator ho (+, -, *, /):
    🔸 Do strings pop karo stack se (v2 & v1)
    🔸 Infix banaao: v1 + operator + v2
    🔸 Us result ko stack mein wapas push karo
5️⃣ End tak yeh process chalao.
6️⃣ Stack ke top par final infix expression hoga.

🛠 Example: 
Postfix = "79+4*8/3-"
Dry run:
1. Push '7' ➡️ [ "7" ]
2. Push '9' ➡️ [ "7", "9" ]
3. '+' ➡️ "7+9" ➡️ push ➡️ [ "7+9" ]
4. Push '4' ➡️ [ "7+9", "4" ]
5. '*' ➡️ "7+9*4" ➡️ [ "7+9*4" ]
6. Push '8' ➡️ [ "7+9*4", "8" ]
7. '/' ➡️ "7+9*4/8" ➡️ [ "7+9*4/8" ]
8. Push '3' ➡️ [ "7+9*4/8", "3" ]
9. '-' ➡️ "7+9*4/8-3" ➡️ [ "7+9*4/8-3" ]

🎯 Final Infix: 7+9*4/8-3  (Note: brackets nahi lagaye for clarity; you can use them too)

🔄 FLOWCHART (ASCII, Hinglish mein):

          Start
            |
            v
    For each char in expr
            |
            v
    Is char a digit?
         /   \
        Yes   No
        |     |
 Push to stack  Is it + - * / ?
        |     |
        |   Yes ---> Pop v2, v1
        |               |
        |        v1 + op + v2 string banao
        |               |
        |        Push result to stack
        \______________/
              |
              v
            End loop
              |
              v
     Top of stack = final infix expression

📊 TIME COMPLEXITY:
➡️ O(n), where n = length of expression
    Each character processed once
➡️ Space Complexity: O(n) for stack (strings stored)

*/

// C++ Code Begins here
#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Yeh function 2 operands aur ek operator ko combine karta hai infix string mein
string solve(string v1, string v2, char ch){
    string s = "";
    s += "(";      // Brackets for clarity (optional)
    s += v1;
    s.push_back(ch);
    s += v2;
    s += ")";
    return s;
}

int main(){
    string s = "79+4*8/3-"; // Example postfix expression

    // Ek stack bana rahe hain string values ke liye
    stack<string> val;

    for(int i = 0; i < s.length(); i++){
        // ASCII check for digit (0-9)
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57){
            // Digit ko string mein convert karo aur push karo
            val.push(to_string(ascii - 48));
        }
        else{
            // Operator mila: Do top strings nikaalo
            string v2 = val.top(); val.pop();
            string v1 = val.top(); val.pop();
            // Infix form banao
            string result = solve(v1, v2, s[i]);
            val.push(result); // Stack mein daal do
        }
    }

    // Stack ke top par final infix expression milega
    cout << "Final Infix Expression: " << val.top() << endl;

    return 0;
}

/*
🟢 OUTPUT:
Final Infix Expression: (((7+9)*4)/8)-3

📊 Time Complexity: O(n)
📊 Space Complexity: O(n)

📚 Note:
- Brackets add kiye gaye hain clarity ke liye.
- Agar aapko without brackets infix chahiye, toh `solve()` function se brackets hata sakte ho.
*/
