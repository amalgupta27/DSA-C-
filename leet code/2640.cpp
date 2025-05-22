/*
Logic (Hinglish):
Ek given array 'nums' di gayi hai, humein ek naya array 'res' banana hai.
Har element ke liye:
1. Ek prefix sum maintain karna hai jo pehle ke sare elements ka sum store kare.
2. Ek maxi variable maintain karna hai jo ab tak ka sabse bada element track kare.
3. Har index 'i' ke liye:
   - Maxi update karo agar nums[i] bada hai
   - res[i] ko calculate karo: nums[i] + maxi + res[i-1]

Example:
nums = [2, 1, 3]
Step 1: maxi = 2, res[0] = 2*2 = 4
Step 2: maxi = max(2,1) = 2, res[1] = 1 + 2 + 4 = 7
Step 3: maxi = max(2,3) = 3, res[2] = 3 + 3 + 7 = 13

Final Output: res = [4, 7, 13]

Flow Chart (Hinglish):
--------------------------------
Start
  |
  |---> Input 'nums' array
  |
  |---> Initialize maxi = 0
  |
  |---> Initialize res[0] = 2 * nums[0]
  |
  |---> Loop from i = 1 to n-1:
  |       |
  |       |---> maxi = max(maxi, nums[i])
  |       |
  |       |---> res[i] = nums[i] + maxi + res[i-1]
  |       |
  |       |---> Store result in res[]
  |
  |---> Print res[]
  |
End
--------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size(); // Array ka size nikalna
        vector<long long> res(n); // Ek n size ka vector res banaya jisme result store hoga
        
        res[0] = 2 * nums[0]; // Pehla element ka double store karna hai as per logic
        int maxi = nums[0]; // Maxi variable ko pehle element se initialize kiya jo max track karega
        /*
        Kyun nahi 0 se initialize kiya?
        - Agar hum maxi = 0 se start karte, toh pehle element ka comparison sahi nahi hota.
        - Maan lo nums[0] negative hota, toh max value ka calculation galat ho sakta tha.
        - maxi = nums[0] rakhne se shuru se hi first element ko sahi track karte hain.
        */
        
        for (int i = 1; i < n; i++) { // Loop chalana hai index 1 se last tak
            maxi = max(maxi, nums[i]); // Maxi ko update karna hai agar nums[i] bada hai
            res[i] = nums[i] + maxi + res[i - 1]; // Current element ka prefix score calculate karna hai
            /*
            Explanation:
            - res[i-1] tak ka prefix score add karna hai jo pehle ka sum hai.
            - maxi ab tak ka sabse bada element hai, isko add karna hai.
            - nums[i] current element hai, isko bhi add karna hai.
            - Is combination se har index ka cumulative score milta hai jo prefix aur maximum ka sum hai.
            */
        }
        return res; // Final result return karna
    }
};

// Driver Code
int main() {
    Solution obj; // Solution class ka object banaya
    vector<int> nums = {2, 1, 3}; // Input array define kiya
    vector<long long> result = obj.findPrefixScore(nums); // Function call kiya aur result store kiya
    
    cout << "Result: "; // Output ke liye print statement
    for (long long val : result) { // Loop chalayenge result array par
        cout << val << " "; // Har element ko print karenge
    }
    cout << endl; // New line ke liye
    
    return 0; // Program end
}
