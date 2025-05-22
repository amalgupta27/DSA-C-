/*
🧠🔄 LOGIC OF "NEXT PERMUTATION" (HINGLISH MEIN):
------------------------------------------------------
Aapko ek array diya gaya hai, jaise: [1, 2, 3]
Next permutation ka matlab hota hai: 
    - is permutation se turant bada permutation jo lexicographically ho.
    
    Lexicographical ka matlab hota hai dictionary ke order mein.

💡 Example:
[1, 2, 3] → [1, 3, 2] → [2, 1, 3] → [2, 3, 1] → [3, 1, 2] → [3, 2, 1]
Toh agar input hai [1, 2, 3], toh output hoga [1, 3, 2]

🧭 Steps to solve:
1️⃣ Pehle "pivot" dhoondo — wo pehla number jahan se order girta hai (right to left se).
2️⃣ Agar pivot nahi mila (i.e., pura array decreasing hai), toh reverse kardo array.
3️⃣ Pivot ke baad ka part reverse kardo (isse wo part smallest ban jayega).
4️⃣ Pivot ke baad wale part me se ek number dhoondo jo pivot se bada ho, aur swap kardo.

🧾 Flow Chart (Hinglish):
----------------------------
1. Start
2. Find pivot: nums[i] < nums[i+1] from right
3. Agar nahi mila pivot:
       ↓
   Reverse pura array and END
4. Else:
    - Reverse part after pivot
    - Find next greater number after pivot
    - Swap pivot with that number
5. END

🕒 Time Complexity:
- Finding pivot: O(n)
- Reversing: O(n)
- Finding next greater and swapping: O(n)
=> Total = O(n)

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find pivot
        // Pivot is the first element from end which is smaller than its next element
        int idx = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: Agar pivot nahi mila - that means array is in descending order
        if(idx == -1) {
            // Example: [3,2,1] → reverse → [1,2,3]
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Reverse the part after pivot
        // Because after pivot, it's in descending, we want to make it as small as possible
        reverse(nums.begin() + idx + 1, nums.end());

        // Step 4: Find the next greater element than nums[idx] in the reversed part
        // Example: nums = [1,3,2], pivot idx = 0, find number > 1 in right part i.e. 2,3
        int j = -1;
        for(int i = idx + 1; i < n; i++) {
            if(nums[i] > nums[idx]) {
                j = i;
                break;
            }
        }

        // Step 5: Swap the pivot with next greater element
        // Example: [1,3,2] → swap 1 and 2 → [2,3,1]
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;

        return;
    }
};

/*
🔁 Example Dry Run:
-------------------
Input: [1, 2, 3]

Step 1: Find pivot:
    nums[1] = 2 < nums[2] = 3 → pivot idx = 1

Step 2: Reverse after pivot:
    reverse nums[2 to 2] → no change → [1, 2, 3]

Step 3: Find number > nums[1] = 2 → nums[2] = 3

Step 4: Swap nums[1] and nums[2] → [1, 3, 2]

Answer: [1, 3, 2]
*/
