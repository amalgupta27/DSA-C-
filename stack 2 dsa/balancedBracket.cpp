#include<iostream>
#include<stack>
using namespace std;

/*
👨‍🏫================= LOGIC IN HINGLISH =================👨‍🏫

👉 Question: Ek string di gayi hai jisme sirf '(' aur ')' brackets hain.
   Hume check karna hai ki ye brackets balanced hain ya nahi.

👉 Balanced ka matlab:
   1. Har opening bracket '(' ka ek matching closing bracket ')' hona chahiye.
   2. Order sahi hona chahiye — pehle open ho fir close ho.

🔍 Example:
    s = "()()()"  --> Balanced ✅
    s = "(()())"  --> Balanced ✅
    s = "(()"     --> Not Balanced ❌
    s = "())("    --> Not Balanced ❌

🤖 Hum stack ka use karenge:
    - Jab '(' mile to stack me daalenge.
    - Jab ')' mile to check karenge ki stack empty to nahi,
      agar nahi hai to ek '(' pop kar denge.
    - Agar kisi waqt ')' mile aur stack empty ho to ➡️ Not balanced
    - Loop ke baad agar stack empty hai to ➡️ Balanced ✅

📊================= FLOWCHART (IN HINGLISH) =================📊

       +----------------------+
       |  Start               |
       +----------------------+
                 |
                 v
       +----------------------+
       |  Stack banao         |
       +----------------------+
                 |
                 v
       +-------------------------------+
       |  Loop chalao har character pe |
       +-------------------------------+
                 |
                 v
       +--------------------------------------+
       |  Agar '(' mila to stack me push karo |
       +--------------------------------------+
                 |
                 v
       +-------------------------------------------------+
       |  Agar ')' mila to check karo stack empty hai?   |
       +-------------------------------------------------+
         |                             |
         |                             v
         |                      +----------------------+
         |                      |  Stack empty?        |
         |                      |  --> Return false    |
         |                      +----------------------+
         |                             |
         |                             v
         |                      Stack se pop karo
         v
       Loop complete hone ke baad
                 |
                 v
       +-------------------------------+
       |  Stack empty?                 |
       |  --> Yes: return true         |
       |  --> No: return false         |
       +-------------------------------+

🕒 TIME COMPLEXITY:
   - O(n)  --> n is length of string (1 loop lagta hai)
   - Stack operations push/pop take O(1) time each

==========================================
*/

bool isBalanced(string s){
    // Agar string ki length odd hai to balanced nahi ho sakti
    if(s.length() % 2 != 0) return false;

    stack<char> st; // stack banaya jisme hum '(' store karenge

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            // Agar current character '(' hai to stack me push karo
            st.push('(');  // ya st.push(s[i]) bhi likh sakte ho
        }
        else{ // agar ')' mila
            if(st.size() == 0){
                // Agar stack already empty hai to koi matching '(' nahi mila
                return false; // iska matlab string invalid hai
            }
            else{
                st.pop(); // ek matching '(' hata do
            }
        }
    }

    // Loop ke baad agar stack empty hai to sab brackets match hue
    if(st.size() == 0) return true;
    else return false; // stack me agar koi '(' bacha hai to unbalanced
}

int main(){
    string s = "()()()";  // Test case: balanced string ✅
    cout << isBalanced(s) << endl; // Output: 1 (true)
}
