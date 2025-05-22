#include<bits/stdc++.h>
using namespace std;
/*
🌧️ PROBLEM: Trapping Rain Water

🧠 LOGIC IN HINGLISH:

Imagine karo tumhare paas ek array hai jo buildings ki height batata hai.
Har building ke beech mein pani trap ho sakta hai agar:

1️⃣ Uske left mein koi building high hai
2️⃣ Aur uske right mein bhi koi building high hai

📦 Jaise Example:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Yahan pe kuch buildings ke beech mein pani ruk sakta hai.
Hume calculate karna hai ki total kitna pani trap hoga.

💡 Key idea: Kisi position `i` pe kitna pani rukega:
    water[i] = min(maxLeft, maxRight) - height[i]

min(maxLeft, maxRight): dono side ke tallest building me se choti
                        height choose karni padegi
height[i]: current building ki height

👣 STEPS:

1. Har building ke LEFT me jo sabse bada height hai (preGreat[])
2. Har building ke RIGHT me jo sabse bada height hai (nextGreat[])
3. In dono me se min nikalo (mini[])
4. Agar mini[i] > height[i] ho to pani trap hoga us index pe
   pani = mini[i] - height[i]

⚙️ TIME COMPLEXITY:
- O(n) where n = number of buildings (height array ka size)
- Kyuki hum 3 baar array traverse kar rahe hain: 
  - preGreat, nextGreat and water calculation

🧭 FLOW CHART (HINGLISH):

              Start
                |
             height[] input
                |
            Initialize preGreat[]
                |
            Traverse from left ➡️
                |
          Fill preGreat[i] = max so far
                |
            Initialize nextGreat[]
                |
            Traverse from right ⬅️
                |
          Fill nextGreat[i] = max so far
                |
        Calculate mini[i] = min(left, right)
                |
        Traverse and trap pani if possible
                |
             Add trapped water
                |
               Output
                |
              THE END

Now let's write the code below ⬇️
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); // 🧱 Total number of buildings
        if (n == 0) return 0;  // ⚠️ Edge case: Empty array, no water can be trapped

        // Step 1️⃣: Calculate Previous Greatest (Left max)
        int max = height[0];  // Starting max
        vector<int> preGreat(n);  // 🪜 Stores left side ka max for each index
        preGreat[0] = -1;  // First building has no one on the left

        for (int i = 1; i < n; i++) {
            preGreat[i] = max; // Ab tak ka max left se
            if (max < height[i]) max = height[i]; // Update max if current is greater
        }

        // Step 2️⃣: Calculate Next Greatest (Right max)
        vector<int> nextGreat(n);  // 🪜 Stores right side ka max for each index
        nextGreat[n - 1] = -1;  // Last building has no one on right
        int nmax = height[n - 1];  // Start from right end

        for (int i = n - 2; i >= 0; i--) {
            nextGreat[i] = nmax;  // Ab tak ka max right se
            if (nmax < height[i]) nmax = height[i];  // Update max
        }
 
        // Step 3️⃣: Minimum of left and right max
        vector<int> mini(n);  // Store min(preGreat, nextGreat)
        for (int i = 0; i < n; i++) {
            mini[i] = min(preGreat[i], nextGreat[i]); // Choose smaller wall
        }

        // Step 4️⃣: Calculate water trapped
        int water = 0;
        for (int i = 1; i < n - 1; i++) {  // First and last building can't trap water
            if (height[i] < mini[i]) {  // Pani sirf tab trap hoga jab current building choti ho
                water += (mini[i] - height[i]);  // Add trapped water
            }
        }

        return water;  // Return final trapped water
    }
};

/*
🎯 Example:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]

preGreat = [-1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3]
nextGreat= [3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1, -1]
mini     = [-1, 0, 1, 1, 2, 2, 2, 2, 2, 2, 1, -1]

Trapped water at i=2: 1-0 = 1
Trapped water at i=4: 2-1 = 1
...

Total trapped water = 6 units

⏱️ Time Complexity: O(n)
🧠 Space Complexity: O(n) for preGreat, nextGreat, and mini

💙 Happy Learning Coder! Tum kar loge! 💪
*/
