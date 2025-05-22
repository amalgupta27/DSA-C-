/*
🧠💡 LOGIC OF POSTFIX ➡️ PREFIX CONVERSION (Hinglish mein):

📌 Postfix Expression (Reverse Polish Notation): Operator baad mein aata hai  
📌 Prefix Expression (Polish Notation): Operator sabse pehle aata hai  
   Example: 
     Postfix: 79+ ➡️ Prefix: +79

🎯 Goal: Postfix expression ko prefix expression mein convert karna

👣 Steps:
1️⃣ Ek stack banao strings store karne ke liye.
2️⃣ Expression ko left to right traverse karo.
3️⃣ Agar character digit ho (0-9):
   🔸 Usse string mein convert karke stack mein push karo
4️⃣ Agar character operator ho (+, -, *, /):
   🔸 Stack ke top do elements (v2 and v1) pop karo
   🔸 Prefix expression banao: operator + v1 + v2
   🔸 Is result ko wapas stack mein push karo
5️⃣ Last mein stack ka top = final prefix expression

🧪 Dry Run:
Postfix = "79+4*8/3-"

Steps:
1. Push '7' ➡️ ["7"]
2. Push '9' ➡️ ["7", "9"]
3. '+' ➡️ "+79" ➡️ ["+79"]
4. Push '4' ➡️ ["+79", "4"]
5. '*' ➡️ "*+794" ➡️ ["*+794"]
6. Push '8' ➡️ ["*+794", "8"]
7. '/' ➡️ "/*+7948" ➡️ ["/*+7948"]
8. Push '3' ➡️ ["/*+7948", "3"]
9. '-' ➡️ "-/*+79483" ➡️ ["-/*+79483"]

✅ Final Prefix: -/*+79483

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
        |        Prefix = op + v1 + v2
        |               |
        |        Push result to stack
        \______________/
              |
              v
            End loop
              |
              v
     Top of stack = final prefix expression

📊 TIME COMPLEXITY:
➡️ O(n), where n = length of expression
    Each character processed once
➡️ SPACE COMPLEXITY: O(n) for stack (string expressions stored)

*/

// C++ code begins here
#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Yeh function do operands aur ek operator ko prefix expression mein jodta hai
string solve(string v1, string v2, char ch){
    string s = "";
    s.push_back(ch); // Operator sabse pehle
    s += v1;         // Pehla operand
    s += v2;         // Doosra operand
    return s;
}

int main(){
    string s = "79+4*8/3-"; // Postfix expression

    // Stack of strings: operands aur intermediate prefix expressions ko store karega
    stack<string> val;

    for(int i = 0; i < s.length(); i++){
        // ASCII check: kya s[i] ek digit hai (0 to 9)?
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57){
            // Digit ko string mein convert karke push kar do
            val.push(to_string(ascii - 48));
        }
        else{
            // Operator mila: pop karo top 2 operands
            string v2 = val.top(); val.pop();
            string v1 = val.top(); val.pop();
            // Prefix expression banao using solve function
            string result = solve(v1, v2, s[i]);
            val.push(result); // Stack mein result push karo
        }
    }

    // Stack ke top par final prefix expression milega
    cout << "Final Prefix Expression: " << val.top() << endl;

    return 0;
}

/*
🟢 OUTPUT:
Final Prefix Expression: -/*+79483

📊 Time Complexity: O(n)
📊 Space Complexity: O(n)

📌 NOTE:
- Stack LIFO (Last In First Out) ki tarah kaam karta hai
- Postfix ka order preserve karne ke liye operands ka sequence v1 v2 rakha gaya hai
- Prefix mein operator sabse pehle aata hai
*/
