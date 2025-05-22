/*
--------------------------------------------
💡 PROBLEM KA LOGIC (Hinglish Explanation):
--------------------------------------------

Humare paas ek mathematical expression diya hai jaise: "2+6*4/8-3"
Yeh ek INFIX expression hai (operator beech mein hota hai: a + b)

Goal: Is expression ko evaluate karna hai correctly using operator precedence (BODMAS).
Toh hum 2 stack ka use karenge:
1️⃣ val[]  -> numbers (operands) ke liye
2️⃣ op[]   -> operators (+, -, *, /) ke liye

BODMAS Rule follow karte hue:
🔹 Agar naye operator ki priority zyada hai -> stack mein push karo
🔹 Agar kam ya barabar priority hai -> pehle evaluate karo phir push karo

Jaise:
Expression: 2 + 6 * 4 / 8 - 3
Evaluate step-by-step with stacks:
val: [2]
op:  ['+']
val: [2, 6]
op:  ['+', '*']
val: [2, 6, 4]
op:  ['+', '*', '/']
Now * and / ka evaluation hoga (kyunki / ki priority kam hai ya barabar)
Evaluate: 6 * 4 = 24, then 24 / 8 = 3, etc...

--------------------------------------------
🧭 FLOWCHART (In Hinglish ASCII Diagram):
--------------------------------------------

    [Start]
       |
       v
[Loop over expression char]
       |
       |----> Digit mila?
       |         |
       |       [Push in val stack]
       |
       |----> Operator mila?
                 |
        op.empty() ya op.top() se priority zyada?
                 |
               [Push in op stack]
                 |
           Nahi? (priority kam ya barabar)
                 |
           [Pop 2 values + 1 operator]
                 |
           [Evaluate & push result]
                 |
               [Continue loop]
       |
       v
[End of expression]
       |
       v
[Evaluate remaining operators]
       |
       v
[Final result in val.top()]
       |
       v
      [End]

--------------------------------------------
⌛ Time Complexity:
--------------------------------------------
Let n = length of the string
🔹 Each character is visited once: O(n)
🔹 Stack operations (push/pop) take O(1)
🔹 So overall: **O(n)** time
🔹 Space Complexity: O(n) in worst case for stacks

*/

#include<iostream>
#include<stack>
using namespace std;

// 🔢 Function to define priority of operators
int priority(char oper){
    if(oper=='+' || oper=='-') return 1;
    else if(oper=='*' || oper=='/') return 2;
    else return 0; // invalid operator
}

// ➕➖✖️➗ Function to perform calculation based on operator
int evaluate(int v1, int v2, char oper){
    if(oper=='+') return v1+v2;
    else if(oper=='-') return v1-v2;
    else if(oper=='*') return v1*v2;
    else if(oper=='/') return v1/v2;
    else return 0; // invalid case
}

int main(){
    string s = "2+6*4/8-3"; // Example input string (infix expression)

    // 📦 Two stacks - one for operands (numbers), one for operators
    stack<int> val; // val stack will store digits: [2, 6, 4...]
    stack<char> op; // op stack will store operators: [+ - * /]

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        
        // 🔍 Check if current character is a digit
        if(ch >= '0' && ch <= '9'){
            // ASCII se integer conversion: '2' -> 2
            val.push(ch - '0');
        }
        else {
            // 🎯 Current character is operator: +, -, *, /
            if(op.size() == 0 || priority(ch) > priority(op.top())){
                // Agar operator ka precedence zyada hai to directly push
                op.push(ch);
            }
            else {
                // Agar current operator ki priority kam ya barabar hai
                // pehle stack ke top 2 operands aur 1 operator se evaluate karo
                while(op.size() > 0 && priority(ch) <= priority(op.top())){
                    char oper = op.top(); op.pop();
                    int v2 = val.top(); val.pop();
                    int v1 = val.top(); val.pop();
                    int result = evaluate(v1, v2, oper);
                    val.push(result);
                }
                // Push current operator after evaluating previous one(s)
                op.push(ch);
            }
        }
    }

    // ✍️ After loop, kuch operators stack mein ho sakte hain
    while(op.size() > 0){
        char oper = op.top(); op.pop();
        int v2 = val.top(); val.pop();
        int v1 = val.top(); val.pop();
        int result = evaluate(v1, v2, oper);
        val.push(result);
    }

    // 🏁 Final result top of val stack mein hoga
    cout << "Final Answer = " << val.top() << endl;

    return 0;
}

/*
--------------------------------------------
🧪 Output for s = "2+6*4/8-3"
Step by step:
2 + (6*4 = 24) => 2 + (24/8 = 3) => 2+3 = 5 => 5 - 3 = 2
✅ Final Answer = 2
--------------------------------------------
*/
