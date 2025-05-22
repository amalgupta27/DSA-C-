#include<bits/stdc++.h>
using namespace std;
/*
🧠 Question: Merge Sorted Arrays

➡️ Aapke paas do sorted arrays hain:
   - `nums1` of size m + n, jisme pehle `m` elements valid hain, baaki jagah khaali hai (0s hote hain ya reserved space)
   - `nums2` of size `n`

➡️ Aapko `nums2` ke elements ko `nums1` me hi merge karna hai, lekin dono ka order sorted hi rehna chahiye.

✅ Constraint:
- Aapko ye kaam in-place karna hai (extra space nahi lena)
- `nums1` me hi final sorted output chahiye

----------------------------------------------------
🔁 Flow Chart (Hinglish in ASCII Style):

     i = m-1          j = n-1             k = m+n-1
nums1 = [1,2,3,_,_,_] nums2 = [2,5,6]

Step-by-step comparison:

1. Compare nums1[i] vs nums2[j]
2. Jo bada ho, usko nums1[k] me daalo
3. i ya j ko update karo, and k ko har bar decrease karo
4. Repeat jab tak i >= 0 && j >= 0
5. Agar nums2 me elements bache ho (j >= 0), unhe nums1 me daalo

📌 Important:
- nums1 ke bache hue elements ko move karne ki zarurat nahi hoti, kyunki wo already correct jagah pe hote hain.
----------------------------------------------------

🧪 Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output:
nums1 = [1,2,2,3,5,6]
----------------------------------------------------
*/

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;           // nums1 ke valid elements ka last index
            int j = n - 1;           // nums2 ka last index
            int k = m + n - 1;       // nums1 ka total last index (including empty spaces)
    
            // 🧠 Back se compare karke merge karte hain
            while (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k] = nums1[i]; // agar nums1 ka element bada hai to usi ko end me daal do
                    i--;                 // nums1 ka index ek kam karo
                } else {
                    nums1[k] = nums2[j]; // agar nums2 ka element bada ya barabar hai to use daalo
                    j--;                 // nums2 ka index ek kam karo
                }
                k--; // har baar daalne ke baad last index ko kam karo
            }
    
            // ✅ Agar nums2 me elements bache ho to unhe daalo
            //"Agar nums2 ke elements abhi bhi baaki hain, to unko nums1 ke bache hue last positions me daal do."
            while (j >= 0) {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
    
            // 🧘‍♂️ Note: nums1 ke elements already correct jagah pe hote hain
        }
    };
    