/*
📘 QUESTION: Convert Infix Expression to Postfix (using stacks)
-------------------------------------------------------------------------------
🔶 Infix Expression: 
    Ek mathematical expression jisme operators beech me hote hain 
    jaise: 1 + (2 + 6) * 4 / 8 - 3

🔶 Objective:
    Is infix expression ko postfix format me convert karna hai.
    Postfix ka matlab hota hai: operand operand operator
    Example: 
        Infix: 2 + 3 => Postfix: 2 3 +
        Infix: (2 + 3) * 4 => Postfix: 2 3 + 4 *
        Infix: 1 + (2 + 6) * 4 / 8 - 3 => Postfix: 126+4*8/+3-

🧠 LOGIC (Hinglish Explanation):
-------------------------------------------------------------------------------
1️⃣ 2 stacks banate hain:
    ➤ val: jisme hum operands (numbers in string format) store karte hain
    ➤ op: jisme hum operators (+, -, *, /, (, )) store karte hain

2️⃣ Expression ke har character par loop lagate hain:
    🔹 Agar digit ho (0-9), usko val stack me push karte hain
    🔹 Agar '(' ho, directly op stack me push karte hain
    🔹 Agar ')' ho, tab tak pop karte hain jab tak '(' na mile
        ➤ Har bar 2 values pop hoti hain val se
        ➤ Ek operator pop hota hai op se
        ➤ solve() se postfix banate hain => v1 + v2 + oper
        ➤ result wapas val me daalte hain
    🔹 Agar operator mile:
        ➤ Agar uski priority zyada ho op.top() se, push it
        ➤ Agar uski priority kam ya barabar ho, pehle evaluate karo
          (operator aur 2 values pop karke solve(), phir push)
        ➤ Finally current operator ko push karo

3️⃣ Loop ke baad bhi agar op stack me kuch hai toh evaluate karte hain

✅ Final result val.top() par hoga — postfix expression as string

🧾 Example Dry Run (1+(2+6)*4/8-3):
----------------------------------------------------------------------------
val: 1
op: +
val: 2, 6
op: +
Eval: 2 + 6 = 26+
val: 1, 26+
op: *
val: 4
op: /
val: 8
Eval: 4 / 8 = 48/
Eval: 26+ * 48/ = 26+48/*
val: 1, 26+48/*
op: -
val: 3
Eval: 26+48/* - 3 = 1 26+48/* + 3 -
Final: 126+4*8/+3-

🧠 ASCII Flowchart (Hinglish Style):
----------------------------------------------------------------------------
                [Shuru karo]
                     |
               [Loop har character par]
                     |
          +------------------------+
          | Digit hai? (0-9)       |
          |------------------------|
          | ✔ Haan ➤ Push in val   |
          | ✖ Nahi ➤ Neeche jao    |
          +------------------------+
                     |
       +-----------------------------+
       | '(' hai? ➤ Push in op      |
       | ')' hai? ➤ Pop & evaluate  |
       +-----------------------------+
                     |
    +-------------------------------------------+
    | Operator hai?                             |
    | ➤ Compare priority with op.top()          |
    | ➤ Agar zyada ➤ Push in op                 |
    | ➤ Agar kam/barabar ➤ Evaluate & then push|
    +-------------------------------------------+
                     |
              [Loop khatam hone ke baad]
                     |
         [Bache huye operators evaluate karo]
                     |
             [val.top() = final answer]
                     |
                  [End]

⏱️ TIME COMPLEXITY:
----------------------------------------------------------------------------
🔹 O(n) where n = number of characters in string
🔹 Har character ek baar stack me jata hai ya nikalta hai => O(1) operation
🔹 solve() and push/pop all take constant time
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

// 📌 Function to decide priority of operators
int priority(char oper){
    if(oper=='+' || oper=='-') return 1;     // + or - have lowest priority
    else if(oper=='*' || oper=='/') return 2; // * or / have higher priority
    else return 0; // Invalid character
}

// 📌 Function to make postfix expression (v1 + v2 + oper)
string solve(string v1, string v2, char oper){
    // postfix format: operand1 operand2 operator
    string s = "";
    s += v1; // first operand
    s += v2; // second operand
    s.push_back(oper); // add operator at end
    return s; // return result string
}

int main(){
    string s = "1+(2+6)*4/8-3"; // ✅ Example infix expression

    stack<string> val; // 📦 Stack to store operands (as strings)
    stack<char> op;    // 🧮 Stack to store operators and parentheses

    for(int i=0; i<s.length(); i++){
        int ascii = (int)(s[i]); // Convert char to ASCII for digit check

        // 🔹 Agar character digit hai (0-9)
        if(ascii >= 48 && ascii <= 57){
            val.push(to_string(ascii - 48)); // Convert char to int, then to string
        }
        else{
            // 🔹 Agar operator ya bracket mila
            if(op.size() == 0) op.push(s[i]); // Agar stack empty hai, push directly

            else if(s[i] == '(' || op.top() == '(') op.push(s[i]); // '(' ko directly push karo

            else if(s[i] == ')'){
                // ')' mila toh tab tak evaluate karo jab tak '(' mile
                while(op.top() != '('){
                    char oper = op.top(); op.pop();
                    string v2 = val.top(); val.pop();
                    string v1 = val.top(); val.pop();
                    string result = solve(v1, v2, oper);
                    val.push(result); // Push solved result into val stack
                }
                op.pop(); // '(' ko bhi hata do
            }
            else if(priority(s[i]) > priority(op.top())) op.push(s[i]); // agar current operator ki priority zyada hai

            else{
                // Jab priority kam ya barabar ho => pehle evaluate karo
                while(op.size() > 0 && priority(s[i]) <= priority(op.top())){
                    char oper = op.top(); op.pop();
                    string v2 = val.top(); val.pop();
                    string v1 = val.top(); val.pop();
                    string result = solve(v1, v2, oper);
                    val.push(result);
                }
                op.push(s[i]); // fir current operator ko push karo
            }
        }
    }

    // 🔚 End of expression: bache huye operators evaluate karo
    while(op.size() > 0){
        char oper = op.top(); op.pop();
        string v2 = val.top(); val.pop();
        string v1 = val.top(); val.pop();
        string result = solve(v1, v2, oper);
        val.push(result);
    }

    // 🟢 Final postfix expression
    cout << val.top() << endl;

    return 0;
}
