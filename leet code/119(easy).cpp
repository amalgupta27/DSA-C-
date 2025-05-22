#include<bits/stdc++.h>
using namespace std;
/*
📌 **Problem Statement (Hinglish):**
Tumhe ek number `rowIndex` diya gaya hai, aur tumhe Pascal's Triangle ki `rowIndex` wali row return karni hai. 
Pascal’s Triangle ek triangle jaisa pattern hota hai jisme har element apne upar ke do elements ka sum hota hai.

🔍 **Example:**
Input: rowIndex = 3  
Pascal's Triangle (first few rows):
Row 0:       [1]
Row 1:      [1, 1]
Row 2:     [1, 2, 1]
Row 3:    [1, 3, 3, 1] ← Output

✅ Hume ye [1, 3, 3, 1] return karna hai

🎯 **Main Concept:**
- Har row ka first aur last element always 1 hota hai.
- Beech ke elements: `row[i][j] = row[i-1][j-1] + row[i-1][j]`

🔁 **Logic Flow:**
1. Ek 2D vector `v` banate hain jisme `rowIndex+1` rows hongi.
2. Har row me `i+1` columns honge.
3. Pehle aur aakhri element 1 set karo.
4. Baki elements ko upar ke 2 elements ka sum bana do.

📊 **Flowchart (Hinglish - ASCII Style):**

[Start]
   |
   v
[Input lo: rowIndex]
   |
   v
[2D vector v banao size rowIndex+1]
   |
   v
[Har row me size = i+1 elements]
   |
   v
[Loop i = 0 se rowIndex tak]
   |
   v
    [Loop j = 0 se i tak]
         |
         ├── [j == 0 || i == j] → v[i][j] = 1
         |
         └── [else] → v[i][j] = v[i-1][j-1] + v[i-1][j]
   |
   v
[Return v[rowIndex]]
   |
   v
[End]
*/

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<vector<int>> v; // 2D vector for Pascal’s triangle rows
    
            // Step 1: har row ke liye vector banate hain
            //Yeh loop har row ke liye ek vector bana raha hai, jisme row number ke according size hoti hai. Aur fir us row ko main vector v me daal deta hai.
            for(int i = 0; i <= rowIndex; i++){ //iska purpose hai Pascal's Triangle ka structure banana
                vector<int> a(i + 1); // row i ke liye i+1 elements chahiye
                v.push_back(a); // row ko main vector me add karo
            }
    
            // Step 2: Pascal triangle fill karte hain
            for(int i = 0; i <= rowIndex; i++){
                for(int j = 0; j <= i; j++){
                    if(j == 0 || j == i){
                        v[i][j] = 1; // har row ka pehla aur last element 1 hota hai
                    } else {
                        // Beech ke elements: upar ke 2 numbers ka sum
                        v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
                    }
                }
            }
    
            // Step 3: Sirf rowIndex wali row return karo
            return v[rowIndex];
        }
    };
    