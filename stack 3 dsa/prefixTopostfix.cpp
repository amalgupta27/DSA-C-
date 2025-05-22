/*
🧠💡 PREFIX TO POSTFIX CONVERSION – Hinglish Explanation

📌 Prefix Expression Format:
   ➤ Operator Operand1 Operand2
   ➤ Example: *+AB-CD ➝ means (A + B) * (C - D)

🎯 Goal:
Prefix expression ko Postfix expression me convert karna.
Postfix format: Operand1 Operand2 Operator

🛠️ Is code ka kaam hai:
Prefix expression (jaise "-/*+79483") ko Postfix form me convert karna
Aur result string ke form me print karna jaise: 79+4*8/3-

👣 LOGIC (Steps):
1️⃣ Ek **stack of strings** banao.
2️⃣ Expression ko **right se left** traverse karo (Prefix ka rule).
3️⃣ Agar character ek **digit** hai:
    ➤ usse string me convert karke stack me push karo.
4️⃣ Agar character ek **operator** hai (+, -, *, /):
    ➤ Stack ke top ke do values nikaalo (v1, v2)
    ➤ Ek string banao: v1 + v2 + operator (Postfix format)
    ➤ Is result string ko stack me push karo
5️⃣ End me stack ka top element hi final postfix expression hoga.

🔍 Dry Run Example:
Prefix: -/*+79483

➡️ Traverse from right:
Push '3'
Push '8'
Push '4'
Push '9'
Push '7'
'+' => "7" + "9" + '+' ➝ "79+"
'*' => "79+" + "4" + '*' ➝ "79+4*"
'/' => "79+4*" + "8" + '/' ➝ "79+4*8/"
'-' => "79+4*8/" + "3" + '-' ➝ "79+4*8/3-"

📤 Output: 79+4*8/3-

📈 TIME COMPLEXITY:
➡️ O(n) – Har character ko ek hi baar process kiya ja raha hai

📦 SPACE COMPLEXITY:
➡️ O(n) – Stack me maximum n elements ho sakte hain

🔄 FLOWCHART (ASCII Style - Hinglish):

         +-------------------------+
         |      Start Program      |
         +-------------------------+
                    |
                    v
     +-----------------------------+
     | Traverse string from right  |
     +-----------------------------+
                    |
           +--------+--------+
           |                 |
     +-----v----+     +------v-----+
     | Is digit? |     | Is operator? |
     +----------+     +--------------+
           |                 |
         Yes               Yes
           |                 |
+----------------+    +---------------------------+
| Push to stack  |    | Pop 2 elements (v1, v2)   |
+----------------+    | Create: v1 + v2 + oper    |
                      | Push result back to stack |
                      +---------------------------+
                    |
                    v
            +---------------+
            | End of loop?  |
            +---------------+
                    |
                   Yes
                    |
            +--------------------+
            | Print stack.top()  |
            +--------------------+
                    |
                    v
               +----------+
               |   END    |
               +----------+

-------------------------------------------------------------------
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

// 👉 Ye function do operands aur operator leta hai aur unhe Postfix form me jod kar return karta hai
string solve(string v1, string v2, char oper){
    string s = "";
    s += v1;            // pehla operand
    s += v2;            // doosra operand
    s.push_back(oper);  // operator ko last me add karo (Postfix rule)
    return s;           // final postfix expression return karo
}

int main(){
    string s = "-/*+79483"; // ✅ Example prefix expression
    stack<string> val;      // 🔁 Stack to store intermediate postfix expressions

    // 🔄 Traverse prefix string from right to left
    for(int i = s.length() - 1; i >= 0; i--){
        int ascii  = (int)(s[i]);

        // 🔢 Agar current character ek digit hai (0-9)
        if(ascii >= 48 && ascii <= 57){
            // ➕ Char ko number string me convert karo aur push karo
            val.push(to_string(ascii - 48)); // '7' ➝ 55 ➝ 55 - 48 = 7
        }
        else{
            // 🔣 Agar operator mila (+, -, *, /)
            string v1 = val.top(); val.pop(); // 🔽 Pehla operand nikaalo
            string v2 = val.top(); val.pop(); // 🔽 Doosra operand nikaalo
            string result = solve(v1, v2, s[i]); // 🔧 Postfix banaye
            val.push(result); // 🔙 Stack me push karo
        }
    }

    // ✅ Final result stack ke top me hoga
    cout << "Postfix Expression: " << val.top() << endl;

    return 0;
}

/*
🟢 OUTPUT:
Postfix Expression: 79+4*8/3-

📝 Explanation:
Prefix Expression "-/*+79483" ko Postfix me convert kiya gaya:
1. + ➝ 7+9 ➝ 79+
2. * ➝ 79+ * 4 ➝ 79+4*
3. / ➝ 79+4* / 8 ➝ 79+4*8/
4. - ➝ 79+4*8/ - 3 ➝ 79+4*8/3-

✅ Final Postfix: 79+4*8/3-

📊 Time Complexity: O(n)
📦 Space Complexity: O(n)
*/
