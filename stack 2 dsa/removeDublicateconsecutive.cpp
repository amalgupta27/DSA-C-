#include<bits/stdc++.h>
using namespace std;

/*
👨‍🏫================= LOGIC IN HINGLISH =================👨‍🏫

👉 Question:
   Ek string di gayi hai jisme kuch characters repeat ho rahe hain consecutively.
   Hume **consecutive duplicates** ko hata kar ek nayi string banana hai.
   Lekin hume **stack** ka use karke karna hai.

🎯 Objective:
   "aaabbcddaabffg" ➝ "abcdabfg"

🧠 Idea:
   1. Stack ka use karenge.
   2. Pehla character stack me daal denge.
   3. Fir har character check karenge:
      ➤ Agar current character stack ke top se **alagalag** hai to push karo.
      ➤ Agar same hai to ignore kar do.
   4. Stack me jo bacha hoga use reverse karke final string banayenge
      (kyunki stack me reverse order me insert hota hai)

📊================= FLOWCHART (HINGLISH) =================📊

       +----------------------+
       |     Start            |
       +----------------------+
                 |
                 v
       +----------------------------+
       | Pehla char stack me daalo |
       +----------------------------+
                 |
                 v
       +----------------------------+
       | Loop chalao har character |
       +----------------------------+
                 |
                 v
       +----------------------------------------------+
       |  Agar current char ≠ stack top --> push karo |
       |  else --> skip karo                          |
       +----------------------------------------------+
                 |
                 v
       +------------------------------------+
       | Stack se pop karke string banao    |
       | (reverse kar do final result)      |
       +------------------------------------+
                 |
                 v
              Return answer

🕒 TIME COMPLEXITY:
   - O(n)  --> n is length of input string (har char ek baar visit hota hai)
   - Stack operations: O(1) each (push/pop)
==========================================
*/

string removeDublicate(string s){
    stack<char> st;

    // Step 1: Pehla character ko stack me push karna
    st.push(s[0]);

    // Step 2: Loop 2nd character se start karo
    for(int i = 1; i < s.size(); i++){
        // Agar current char ≠ stack ke top wale char se to stack me push karo
        if(s[i] != st.top())
            st.push(s[i]);
        // Agar same hai to kuch mat karo (skip karo)
    }

    // Step 3: Stack se reverse string banana
    s = ""; // nayi string banane ke liye purani string ko empty kar diya

    while(st.size() > 0){
        s += st.top();  // top character ko string me add karo
        st.pop();       // us character ko stack se hata do
    }

    // Stack me string ulta store hota hai, to use reverse karo
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string s = "aaabbcddaabffg";

    cout << "Original string: " << s << endl;

    s = removeDublicate(s); // function call to remove consecutive duplicates

    cout << "After removing consecutive duplicates: " << s << endl;

    return 0;
}
