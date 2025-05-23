#include<bits/stdc++.h>
using namespace std;
/* 
-----------------------------------------
💡 Problem: 3Sum (Triplets with Sum Zero)
-----------------------------------------

👀 Aapko ek array diya gaya hai, aapko usme se aise unique triplet dhoondhne hain 
jinka sum 0 ho. Har triplet mein 3 alag-alag elements hone chahiye.

Example: 
Input: nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]

--------------------------------------------------
🔍 Logic Samjho (Step-by-step in Hinglish with Diagram)
--------------------------------------------------

1. Pehle array ko sort kar lo → Isse duplicates handle karna easy ho jata hai.
2. Har element ko fix karo ek outer loop ke through.
3. Uske baad two-pointer technique lagao baaki do elements dhoondhne ke liye.
4. Agar sum == 0 → valid triplet → store kar lo
5. Agar sum < 0 → left pointer aage badhao (sum badhega)
6. Agar sum > 0 → right pointer peeche lao (sum ghatega)
7. Duplicate values ko skip karo taaki repeat na ho

----------------------------
🧠 ASCII Flowchart (Hinglish)
----------------------------

                   +-------------------------+
                   |   Array ko sort karo    |
                   +-------------------------+
                              |
                              v
                   +-------------------------+
                   |  Har element fix karo   | <---- outer loop
                   +-------------------------+
                              |
                              v
                  +---------------------------------+
                  | Left = i+1, Right = end of array|
                  +---------------------------------+
                              |
                              v
                    +-----------------------+
                    | Sum = nums[i] + L + R |
                    +-----------------------+
                     /       |         \
                    /        |          \
                sum<0    sum==0      sum>0
                  |         |            |
                  v         v            v
           L++ (aage badho) |     R-- (peeche jao)
                            |
                    Save triplet & skip duplicates

----------------------------------
⏱️ Time Complexity:
----------------------------------
1. Sorting → O(n log n)
2. Outer loop + Two pointers → O(n^2)
Total = O(n^2)

*/

class Solution {  
public:
    vector<vector<int>> threeSum(vector<int>& nums) {  
        // Step 1: Sort kar lo input array ko
        sort(nums.begin(), nums.end());  

        // Step 2: Result vector jo final triplets store karega
        vector<vector<int>> result;

        // Step 3: Har element ko fix karte hue triplets dhoondho
        for (int i = 0; i < nums.size(); i++) {

            // Step 4: Duplicate element ko skip karo (taaki same triplet na aaye)
            if (i > 0 && nums[i] == nums[i - 1]) continue; 

            // Step 5: Do pointer set karo: ek left (i+1) se, ek right (end se)
            int l = i + 1;   
            int r = nums.size() - 1;

            // Step 6: Jab tak left < right
            while (l < r) { 
                int sum = nums[i] + nums[l] + nums[r];  // Teeno ka sum nikaalo

                if (sum > 0) {
                    // Sum zyada hai, right pointer ko peeche le jao
                    r--;  
                } 
                else if (sum < 0) {
                    // Sum kam hai, left pointer aage le jao
                    l++;  
                } 
                else {  
                    // Sum 0 hai → valid triplet mil gaya
                    result.push_back({nums[i], nums[l], nums[r]});

                    // Step 7: Left pointer ke duplicate skip karo
                    while (l < r && nums[l] == nums[l + 1]) l++;  
                    
                    // Step 8: Right pointer ke duplicate skip karo
                    while (l < r && nums[r] == nums[r - 1]) r--;  

                    // Step 9: Dono pointers move karo taaki naye pair mile
                    l++;  
                    r--;  
                }
            }
        }

        // Step 10: Final list of unique triplets return karo
        return result;
    }
};

/*
---------------------------------------------------
🧪 Example Dry Run:
---------------------------------------------------
Input: nums = [-1, 0, 1, 2, -1, -4]

1. Sorted: [-4, -1, -1, 0, 1, 2]
2. Fix -4 → No pair makes sum 0
3. Fix -1 → pairs (-1, 2) and (0, 1) → valid
4. Skip duplicate -1
5. Fix 0 → no pair with sum 0
6. Continue...

Output:
[[-1, -1, 2], [-1, 0, 1]]
*/
