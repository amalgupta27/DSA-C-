#include<bits/stdc++.h>
using namespace std;
/*
📌 PROBLEM: Transpose of a Matrix (Hinglish Explanation)

🧠 LOGIC:
Matrix transpose ka matlab hai — rows ko columns banana aur columns ko rows.
Matlab: agar matrix[i][j] tha, to transpose me woh matrix[j][i] ho jaata hai.

➡️ Original matrix (m × n):
1  2  3
4  5  6

➡️ Transposed matrix (n × m):
1  4
2  5
3  6

🧾 Step-by-Step:
1️⃣ Matrix ka size nikal lo:
     m = matrix.size()        => rows
     n = matrix[0].size()     => columns
2️⃣ Ek n × m ka empty matrix banao (yeh transpose hoga)
3️⃣ Nested loops se original matrix ke elements ko transpose matrix me store karo:
     t[i][j] = matrix[j][i];

📊 FLOWCHART (Hinglish):
START
  |
  |---> matrix ka row aur column size nikalo (m × n)
  |
  |---> n × m ka new matrix t[][] banao
  |
  |---> i = 0 to n-1:
  |       j = 0 to m-1:
  |           t[i][j] = matrix[j][i]
  |
  |---> Transposed matrix t[][] return karo
  |
  ---> END

🧮 TIME COMPLEXITY:
- Total elements = m × n
- Har element ko 1 baar access kar rahe ho
- So, Time Complexity = O(m × n)

🧠 SPACE COMPLEXITY:
- O(n × m) extra space for new matrix

✅ Easy and perfect for beginners!
--------------------------------------------------------
👇👇👇 Actual Working Code with comments
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();         // m = number of rows
        int n = matrix[0].size();      // n = number of columns

        // New matrix of size n x m (transpose ka size ulta hota hai)
        vector<vector<int>> t(n, vector<int>(m)); 

        // Transposing logic: row becomes column, column becomes row
        for(int i = 0; i < n; i++){           // n columns → now rows in transpose
            for(int j = 0; j < m; j++){       // m rows → now columns in transpose
                t[i][j] = matrix[j][i];       // transpose logic: t[i][j] = matrix[j][i]
            }
        }

        return t;  // Return transposed matrix
    }
};
