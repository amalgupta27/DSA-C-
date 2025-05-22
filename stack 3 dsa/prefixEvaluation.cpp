/*
🧠💡 LOGIC OF PREFIX EXPRESSION EVALUATION (Hinglish mein):

📌 Prefix (Polish) Expression ka format: operator operand1 operand2
   Example: + 7 9 ➡️ means (7 + 9)

🎯 Goal: Prefix expression evaluate karna and final result print karna

👣 Steps:
1️⃣ Ek stack banao to store operands (integers)
2️⃣ Expression ko **right se left** traverse karo (kyunki prefix mein operator pehle hota hai)
3️⃣ Agar character digit ho (0-9):
   🔸 Usse integer mein convert karke stack mein push karo
4️⃣ Agar operator mile:
   🔸 Stack se do top values pop karo (v1 and v2)
   🔸 Result = v1 (operator) v2
   🔸 Result ko wapas stack mein push karo
5️⃣ Loop ke baad stack ke top par final result hoga

🧪 Dry Run:
Prefix = "-/*+79483"

Reverse traverse:

1. Push 3      ➡️ [3]
2. Push 8      ➡️ [3, 8]
3. Push 4      ➡️ [3, 8, 4]
4. '+'         ➡️ 4 + 9 = 13        [3, 8, 13]
5. Push 9      ➡️ [3, 8, 13, 9]
6. Push 7      ➡️ [3, 8, 13, 9, 7]
7. '*'         ➡️ 13 * 4 = 52       [3, 8, 52]
8. '/'         ➡️ 52 / 8 = 6        [3, 6]
9. '-'         ➡️ 6 - 3 = 3         [3]

✅ Final Answer: 3

🔄 FLOWCHART (ASCII style - Hinglish mein):

         Start
           |
           v
   For i = n-1 to 0
           |
           v
   Is s[i] a digit?
         /    \
       Yes     No
        |       |
 Push to stack  Is s[i] operator?
        |       |
        |     Yes
        |       |
        |   Pop v1 and v2
        |   Result = v1 op v2
        |   Push result to stack
         \_____/
           |
           v
       End loop
           |
           v
    Print top of stack = final result

📊 TIME COMPLEXITY:
➡️ O(n)  - Har character ek baar process hota hai

📊 SPACE COMPLEXITY:
➡️ O(n)  - Stack mein max n/2 values at a time (operands)
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Operator apply karne wala function
int solve(int v1, int v2, char oper){
    if(oper == '+') return (v1 + v2);
    else if(oper == '-') return (v1 - v2);
    else if(oper == '*') return (v1 * v2);
    else if(oper == '/') return (v1 / v2);
    else return 0; // Invalid operator case
}

int main(){
    string s = "-/*+79483"; // Prefix expression
    stack<int> val; // Stack for operands

    // Prefix expression ko reverse (right to left) traverse karte hain
    for(int i = s.length() - 1; i >= 0; i--){
        int ascii = (int)(s[i]);

        // Check: kya s[i] ek digit hai?
        if(ascii >= 48 && ascii <= 57){
            val.push(ascii - 48); // Char ko int mein convert karke push
        }
        else{
            // Operator mila hai (+, -, *, /)
            int v1 = val.top(); val.pop(); // First operand
            int v2 = val.top(); val.pop(); // Second operand

            // Solve the operation
            int result = solve(v1, v2, s[i]);

            // Push the result back to stack
            val.push(result);
        }
    }

    // Final result will be on top of the stack
    cout << "Final Result of Prefix Evaluation: " << val.top() << endl;

    return 0;
}

/*
🟢 OUTPUT:
Final Result of Prefix Evaluation: 3

📊 Time Complexity: O(n)
📊 Space Complexity: O(n)

📌 NOTE:
- Stack LIFO structure follow karta hai
- Prefix expression mein operator pehle hota hai, isiliye reverse loop
*/
