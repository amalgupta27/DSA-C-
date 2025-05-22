#include <vector>
#include <iostream>
using namespace std;
/*
******************************************************
* 📌 इस कोड का उद्देश्य: Pivot Index खोजना
*
* 🔹 दिया गया: एक array `nums[]`
* 🔹 हमें वह `index` ढूंढना है जहाँ:
*      `leftSum == rightSum`
*
* 🎯 हमारी Approach:
*   1️⃣ सबसे पहले, पूरे array का **total sum** निकालो।
*   2️⃣ हर index `i` पर:
*       🔸 rightSum निकालो → `totalSum - leftSum - nums[i]`
*       🔸 अगर `leftSum == rightSum` तो वही **pivot index**
*       🔸 leftSum को update करते जाओ।
*   3️⃣ अगर कोई pivot index नहीं मिला, तो **-1 return** करो।
*
* ⏳ Complexity:
*   - **O(n) time**, **O(1) space**
******************************************************
*/

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int n = nums.size();  // 🔹 Array का size (कितने elements हैं)
            int leftSum = 0, totalSum = 0;  // 🔹 Left sum और total sum को 0 से शुरू करें
            
            // 🔹 Step 1: पूरा `totalSum` निकालें (array के सभी elements का योग करें)
            for (auto x : nums) totalSum += x;
    
            // 🔹 Step 2: हर index पर rightSum निकालें और check करें
            for (int i = 0; i < n; i++) {
                int rightSum = totalSum - leftSum - nums[i];  // 📌 Right sum निकालें
                
                // ✅ अगर leftSum == rightSum, तो pivot index मिल गया
                if (leftSum == rightSum) {
                    return i;  
                }
                
                // 🔹 leftSum को update करें (अगले index के लिए)
                leftSum += nums[i];
            }
    
            // ❌ कोई pivot index नहीं मिला, तो -1 return करें
            return -1;
        }
    };
    
    /**
     * 🎯 इस class को ऐसे use करें:
     *
     *  vector<int> nums = {1, 7, 3, 6, 5, 6};  // Example array
     *  Solution obj;
     *  
     *  cout << obj.pivotIndex(nums);  // 🔹 Output: 3
     */
    