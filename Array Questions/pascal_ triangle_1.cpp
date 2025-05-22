#include<iostream>
#include<vector>
using namespace std;
/*
📌 **Logic Explanation - Pascal's Triangle (Hinglish + Flow + Example)**

🔹 **Samasya Ka Vivaran (Problem Statement):**
Hume ek number `numRows` diya gaya hai. Hume `numRows` tak ka **Pascal's Triangle** banana hai.

Pascal's Triangle ke har row me numbers hote hain:
- Pehla aur last element `1` hota hai
- Beech ke elements: `v[i-1][j] + v[i-1][j-1]`

🔹 **Example:**
numRows = 5
Output:
[
 [1],
 [1, 1],
 [1, 2, 1],
 [1, 3, 3, 1],
 [1, 4, 6, 4, 1]
]

🔹 **Flowchart (Hinglish ASCII Style)**

Start
  |
  v
[Input lo numRows]
  |
  v
[Ek empty 2D vector banao]
  |
  v
[row-wise vectors banao jisme size i hoga]
  |
  v
[Har row ke liye loop chalao]
  |
  v
[agar j==0 ya j==i ho toh 1 rakho]
  |
  v
[nahi toh value = upper left + upper element]
  |
  v
[return 2D vector]
  |
  v
End

*/

class Solution {
    public:
        // Pascal's Triangle generate karne ka function
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> v; // 2D vector jisme final triangle store hoga
    
            // Step 1: Row wise vector insert karo jiska size i hoga
            //Yeh loop har row ke liye ek vector bana raha hai, jisme row number ke according size hoti hai. Aur fir us row ko main vector v me daal deta hai.
            for(int i = 1; i <= numRows; i++){  //iska purpose hai Pascal's Triangle ka structure banana
                vector<int> a(i); // ek vector bana rahe jiska size 'i' hai
                v.push_back(a); // is row ko main vector me daal rahe hain
            }
    
            // Step 2: Pascal's Triangle generate karo
            for(int i = 0; i <= numRows - 1; i++){
                for(int j = 0; j <= i; j++){
                    if(j == 0 || i == j){
                        // Har row ka pehla aur aakhri element hamesha 1 hota hai
                        v[i][j] = 1;
                    } else {
                        // Beech ka element = upar wale row ke dono diagonals ka sum
                        // v[i][j] = v[i-1][j] + v[i-1][j-1];
                        v[i][j] = v[i-1][j] + v[i-1][j-1];
                    }
                }
            }
    
            return v; // Final Pascal's Triangle return karo
        }
    };
    