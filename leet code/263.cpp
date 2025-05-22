#include<bits/stdc++.h>
using namespace std;
/*
📌 **Ugly Number Problem - Logic (Hinglish Explanation + Flowchart + Example)**

🔹 **Samasya (Problem Statement):**
Ek number ko "Ugly Number" kaha jata hai agar uske **prime factors sirf 2, 3 ya 5** ho.
Matlab number 2, 3, ya 5 ke alawa kisi aur prime se divisible nahi hona chahiye.

🔹 **Example:**
- n = 6 → 6 = 2 × 3 → Ugly ✅
- n = 14 → 14 = 2 × 7 → 7 ek extra prime hai → Not Ugly ❌
- n = 1 → considered Ugly ✅ (base case)

🔹 **Approach:**
- Agar number 0 hai → directly false (kyuki 0 kisi se divide nahi hota properly)
- Jab tak number 2, 3, ya 5 se divide ho raha hai, usko divide karte raho.
- Agar end me number 1 ban gaya → Ugly ✅
- Agar koi aur prime bacha → Not Ugly ❌

📊 **Flowchart (ASCII in Hinglish):**

[Start]
   |
   v
[n == 0 ? → return false]
   |
   v
[While divisible by 2 → divide]
   |
   v
[While divisible by 3 → divide]
   |
   v
[While divisible by 5 → divide]
   |
   v
[n == 1 ? → return true : return false]
   |
   v
[End]
*/

class Solution {
    public:
        // Ye function check karta hai ki diya gaya number "ugly number" hai ya nahi
        bool isUgly(int n) {
            // 🟡 Step 1: Agar number 0 hai, to ugly number nahi ho sakta (direct return false)
            if(n == 0) return false;
    
            // 🔵 Step 2: Jab tak n 2 se divide ho raha hai, usko divide karte raho
            // Example: n = 8 → 8 → 4 → 2 → 1
            while(n % 2 == 0) n /= 2;
    
            // 🔵 Step 3: Jab tak n 3 se divide ho raha hai, usko divide karte raho
            // Example: n = 9 → 9 → 3 → 1
            while(n % 3 == 0) n /= 3;
    
            // 🔵 Step 4: Jab tak n 5 se divide ho raha hai, usko divide karte raho
            // Example: n = 25 → 25 → 5 → 1
            while(n % 5 == 0) n /= 5;
    
            // 🟢 Step 5: Agar sab prime factors se divide karne ke baad n == 1 ho gaya,
            // to iska matlab hai ki number ugly hai
            if(n == 1) return true;
    
            // 🔴 Step 6: Agar n 1 nahi hai, to number mein koi aur prime factor tha,
            // isliye ye ugly number nahi hai
            return false;
        }
    };
    