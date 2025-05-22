#include <bits/stdc++.h>
using namespace std;

/*
==============================
👀 Can See Persons Count Problem (HINGLISH EXPLANATION) 👀
==============================

👨‍🏫 Question:
Aapko ek array diya gaya hai jisme har element ek person ki height ko dikhata hai.
Aapko batana hai har person kitne logon ko dekh sakta hai apne right side me.

📦 Input: [10, 6, 8, 5, 11, 9]
🎯 Output: 3 1 2 1 1 0

🧠 Idea:
- Har person ke liye hum uske right me dekhte hain jab tak koi usse chhota person ho,
  agar bada mila toh usko bhi dekh sakta hai par woh block kar dega.

➡️ Stack use karte hain right se left iterate karke:
   - Jab tak current person se chhoti height mile, pop karte hain aur count badhate hain.
   - Agar ek bada mila toh usko bhi count me lete hain kyunki woh visible hota hai.

=============================
📊 FLOWCHART (HINGLISH) 📊
=============================

            +----------------------+
            |     Start Program    |
            +----------------------+
                       |
                       v
            +----------------------------+
            |  Right to Left Traverse    |
            +----------------------------+
                       |
                       v
            +--------------------------------------+
            |  Stack se chhote elements pop karo   |
            +--------------------------------------+
                       |
                       v
            +--------------------------------------+
            |  Agar bada mila toh count++          |
            +--------------------------------------+
                       |
                       v
            +----------------------------+
            |  Current height push karo  |
            +----------------------------+
                       |
                       v
            +------------+
            |   Return   |
            +------------+

=============================
⏱️ Time Complexity: O(n)
🧠 Space Complexity: O(n) (stack ke liye)
=============================

📈 Example:
Input: [10, 6, 8, 5, 11, 9]

Index     : 0   1   2   3   4   5
Height    : 10  6   8   5  11  9
Output    :  3   1   2   1   1   0

Visual Explanation for index 0 (10):
- Dekh sakta hai: 6 (smaller), 8 (smaller), 11 (greater => visible but blocks view) => total = 3
*/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n= arr.size();
        vector<int> ans(n,0);
        stack<int> st;

        // Last person can see no one to the right
        st.push(arr[n-1]);
        ans[n-1]=0;

        // Traverse from right to left
        for(int i=n-2; i>=0;i--){
            int count =0;

            // Step 1: Jab tak current height se chhoti height mil rahi hai, pop karo and count++
            while(st.size()>0 && st.top()<arr[i]){
                st.pop();
                count++;
            }

            // Step 2: Agar koi bada ya barabar mila (matlab stack non-empty), usko bhi dekh sakte ho
            if(st.size()!=0) count++; // VIMP: because bada ya equal height dikhega but block karega

            // Step 3: Count assign karo
            ans[i]=count;

            // Step 4: Current height ko stack me daalo
            st.push(arr[i]);
        }

        return ans;
    }
};