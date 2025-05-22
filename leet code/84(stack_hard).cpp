#include<bits/stdc++.h>
using namespace std;
/*
👨‍🏫==================== LARGEST RECTANGLE IN HISTOGRAM ====================👨‍🏫

🔎 Problem:
Ek histogram diya gaya hai (array of heights). Hume usme sabse bada rectangular area nikalna hai jo kisi bar ke upar ban sakta hai.

📦 Example:
arr = [2, 1, 5, 6, 2, 3]
Largest rectangle area = 10 (between heights 5 and 6)

🧠 Idea:
- Har bar ke liye uska left (Previous Smaller Index - PSI) aur right (Next Smaller Index - NSI) chhoti height kaha hai, ye pata karo.
- Us range me rectangle banega → Breadth = NSI - PSI - 1
- Area = height * breadth
- Har bar ke liye aisa area nikal ke max lo.

🔄 Flow Chart (Hinglish):

       +------------------+
       |     Start        |
       +------------------+
               |
               v
 +------------------------------+
 | NSI (Next Smaller Index)     |
 | Right se left traverse karo  |
 | Stack se chhote element pop  |
 +------------------------------+
               |
               v
 +------------------------------+
 | PSI (Previous Smaller Index) |
 | Left se right traverse karo  |
 | Stack se chhote element pop  |
 +------------------------------+
               |
               v
 +-------------------------------------------+
 | For each bar:                             |
 |   Area = height * (NSI - PSI - 1)         |
 |   maxArea = max(maxArea, area)            |
 +-------------------------------------------+
               |
               v
            Print maxArea

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)
==================================================================
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsi(n); // Next Smaller Index (right boundary)
        stack<int> st;
        nsi[n - 1] = n; // Last element ka right smaller to end hoga
        st.push(n - 1);

        // NSI calculation (Right se left)
        for (int i = n - 2; i >= 0; i--) {
            // Jab tak stack top ka element bada ya barabar hai, hatao
            while (st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();

            // Agar stack empty ho gaya toh right end tak koi chhota nahi mila
            if (st.size() == 0) nsi[i] = n;
            else nsi[i] = st.top(); // pehla chhota element
            st.push(i);
        }

        vector<int> psi(n); // Previous Smaller Index (left boundary)
        psi[0] = -1; // First element ke left me kuch nahi
        stack<int> gt;
        gt.push(0);

        // PSI calculation (Left se right)
        for (int i = 1; i <= n - 1; i++) {
            while (gt.size() > 0 && arr[gt.top()] >= arr[i]) gt.pop();
            if (gt.size() == 0) psi[i] = -1;
            else psi[i] = gt.top();
            gt.push(i);
        }

        int maxArea = 0;

        // Har bar ke liye area calculate karo
        for (int i = 0; i < n; i++) {
            int height = arr[i];
            int breadth = nsi[i] - psi[i] - 1; // Width = right - left - 1
            int area = height * breadth;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
