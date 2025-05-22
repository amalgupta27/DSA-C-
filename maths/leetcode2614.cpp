#include<bits/stdc++.h>
using namespace std;
/*
📌 LOGIC EXPLANATION (HINGLISH):

🔹 Question:
Ek 2D square matrix diya gaya hai (vector<vector<int>>), jisme hume **diagonals par jo prime number hai unmein se sabse bada (maximum) prime number** nikalna hai.

🔹 Diagonals:
1️⃣ **Primary Diagonal** – (i, i) wale elements
2️⃣ **Secondary Diagonal** – (i, n - i - 1) wale elements

🔹 Approach:
👉 Step 1: Diagonals ke elements ko loop se access karo.
👉 Step 2: Har element ke liye check karo kya wo prime number hai (isPrime function se).
👉 Step 3: Agar prime hai to max (maximum) variable se compare karke update karo.
👉 Step 4: Last mein max return kar do.

🔹 Example:
Input matrix:
[
 [1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]
]

Primary Diagonal: 1, 5, 9
Secondary Diagonal: 3, 5, 7
Prime elements: 3, 5, 5, 7 → max = 7

📊 Flowchart (ASCII in Hinglish):

Start
  |
  v
[Input: 2D matrix]
  |
  v
[Loop i = 0 to n-1]
  |
  v
[Check: isPrime(matrix[i][i])]
  |        \
  |         > Agar haan, max update karo
  |
  v
[Check: isPrime(matrix[i][n-i-1])]
  |        \
  |         > Agar haan, max update karo
  |
  v
[Loop end hone ke baad max return karo]
  |
  v
End
*/

class Solution {
    public:
        // Prime number check karne ka function
        bool isPrime(int n){
            if(n == 1) return false; // 1 ko prime nahi maanate
            for(int i = 2; i <= sqrt(n); i++){ // √n tak check karna kaafi hota hai
                /*
                Agar n kisi bhi i se divide ho gaya (i = 2 to sqrt(n))
                toh wo prime nahi hoga
                */
                if(n % i == 0) return false;
            }
            return true; // Agar koi factor nahi mila toh prime hai
        }
    
        int diagonalPrime(vector<vector<int>>& nums) {
            int mx = 0; // Maximum prime ko track karega
            int n = nums.size(); // Matrix ka size
    
            for(int i = 0; i < n; i++){
                // Primary diagonal ka element: nums[i][i]
                if(isPrime(nums[i][i])){
                    mx = max(mx, nums[i][i]); // Prime mila toh mx update karo
                }
    
                // Secondary diagonal ka element: nums[i][n-i-1]
                if(isPrime(nums[i][n - i - 1])){
                    mx = max(mx, nums[i][n - i - 1]); // Prime mila toh mx update karo
                }
            }
    
            return mx; // Maximum diagonal prime return karo
        }
    };
    