#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
    🔴🟡🔵 PROBLEM:
    Given an array 'nums' containing only 0s, 1s, and 2s,
    sort it in-place so that all 0s come first, then all 1s, then all 2s.

    Example:
    Input:  nums = [2, 0, 2, 1, 1, 0]
    Output: nums = [0, 0, 1, 1, 2, 2]

    🌈 Idea: Dutch Flag Algorithm
    Use 3 pointers: 
    👉 'l' for 0s (left side)
    👉 'mid' for current element
    👉 'h' for 2s (right side)
 
    Traverse the array with mid pointer:
    ----------------------------------
    Agar:
    nums[mid] == 0: Swap with nums[l] and increment both l and mid
    nums[mid] == 1: Just increment mid (1 already at correct place)
    nums[mid] == 2: Swap with nums[h] and decrement h

    Yeh logic ek pass me sab sahi jagah le aata hai!

    🧠 Flow Chart (in Hinglish):
    ---------------------------
                +----------------------+
                |  mid <= high ?       |
                +---------+------------+
                          |
                         YES
                          |
                          v
                +----------------------+
                | nums[mid] == 0 ?     |
                +----+-----------------+
                     |
                    YES
                     |
         +-----------v-------------+
         | Swap(nums[mid], nums[l])|
         | mid++, l++              |
         +-------------------------+
                     |
                    NO
                     |
           +---------v-------------+
           | nums[mid] == 2 ?      |
           +----+------------------+
                |
               YES
                |
      +---------v-------------+
      | Swap(nums[mid], nums[h]) |
      | h--                     |
      +-------------------------+
                |
               NO
                |
           +----v-----+
           | mid++    |
           +----------+

    🔁 Time Complexity: O(n)
    🔁 Space Complexity: O(1) (In-place sorting)
    */

    void sortColors(vector<int>& nums) {
        int l = 0;                  // Pointer for placing 0s (left boundary)
        int h = nums.size() - 1;   // Pointer for placing 2s (right boundary)
        int mid = 0;               // Current element being checked

        // Example: nums = [2, 0, 2, 1, 1, 0]
        // Goal:    nums = [0, 0, 1, 1, 2, 2]

        while (mid <= h) {
            if (nums[mid] == 0) {
                // ✅ 0 mila, toh left mein le jao
                // Swap current mid value with left pointer
                int temp = nums[mid];
                nums[mid] = nums[l];
                nums[l] = temp;
                l++;    // 0 sahi jagah chala gaya
                mid++;  // next element dekhne chalo
            }
            else if (nums[mid] == 2) {
                // ✅ 2 mila, toh right mein bhejo
                // Swap current mid value with right pointer
                int temp = nums[mid];
                nums[mid] = nums[h];
                nums[h] = temp;
                h--;    // 2 sahi jagah chala gaya
                // mid++ nahi karte kyunki swapped value check karni hai
            }
            else {
                // ✅ 1 mila, already sahi jagah par hai
                mid++;  // bas aage badho
            }

            // Har iteration ke baad nums ka state dekh sakte ho debugging ke liye
            // (optional) e.g., cout << nums[mid] << " ";
        }
    }
};

// Method 2
// int noz=0;
        // int noo=0;
        // int notw=0;
        // for(int i=0; i<=nums.size()-1;i++){
        //     if(nums[i]==0) noz++;
        //     else if(nums[i]==1) noo++;
        //     else notw++;
        // }
        // for(int i=0; i<=nums.size()-1;i++){
        //     if(i<noz) nums[i]=0;
        //     else if(i<noz+noo ) nums[i]=1;
        //     else nums[i]=2;
            
        // }