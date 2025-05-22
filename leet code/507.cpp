#include<bits/stdc++.h>
using namespace std;
/*
📌 **Logic Explanation (Hinglish + Flow + Example)**

🔹 **Samasya Ka Vivaran:**
Hume check karna hai ki koi number `num` **perfect number** hai ya nahi.

🔹 **Perfect Number Kya Hota Hai?**
A perfect number woh hota hai jiska sum of **proper divisors (excluding the number itself)** us number ke barabar ho.
Example:
- 28 → Divisors: 1, 2, 4, 7, 14 → Sum = 28 → Perfect Number ✅
- 12 → Divisors: 1, 2, 3, 4, 6 → Sum = 16 ≠ 12 → Not Perfect ❌

🔹 **Optimized Approach:**
Factors hamesha ek dusre ke pair mein hote hain. Jaise: 
→ 2 x 14 = 28, 4 x 7 = 28
Toh hume sirf `1 se √num` tak check karna hota hai. Agar `i` `num` ko divide kare, toh `num/i` bhi ek factor hoga.

🔹 **Why Two Loops?**
1st loop: `1 to sqrt(num)` tak jaake chhote wale factors ka sum nikalta hai.
2nd loop: `sqrt(num)` se `2` tak jaake bade wale paired factors ka sum nikalta hai.

⚠️ Note: `num` khud ko factor me include nahi karna hota.

📊 **Flowchart Representation (ASCII in Hinglish)**

Start
  |
  v
[Input lo num]
  |
  v
[sum = 0]
  |
  v
[1 to sqrt(num) tak loop]
  |--- if num % i == 0
  |       sum += i
  |
  v
[sqrt(num) to 2 tak loop]
  |--- if num % i == 0
  |       sum += num / i
  |
  v
[Check if sum == num]
  |
  v
[Perfect Number or Not]
  |
  v
End

🔢 **Example: num = 28**
- Loop 1: i = 1, 2, 3, 4, 5
   → 28 % 1 == 0 → sum += 1
   → 28 % 2 == 0 → sum += 2
   → 28 % 4 == 0 → sum += 4
   (sum = 1+2+4 = 7)
- Loop 2: i = 5 → 1
   → 28 % 7 == 0 → sum += 7
   → 28 % 14 == 0 → sum += 14
   (total sum = 7+7+14 = 28)
- sum == num → Perfect Number ✅
*/

class Solution {
    public:
        bool checkPerfectNumber(int num) {
            int sumOfFactor = 0; 
    
            // First loop: 1 se sqrt(num) tak, chhote factors ka sum nikalna
            for(int i = 1; i < sqrt(num); i++){ 
                if(num % i == 0) 
                    sumOfFactor += i; // i ek factor hai
            }
    
            // Second loop: sqrt(num) se 2 tak, bade wale paired factor (num/i) ka sum
            for(int i = sqrt(num); i > 1; i--){
                if(num % i == 0)
                    sumOfFactor += num / i; // paired factor
            } 
    
            // Agar sum of factors num ke barabar hai → perfect number hai
            if(sumOfFactor == num) return true;
            else return false;
        }
    };
    