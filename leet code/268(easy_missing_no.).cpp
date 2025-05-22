#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
        /*
        💡 Logic in Hinglish:
    
        Hume ek array diya gaya hai jisme numbers 0 se lekar n tak hone chahiye.
        Lekin ek number missing hai. Hume use find karna hai.
    
        Example:
        nums = [3, 0, 1]
        size = 3 → isliye numbers hone chahiye: [0, 1, 2, 3]
        Diya gaya: [0, 1, 3]
        Missing number: 2
    
        Hum 3 cases check karte hain:
        1️⃣ Agar first element 0 nahi hai → 0 missing hai
        2️⃣ Agar last element n nahi hai → n missing hai
        3️⃣ Beech ka number missing ho → check karo nums[i] != i
        */
    
        int missingNumber(vector<int>& nums) {
            // Step 1: Pehle array ko sort karo
            sort(nums.begin(), nums.end());
    
            int n = nums.size();  // array ka size nikal rahe
    
            // Case 1️⃣: Agar 0 missing hai
            if(nums[0] != 0) return 0;
    
            // Case 2️⃣: Agar n missing hai
            if(nums[n-1] != n) return n;
    
            // Case 3️⃣: Agar beech ka number missing hai
            for(int i = 1; i < nums.size(); i++) {
                // Agar index i par value i nahi hai → wahi missing hai
                if(nums[i] != i) {
                    return i;
                }
            }
    
            // Agar kuch bhi missing nahi mila (fallback case)
            return 0;
        }
    };
    