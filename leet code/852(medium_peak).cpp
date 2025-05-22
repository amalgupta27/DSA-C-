// ✅ Problem: Find the peak index in a mountain array
// ✅ Mountain Array: Pahle increasing elements, ek peak, phir decreasing elements
// ✅ Example: arr = [1, 3, 5, 7, 6, 4, 2] → Peak = 7 at index 3

/*
----------------------------------
        📈 Flow Chart (Hinglish)
----------------------------------
Start
   ↓
Initialize lo = 1, hi = n-2
   ↓
Repeat while (lo <= hi):
     ↓
   Find mid = lo + (hi-lo)/2
     ↓
   If arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]:
         → Peak found → return mid
     ↓
   Else if arr[mid] > arr[mid+1]:
         → Peak left side mein → hi = mid - 1
     ↓
   Else
         → Peak right side mein → lo = mid + 1
   ↓
End Loop
↓
Return -1 (kabhi nahi hoga valid mountain array mein)
*/

#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 1; // ❗ lo = 1 kyunki index 0 kabhi peak nahi hoga (mountain array mein)
        int hi = arr.size() - 2; // ❗ hi = size-2 kyunki last index bhi peak nahi hoga

        // 🔍 Binary Search lagate hain to find peak efficiently
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // ➡️ mid find karte hain (overflow se bachne ke liye aise likhte hain)

            // 🏔️ Check: kya mid element dono side se bada hai?
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid; // ✅ Yahi peak hai, return kar do
            }
            // 🔽 Agar mid apne right wale se bada hai
            else if (arr[mid] > arr[mid + 1]) {
                hi = mid - 1; // 🧭 Peak left side mein hoga
            }
            // 🔼 Agar mid apne right wale se chhota hai
            else {
                lo = mid + 1; // 🧭 Peak right side mein hoga
            }
        }

        // ❌ Ye return theoretically kabhi nahi hona chahiye valid mountain array ke case mein
        return -1;
    }
};
