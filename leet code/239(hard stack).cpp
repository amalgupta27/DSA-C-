#include<bits/stdc++.h>
using namespace std;
/*
==================== PROBLEM: MAX SLIDING WINDOW ====================

🧠 Question ka Matlab (Hinglish me):
Ek array diya gaya hai aur ek window size 'k'. 
Tumhe har window (yaani k consecutive elements) ka maximum element nikalna hai.
Har bar window 1 step aage move karegi (sliding window).

Example:
arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

Sliding Windows & Their Maximum:
1. [1, 3, -1] => max = 3
2. [3, -1, -3] => max = 3
3. [-1, -3, 5] => max = 5
4. [-3, 5, 3] => max = 5
5. [5, 3, 6] => max = 6
6. [3, 6, 7] => max = 7

👉 Output = [3, 3, 5, 5, 6, 7]

---------------------------------------------------------------------
💡 Optimized Soch:
Naive way: Har window ke liye max nikalo (O(n*k)) ❌ TLE aayega

Optimized way: Use karo **Next Greater Index (NGI)** approach with a stack.

Yeh NGI batata hai ki kisi index ke baad pehla bada element kahaan hai.

---------------------------------------------------------------------
📊 Flow Chart in Hinglish (ASCII-Art Style):

               +-----------------------------+
               | 1. Traverse array right to left |
               +-----------------------------+
                          |
                          v
              +---------------------------+
              | Stack se chhote ya equal    |
              | elements hatao             |
              +---------------------------+
                          |
                          v
              +---------------------------+
              | NGI[i] = index of next      |
              | greater element (or -1)   |
              +---------------------------+
                          |
                          v
              +-----------------------------+
              | 2. Use NGI to find max in   |
              | each sliding window        |
              +-----------------------------+
                          |
                          v
               +--------------------------+
               | Final Answer banega     |
               +--------------------------+

---------------------------------------------------------------------
⏱️ Time Complexity:
- NGI banane me: O(n)
- Har index ek baar hi traverse hoga: O(n)
🔁 Total: O(n) ✅
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        if (k == 1) return arr;

        int n = arr.size();
        vector<int> ngi(n);   // NGI = Next Greater Index
        stack<int> st;        // Stack to find NGI

        // ------------------ Step 1: Create NGI Array ------------------

        // Traverse from right to left to find next greater index for each element
        for (int i = n - 1; i >= 0; i--) {
            // Remove all elements from stack which are <= current element
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // NGI[i] will be top of stack or -1 if stack is empty
            ngi[i] = st.empty() ? -1 : st.top();

            // Push current index into the stack
            st.push(i);
        }

        // Example: arr = [1, 3, -1, -3, 5]
        // NGI[]  = [1, 4, 4, 4, -1]  => arr[1]=3, arr[4]=5

        // ------------------ Step 2: Sliding Window Logic Using NGI ------------------

        vector<int> ans;  // Final answer array
        int j = 0;        // Pointer to track max in current window

        for (int i = 0; i <= n - k; i++) {
            // Make sure j is inside the current window
            if (j < i) j = i;

            // Use NGI to jump to next greater element till it goes outside window
            while (ngi[j] != -1 && ngi[j] < i + k) {
                j = ngi[j];
            }

            // j now points to max element in current window
            ans.push_back(arr[j]);
        }

        // Dry Run for arr = [1,3,-1,-3,5,3,6,7], k = 3:
        // i=0 → window=[1,3,-1] → j=1 → max=3
        // i=1 → window=[3,-1,-3] → j=1 → max=3
        // i=2 → window=[-1,-3,5] → j=4 → max=5
        // i=3 → window=[-3,5,3] → j=4 → max=5
        // i=4 → window=[5,3,6] → j=6 → max=6
        // i=5 → window=[3,6,7] → j=7 → max=7

        return ans;
    }
};

/*
🌟 OUTPUT for arr = [1,3,-1,-3,5,3,6,7], k = 3:
👉 Output: [3, 3, 5, 5, 6, 7]
*/

// Another method
// time limit exceed
        // vector<int> ans;
        // int n = arr.size();
        // for(int i=0;i<n-k+1;i++){
        //     int mx = INT_MIN;
        //     for(int j=i; j<i+k; j++){
        //         mx =max(mx ,arr[j]);
        //     }
        //     ans.push_back(mx);
        // }
        // return ans;

