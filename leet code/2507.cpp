#include<bits/stdc++.h>
using namespace std;
/*
🧠 Problem Understanding (Hinglish + Flow + Example)

🔹 Question: Ek number n diya gaya hai. Agar n prime hai toh wahi return karna hai.
   Agar n prime nahi hai, toh uske prime factors ka sum nikalna hai,
   aur fir dobara same process repeat karna hai jab tak result prime ho jaaye.

🔹 Example:
   n = 12
   Prime factors: 2 × 2 × 3 → sum = 2 + 2 + 3 = 7
   7 is prime → return 7

🔹 Flowchart (Hinglish - ASCII Art Style)

[Start]
   ↓
[Kya n Prime hai?] --Yes--> [Return n]
   |
   No
   ↓
[Prime Factors of n nikaalo]
   ↓
[Unka sum banao]
   ↓
[sum ko fir se smallestValue(sum) mein bhejo]
   ↓
[Repeat until Prime]
   ↓
[Return Prime Value]

✅ Efficient Logic:
   - Prime check ke liye √n tak loop chalaana
   - Dono direction (1 se sqrt(n), sqrt(n) se 1) mein factor find karna
   - Prime hone par recursion stop ho jaata hai
*/

class Solution {
    public:
        // Ek function jo check karta hai ki number prime hai ya nahi
        bool isPrime(int n){
            if(n == 1) return false; // 1 prime nahi hota
            for(int i = 2; i <= sqrt(n); i++){ // 2 se lekar sqrt(n) tak har number se divide karke check karo
                if(n % i == 0) return false; // agar kisi number se divide ho gaya, to prime nahi hai
            }
            return true; // agar kisi se divide nahi hua to prime hai
        }
    
        // Main function jo smallest value find karta hai
        int smallestValue(int n) {
            if(isPrime(n)) return n; // agar n already prime hai to wahi return karo
    
            int sum = 0; // prime factors ka sum yahan store hoga
    
            // Pehla loop: sqrt(n) se chhote prime factors find karo
            for(int i = 1; i < sqrt(n); i++){
                if(n % i == 0 && isPrime(i)){ // agar i ek factor hai aur prime bhi hai
                    int m = n; // ek temporary variable banaya m = n
                    while(m % i == 0){ // jab tak m i se divide ho raha hai
                        sum += i; // i ko sum mein add karo
                        m = m / i; // m ko i se divide karte jao
                    }
                }
            }
    
            // Dusra loop: sqrt(n) se bade prime factors find karo
            for(int i = sqrt(n); i >= 1; i--){
                if(n % i == 0 && isPrime(n / i)){ // agar n/i ek factor hai aur prime bhi hai
                    int m = n; // ek aur temporary variable m = n
                    while(m % (n / i) == 0){ // jab tak m, n/i se divide hota rahe
                        sum += n / i; // n/i ko sum mein add karo
                        m /= (n / i); // m ko n/i se divide karte jao
                    }
                }
            }
    
            if(sum == n) return n; // agar sum phir se wahi n aa gaya to use return kar do
    
            // Recursion: ab naye sum ke liye same function call karo
            return smallestValue(sum);
        }
    };
    