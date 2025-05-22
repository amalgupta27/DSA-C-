#include<bits/stdc++.h>
using namespace std;
/*
🔍 Problem Statement Explanation in Hinglish:

Aapke paas do arrays hain:
 
1. students[] → Queue of students jahan:
   - 0 = student wants square sandwich
   - 1 = student wants circular sandwich

2. sandwiches[] → Stack of sandwiches (0 on top = square, 1 = circle)

Rules:
- Student front se aayega aur top sandwich check karega.
- Agar uski pasand ka hai → sandwich le jaata hai (queue & sandwich dono se hat jaata hai)
- Agar nahi pasand → woh queue ke end mein chala jaata hai.

Ye tab tak repeat hota hai jab:
- Sab students ko sandwich mil jaata hai, ya
- Kisi bhi student ne sandwich lena band kar diya ho.

🧠 Example:
students = [1, 1, 0, 0]
sandwiches = [0, 1, 0, 1]

→ student(1) ≠ sandwich(0) → back mein
→ student(1) ≠ sandwich(0) → back mein
→ student(0) == sandwich(0) → mil gaya!
→ student(0) ≠ sandwich(1) → back mein
→ student(1) == sandwich(1) → mil gaya!
→ student(0) == sandwich(0) → mil gaya!
→ student(1) ≠ sandwich(1) → back mein
→ student(1) == sandwich(1) → mil gaya!

✅ Sabko sandwich mil gaya → return 0

🧭 Flow Chart (Hinglish):

               +------------------------+
               |  Kya queue empty hai?  |
               +------------------------+
                          |
                         No
                          |
                +------------------------+
                |  Front student sandwich  |
                |     se match karta hai?  |
                +------------------------+
                      /         \
                   Yes           No
                    |             |
        +-------------------+   +-----------------------------+
        |  student & sandwich|   |  student ko end mein bhejo |
        |      remove karo   |   |   count++; agar count==q.size |
        |    i++; count=0    |   |      to loop break karo     |
        +-------------------+   +-----------------------------+

🕒 Time Complexity:
- Worst case: O(n^2)
  Kyunki har student maximum n baar queue mein wapas aa sakta hai
  agar sandwich nahi mila ho.

Return:
- Queue mein jitne students bache hain woh return kar do → unko sandwich nahi mila.
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        for(int i=0; i<n;i++){
           q.push(students[i]);
        }

        int i= 0; // to traverse the sandwiches vector
        int count =0; // not let to go in infinite loop

        // Jab tak queue mein students hain aur count != queue size (infinite loop se bachne ke liye)
        while(q.size()>0 && count!=q.size()){
            if(q.front()==sandwiches[i]){
                // Agar student ki pasand ka sandwich mila
                count= 0;      // Reset the no-match count
                q.pop();       // student and sandwich dono hatao
                i++;           // next sandwich pe jaao
            }
            else{
                // Agar pasand nahi aaya sandwich
                q.push(q.front()); // student ko queue ke end mein bhejo
                q.pop();           // front se hatao
                count++;           // count increase karo

                // Agar ek full round ho gaya aur koi bhi student ne sandwich nahi liya
                // to iska matlab koi aur sandwich nahi milega → loop break ho jaayega
            }
        }

       return q.size(); // jitne students bache hain → unko sandwich nahi mila
    }
};
