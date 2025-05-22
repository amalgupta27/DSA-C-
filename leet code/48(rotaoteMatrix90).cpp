#include<bits/stdc++.h> // Include all standard libraries
using namespace std;
/*
❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖
🧠 LOGIC SAMJHAYEIN (Rotate 90 degree clockwise) ➤ Matrix ko rotate karna hai

✦ Matrix ko 90° clockwise rotate karne ke liye:
   Step 1: Matrix ka **transpose** lo (i.e., row <-> column swap karo).
   Step 2: Har row ko **reverse** kar do (left <-> right).

🎯 Example:
Input:
1  2  3
4  5  6
7  8  9

Step 1 (Transpose):
1  4  7
2  5  8
3  6  9

Step 2 (Reverse each row):
7  4  1
8  5  2
9  6  3

OUTPUT: 90° rotated matrix clockwise

🧭 FLOWCHART (Hinglish - ASCII Style):
-------------------------------------------
| Start                                    |
|    ↓                                     |
| Transpose matrix                        |
| (matrix[i][j] <-> matrix[j][i])          |
|    ↓                                     |
| Reverse har row                          |
| (har row ke andar left<->right swap)     |
|    ↓                                     |
| Return rotated matrix                    |
|    ↓                                     |
| End                                      |
-------------------------------------------

⏱️ TIME COMPLEXITY:
- Transpose: O(n²)
- Row reversal: O(n²)
- Overall: O(n²) time, O(1) space (in-place rotation)

❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖❖
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // n x n matrix

        // Step 1: Transpose the matrix (row <-> column)
        // Matrix[i][j] ko matrix[j][i] ke saath swap karte hain
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // Swap values
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Step 2: Reverse each row (left <-> right)
        // Har row ke andar elements ko ulta karna hai
        for(int row = 0; row < n; row++) {
            int i = 0;         // row ke left end
            int j = n - 1;     // row ke right end
            while(i < j) {
                // Swap left and right
                int temp = matrix[row][i];
                matrix[row][i] = matrix[row][j];
                matrix[row][j] = temp;
                i++;
                j--;
            }
        }
    }
};

/*
🌟 SUMMARY:
- Matrix ko transpose karke har row ko reverse karne se 90 degree rotation clockwise hota hai.
- Ye in-place hai, so koi extra space nahi lagta.

🧠 Visualization Example:
Input:
1 2 3
4 5 6
7 8 9

After Transpose:
1 4 7
2 5 8
3 6 9

After Row Reverse:
7 4 1
8 5 2
9 6 3

Yahi final rotated matrix hai! 🎉
*/
