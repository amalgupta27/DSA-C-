/*
📘 PROBLEM: Infix Expression Evaluation using Stacks
---------------------------------------------------
🔹 Infix expression: Mathematical expression jisme operators beech me hote hain.
   For example: 1+(2+6)*4/8-3
   Hume ye expression evaluate karna hai using priority (BODMAS rule) aur brackets.

🔧 Approach:
---------------------------------------------------
1. Use two stacks:
   - stack<int> val: stores operands (numbers)
   - stack<char> op: stores operators (+, -, *, /, (, ))

2. Loop through each character in string:
   - Agar digit mile (0–9), use val stack me daalo.
   - Agar '(' mile, use op stack me daalo.
   - Agar ')' mile, tab tak evaluate karo jab tak '(' mil jaaye.
   - Agar operator mile (+, -, *, /), uski priority check karo with op.top().
     ➤ Agar higher priority hai, toh push karo.
     ➤ Agar lower ya equal hai, toh evaluate karte jao jab tak priority high na ho.

3. Finally, bache huye operators ko evaluate karo.

🕒 Time Complexity:
---------------------------------------------------
✅ O(n) — where n = length of expression
✅ Each character ko ek baar process karte hain (digit ya operator)
✅ Stack operations are O(1)

💡 Dry Run Example:
---------------------------------------------------
Expression: 1+(2+6)*4/8-3

Step-by-step:
1 -> val: [1]
( -> op: ['(']
2 -> val: [1,2]
+ -> op: ['(','+']
6 -> val: [1,2,6]
) -> evaluate 2+6 = 8 -> val: [1,8], op: ['('] -> pop '('
* -> op: ['*']
4 -> val: [1,8,4]
/ -> op: ['*','/']
8 -> val: [1,8,4,8]
Now evaluate: 4 / 8 = 0 -> val: [1,8,0]
Then: 8 * 0 = 0 -> val: [1,0]
- -> op: ['-']
3 -> val: [1,0,3]
Evaluate: 0 - 3 = -3 -> val: [1,-3]
Then: 1 - (-3) = -2

✅ Final Result: -2

🧠 Flowchart (ASCII Diagram in Hinglish):
---------------------------------------------------
           [Start]
               |
        [for loop chalao]
               |
        ch == digit (0-9)?
               |
             Yes ➜ [val.push()]
               |
             No
               |
         ch == '(' ?
               |
             Yes ➜ [op.push('(')]
               |
             No
               |
         ch == ')' ?
               |
             Yes ➜ [Evaluate till '(']
               |
             No
               |
         ch == operator ?
               |
        priority <= op.top() ?
               |
             Yes ➜ [Evaluate]
               |
               ⬇
        [Push current operator]
               |
         [Loop ends]
               |
     [Evaluate bache huye operators]
               |
          [Print val.top()]
               |
            [End]
*/

// ---------------------------------------------------
#include<iostream>
#include<stack>
using namespace std;

// ⚖️ Function to check operator priority
int priority(char oper){
    if(oper=='+' || oper=='-') return 1;
    else if(oper=='*' || oper=='/') return 2;
    else return 0; // for invalid operator
}

// ➕➖✖️➗ Evaluate two values with given operator
int evaluate(int v1, int v2, char oper){
    if(oper=='+') return v1+v2;
    else if(oper=='-') return v1-v2;
    else if(oper=='*') return v1*v2;
    else if(oper=='/') return v1/v2;
    else return 0; // for invalid operator
}

// 🧠 Main function
int main(){
    string s = "(7+9)*4/8-3"; 
    
    stack<int> val; // Stack for operands (values like 1, 2, etc.)
    stack<char> op; // Stack for operators (+, -, *, /, etc.)

    for(int i=0;i<s.length();i++){
        int ascii  = (int)(s[i]);

        // ✅ Agar digit hai toh number banake value stack me daal do
        if(ascii>=48 && ascii<=57){
            val.push(ascii-48); // ASCII se int me convert
        }
        else{
            // ❗ yaha operator ya bracket aaya hai
            if(op.size()==0) op.push(s[i]); // Stack empty hai toh push karo
            else if(s[i]=='(' || op.top()=='(') op.push(s[i]); // '(' ko priority dete hai
            else if(s[i]==')'){
                // ')' mila toh '(' tak evaluate karo
                while(op.top()!='('){
                    char oper = op.top(); op.pop();
                    int v2 = val.top(); val.pop();
                    int v1 = val.top(); val.pop();
                    int result = evaluate(v1,v2,oper);
                    val.push(result);
                }
                op.pop(); // '(' ko hata do
            }
            // Agar current operator ki priority high hai toh directly push kar do
            else if(priority(s[i])>priority(op.top())) op.push(s[i]); // current operator ko push karo
            else{
                // Priority kam ya barabar hai, pehle evaluate karo
                while(op.size()>0 && priority(s[i])<=priority(op.top())){
                    char oper = op.top(); op.pop();
                    int v2 = val.top(); val.pop();
                    int v1 = val.top(); val.pop();
                    int result = evaluate(v1,v2,oper);
                    val.push(result);
                }
                op.push(s[i]); // current operator ko push karo
            }
        }
    }

    // ✅ Loop ke baad bache huye operators ko bhi evaluate karo
    while(op.size()>0){
        char oper = op.top(); op.pop();
        int v2 = val.top(); val.pop();
        int v1 = val.top(); val.pop();
        int result = evaluate(v1,v2,oper);
        val.push(result);
    }

    // ✅ Final answer stack ke top me hoga
    cout<<val.top()<<endl;

    return 0;
}
