#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        /*
        💡 Question Logic in Hinglish:
    
        Tumhe ek 2D matrix diya gaya hai. Tumhe uske elements ko ek spiral (ghoomte hue) order me return karna hai.
        Matlab pehle top row, fir right column, fir bottom row reverse me, fir left column reverse me...
        Ye ghoomna tab tak chalega jab tak pura matrix cover nahi ho jata.
    
        ✅ Example:
        Input:
        matrix = [
          [1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]
        ]
        
        Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
    
        🔁 Spiral Direction Order:
        ➡️ Right → ⬇️ Down → ⬅️ Left → ⬆️ Up (repeat until complete)
    
        -----------------------------------------
        🧠 Flowchart (Hinglish):
    
          minr = 0, maxr = m-1
          minc = 0, maxc = n-1
    
          Jab tak (minr <= maxr && minc <= maxc):
            ➡️ Traverse top row → minr++
            ⬇️ Traverse right column → maxc--
            ⬅️ Traverse bottom row → maxr--
            ⬆️ Traverse left column → minc++
        -----------------------------------------
        */
    
        vector<int> spiralOrder(vector<vector<int>>& matrix) {  //The & means:"Don't create a copy of the matrix, just give me access to the original one."
             //Matrix can be large (like 1000x1000).You just need to read it, not modify it.
             //Using reference avoids copying the whole matrix, which is good for performance.
            vector<int> v;  // Final answer store karne ke liye
    
            int m = matrix.size();         // rows ki sankhya
            int n = matrix[0].size();      // columns ki sankhya
    
            // 4 boundaries define karte hain
            int minr = 0;         // top row
            int maxr = m - 1;     // bottom row
            int minc = 0;         // left column
            int maxc = n - 1;     // right column
    
            // ✅ Jab tak minr <= maxr aur minc <= maxc hoga tab tak matrix ka andar ka kuch na kuch part bacha hai ghoomne ke liye.
            // Agar minr > maxr ya minc > maxc ho gaya to iska matlab hai hum already saari rows/columns ghoom chuke hain.
            // Tab loop ruk jaayega.
            while (minr <= maxr && minc <= maxc) {
                // ➡️ Step 1: Move right → Top row me left to right chalte hain
                for (int j = minc; j <= maxc; j++) {
                    v.push_back(matrix[minr][j]);
                }
                minr++;  // Top row ho gaya, ab neeche wale row ki taraf badho
    
                // Agar matrix already finish ho gaya ho to break
                //Toh agar aisi situation ho, toh turant loop se bahar nikal jao, warna galat access hoga ya repeat hoga.
                //bar-bar har direction ke baad isliye likha jata hai, taaki program extra loop me na ghuse aur out-of-bound access na kare.
                if (minr > maxr || minc > maxc) break;
    
                // ⬇️ Step 2: Move down → Right column me upar se neeche jao
                for (int i = minr; i <= maxr; i++) {
                    v.push_back(matrix[i][maxc]);
                }
                maxc--;  // Right column ho gaya, ab left ki taraf aao
    
                if (minr > maxr || minc > maxc) break;
    
                // ⬅️ Step 3: Move left → Bottom row me right to left jao
                for (int j = maxc; j >= minc; j--) {
                    v.push_back(matrix[maxr][j]);
                }
                maxr--;  // Bottom row ho gaya, ab upar ki taraf jao
    
                if (minr > maxr || minc > maxc) break;
    
                // ⬆️ Step 4: Move up → Left column me neeche se upar jao
                for (int i = maxr; i >= minr; i--) {
                    v.push_back(matrix[i][minc]);
                }
                minc++;  // Left column ho gaya, ab right ki taraf aao
            }
    
            return v;  // Final spiral order wala vector return kar do
        }
    };
    