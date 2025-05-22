
#include<bits/stdc++.h>
using namespace std;
/*
*******************************************************
* 💡 समस्या का समाधान: Prefix Sum Method
*   - दिए गए array `nums` में से किसी भी range `[left, right]`
*     का sum निकालना है।
*   - हर बार sum निकालने की बजाय, एक prefix sum array (`pre[]`)
*     बनाएंगे, ताकि हम **O(1) में** उत्तर निकाल सकें।
*
* 🎯 Prefix Sum logic:
*   - `pre[i]` store करेगा `nums[0]` से `nums[i]` तक का sum।
*   - इस तरह से, अगर हमें `[left, right]` का sum चाहिए, तो:
*     🔹 अगर `left == 0`, तो `pre[right]` return करें।
*     🔹 अन्यथा, `pre[right] - pre[left-1]` return करें।
*
* ⏳ टाइम कॉम्प्लेक्सिटी:
*   - **Prefix Sum बनाना:** O(n)
*   - **हर query का उत्तर:** O(1)
*
*******************************************************
*/

class NumArray {
    public:
        vector<int> pre;  // 📌 Prefix sum array बनाएँ
    
        // 🔹 Constructor: Prefix sum array तैयार करें
        NumArray(vector<int>& nums) {
            int n = nums.size();  // 📌 Array का size पता करें
            pre.resize(n);        // 📌 Prefix sum array को resize करें
            
            // 🟢 पहले element को initialize करें
            pre[0] = nums[0];
    
            // 🟢 बाकी prefix sum बनाएँ
            for (int i = 1; i < n; i++) {
                pre[i] = nums[i] + pre[i - 1];  // `pre[i]` = `nums[i]` + `pre[i-1]`
            }
        }
        
        // 🔹 किसी भी range [left, right] का sum return करें
        int sumRange(int left, int right) {
            // 🟢 अगर left = 0 है, तो pre[right] return करें
            if (left == 0) return pre[right];
            
            // 🟢 अन्यथा, pre[right] - pre[left-1] return करें
            return pre[right] - pre[left - 1];
        }
    };
    
    /**
     * 🎯 इस class को ऐसे use करें:
     *
     *  vector<int> nums = {1, 2, 3, 4, 5};  // Example array
     *  NumArray* obj = new NumArray(nums);  // Prefix Sum Object बनाएँ
     *  
     *  cout << obj->sumRange(1, 3);  // 🔹 Output: 2 + 3 + 4 = 9
     *  cout << obj->sumRange(0, 2);  // 🔹 Output: 1 + 2 + 3 = 6
     */
    