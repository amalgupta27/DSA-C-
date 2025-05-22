#include<iostream>
#include<vector>
using namespace std;
/*
🧠 Question Ka Logic - Hinglish Mein Samjho:

Humare paas ek array `height[]` hai jisme har index ek vertical line ka height batata hai.

Objective: Do lines select karo aise ki unke beech ka paani rakhne ka area maximum ho.

🧱 Container banane ke rules:
- Area = distance between lines * minimum height of the two lines
- Jitna zyada distance aur height, utna zyada area

🔁 Brute-force approach (O(n^2)) → Har pair check karo
✅ Better approach (Two Pointer Technique - O(n)):

Step by step:

1. Start `i` from 0 (left pointer) and `j` from end (right pointer)
2. Calculate current area:
   - Length = j - i
   - Width = min(height[i], height[j])
   - Area = length * width
3. Compare with maxArea so far
4. Move pointer which has smaller height (because chhoti height limit kar rahi hai area ko)
5. Repeat until `i < j`

💡 Intuition: Chhoti height wale ko hatao → ho sakta hai aage koi badi height mil jaaye

📊 Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Answer: 49  (Between index 1 and 8 → min(8,7) = 7, length = 8-1 = 7 → 7*7 = 49)

-----------------------------
📈 Flow Chart (Hinglish mein)

      i=0              j=last index
       ↓                    ↓
height[i]             height[j]

|→→→→→→→→→→→→→→→→→→→→→→→→|
<-- Width = j - i -->

Minimum(height[i], height[j]) → Width of water

Area = Width * Length

Phir:
- Agar height[i] < height[j], to i++
- Else j--

Repeat till i < j

-----------------------------
*/

class Solution {
    public:
        int maxArea(vector<int>& height) {
    
            int i = 0;                       // left pointer
            int j = height.size() - 1;       // right pointer (last index)
            int maxArea = 0;                 // maximum area ko track karne ke liye
    
            // Jab tak i aur j takra nahi jaate, loop chalayenge
            while(i < j){
    
                // Do lines ke beech ka distance (ye length hoga)
                int length = j - i;
    
                // Dono height me se chhoti height lete hain (ye width hoga)
                int width = min(height[i], height[j]);
    
                // Area = length * width
                int area = length * width;
    
                // Max area update karo agar naya area bada ho
                maxArea = max(maxArea, area);
    
                // Ab chhoti height ko move karo - taaki behtar height mil sake
                //Matlab left wali chhoti hai, toh wo area ko limit kar rahi hai.
                //i++ karo → agli badi height milne ka chance hai.
                if(height[i] < height[j]){
                    i++;  // left wali height chhoti thi → i ko aage badhao
                }
                else { //Matlab right wali chhoti hai ya equal hai
                       //j-- karo → right side se badi height aane ka chance hai.
                    j--;  // right wali height chhoti thi ya barabar thi → j ko peeche lao
                }
            }
    
            return maxArea; // sabse bada area return karo
        }
    };
    