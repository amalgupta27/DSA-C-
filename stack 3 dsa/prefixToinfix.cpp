/*
🧠💡 PREFIX TO INFIX CONVERSION (Hinglish Explanation):

📌 Prefix Expression Format:
   ➤ operator operand1 operand2
   Example: *+79/48 ➡️ means ((7+9)*(4/8))

🎯 Goal:
Prefix expression ko infix expression mein convert karna.
Infix format: (operand1 operator operand2)

👣 Steps:
1️⃣ Ek stack banao (string type) jisme operands aur intermediate expressions store karenge
2️⃣ Prefix string ko **right se left** traverse karo
3️⃣ Agar character ek digit ho:
   🔸 Stack mein push karo (as string)
4️⃣ Agar character operator ho:
   🔸 Stack se do strings pop karo (v1, v2)
   🔸 Infix string banao: v1 + operator + v2
   🔸 Wapas push karo stack mein
5️⃣ End mein stack ke top par final infix expression milega

🧪 Dry Run Example:
Prefix: -/*+79483

➡️ Right se start karte hain:
- Push "3"
- Push "8"
- Push "4"
- '+' ➡️ v1 = "7", v2 = "9" ➡️ result = "7+9"
- '*' ➡️ v1 = "7+9", v2 = "4" ➡️ result = "7+9*4"
- '/' ➡️ v1 = "7+9*4", v2 = "8" ➡️ result = "7+9*4/8"
- '-' ➡️ v1 = "7+9*4/8", v2 = "3" ➡️ result = "7+9*4/8-3"

➡️ Final infix expression: 7+9*4/8-3

🔄 FLOWCHART (ASCII - Hinglish Version):

         Start
           |
           v
   For i = n-1 to 0
           |
           v
   Is s[i] a digit?
        /     \
      Yes     No
       |       |
Push to stack  Is s[i] operator?
       |       |
       |     Yes
       |       |
       |   Pop v1 and v2
       |   result = v1 + op + v2
       |   Push result back to stack
        \_____/
           |
           v
       End loop
           |
           v
  Final infix at top of stack

📊 TIME COMPLEXITY:
➡️ O(n) – har character ko ek hi baar process kar rahe hain

📊 SPACE COMPLEXITY:
➡️ O(n) – stack mein maximum n strings store ho sakte hain
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Yeh function do operands aur operator leke ek infix expression banata hai
string solve(string v1, string v2, char oper){
    string s = "";
    s += v1;            // pehla operand
    s.push_back(oper);  // operator
    s += v2;            // doosra operand
    
    return s;           // infix expression return karo
}

int main(){
    string s = "-/*+79483"; // Prefix expression
    stack<string> val;      // Stack banaya for strings

    // Prefix expression ko right se left traverse karenge
    for(int i = s.length() - 1; i >= 0; i--){
        int ascii = (int)(s[i]);

        // Agar digit mila toh string mein convert karke push kar do
        if(ascii >= 48 && ascii <= 57){
            val.push(to_string(ascii - 48)); // '7' ➝ 55 ➝ 55-48 = 7
        }
        else{
            // Agar operator mila toh top ke 2 strings nikalo
            string v1 = val.top(); val.pop();
            string v2 = val.top(); val.pop();

            // Infix banake wapas stack mein daal do
            string result = solve(v1, v2, s[i]);
            val.push(result);
        }
    }

    // Final infix expression top of the stack pe hoga
    cout << "Infix Expression: " << val.top() << endl;

    return 0;
}

/*
🟢 OUTPUT:
Infix Expression: 7+9*4/8-3

📌 Is output ka matlab hai:
Original prefix expression -/*+79483 ko jab infix mein convert karte hain toh result hota hai:
(7 + 9) * 4 / 8 - 3 (Without brackets here, par priority ke hisaab se yeh correct hoga)

📊 Time Complexity: O(n)
📊 Space Complexity: O(n)
*/
