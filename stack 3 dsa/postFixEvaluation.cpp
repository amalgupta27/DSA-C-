/*
🧠💡 LOGIC OF POSTFIX EXPRESSION EVALUATION (Hinglish mein):

Postfix expression: Operators baad mein aate hain, jaise: "79+4*8/3-"
Matlab: (7 + 9) * 4 / 8 - 3

👣 Steps:
1️⃣ Ek stack banao sirf numbers (integers) ke liye.
2️⃣ Expression ko left se right padho.
3️⃣ Agar character digit ho (0-9), toh usse integer mein convert karke stack mein daal do.
4️⃣ Agar character operator ho (+, -, *, /):
    🔸 Do numbers pop karo stack se
    🔸 Unpe operation lagao (v1 operator v2)
    🔸 Result ko stack mein push karo
5️⃣ End tak karte raho.
6️⃣ Stack mein jo last element bachega, wahi final result hai.

🛠 Example: 
Input postfix = "79+4*8/3-"

Step by step:
1. Push 7 ➡️ stack: [7]
2. Push 9 ➡️ stack: [7, 9]
3. '+' ➡️ pop 9 & 7 ➡️ 7+9 = 16 ➡️ push 16 ➡️ [16]
4. Push 4 ➡️ [16, 4]
5. '*' ➡️ 16*4 = 64 ➡️ [64]
6. Push 8 ➡️ [64, 8]
7. '/' ➡️ 64/8 = 8 ➡️ [8]
8. Push 3 ➡️ [8, 3]
9. '-' ➡️ 8-3 = 5 ➡️ [5]
✅ Final answer = 5

🔄 FLOWCHART (Hinglish mein):

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
        |           Solve(v1 op v2)
        |               |
        |         Push result to stack
        \______________/
              |
              v
            End loop
              |
              v
     Top of stack = result

📊 TIME COMPLEXITY:
➡️ O(n), where n = length of expression
    We scan each character once
    Each push/pop is O(1)
➡️ Space Complexity: O(n) for stack

*/

// C++ Code Starts here
#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Yeh function operator ke according operation karta hai
int solve(int v1, int v2, char oper){
    if(oper=='+') return (v1+v2);
    else if(oper=='-') return (v1-v2);
    else if(oper=='*') return (v1*v2);
    else if(oper=='/') return (v1/v2);
    else return 0; // Agar operator valid nahi hai
}

int main(){
    string s = "79+4*8/3-"; // Example postfix expression

    // Ek stack banao operands ke liye (matlab numbers store karne ke liye)
    stack<int> val;

    // Har character ke liye loop chalega
    for(int i=0; i<s.length(); i++){
        // ASCII check kar rahe hain agar digit ho (0-9)
        int ascii  = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57){
            // Character digit hai: usse integer mein convert karo aur push karo
            // Example: '7' => ASCII 55, 55 - 48 = 7
            val.push(ascii - 48);
        }
        else{
            // Agar character operator hai (+, -, *, /)
            // Tab do top values stack se nikaalo
            int v2 = val.top(); val.pop(); // Second operand
            int v1 = val.top(); val.pop(); // First operand
            // Operation karo v1 op v2 (jaise 7 + 9)
            int result = solve(v1, v2, s[i]);
            // Result ko wapas stack mein daal do
            val.push(result);
        }
    }

    // Jab pura expression process ho gaya, toh stack ka top hi final result hai
    cout << "Final Result: " << val.top() << endl;

    return 0;
}

/*
OUTPUT:
Final Result: 5

🧠 Time Complexity: O(n)
🧠 Space Complexity: O(n)

Postfix expression evaluation stack ka concept dikhata hai.
Stack se hum expression ko bina brackets ke easily evaluate kar sakte hain.
*/
