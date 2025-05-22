#include<bits/stdc++.h>
using namespace std;
/*
📌 **Logic Explanation (Hinglish + Flow + Example)**

🔹 **Samasya Ka Vivaran (Problem Statement):**
Hume `n` se chhote sare **prime numbers** count karne hain. Jaise agar `n = 10`, toh prime numbers hain: 2, 3, 5, 7 ⇒ total 4 primes.

🔹 **Optimized Approach (Sieve of Eratosthenes):**
- Ek array/vector banate hain `sieve[]` jo batayega kaunsa number prime hai ya nahi.
- Initially, sabko `true` (yaani prime) maan lete hain.
- Fir 2 se lekar √n tak loop chalayenge.
    - Jis number ko prime maan liya, uske multiples ko `false` kar denge.
    - Aise karke non-primes ko eliminate karte hain.

🔹 **Example:**
n = 10
Start: [T, T, T, T, T, T, T, T, T, T, T] // index 0 to 10
0 aur 1 ko false karo: [F, F, T, T, T, T, T, T, T, T, T]
2 ke multiples hatao: 4,6,8,10
3 ke multiples hatao: 6,9
Final Prime Flags: [F, F, T, T, F, T, F, T, F, F, F] → primes: 2,3,5,7 = 4 primes

📊 **Flowchart Representation (ASCII - Hinglish)**

Start
  |
  v
[Input lo n]
  |
  v
[vector<bool> sieve bana lo size n+1 with true]
  |
  v
[0 aur 1 ko false karo]
  |
  v
[2 se sqrt(n) tak loop karo]
  |
  v
[Har i ke multiples ko false karo (non-prime)]
  |
  v
[sieve me jitne true bache → count karo]
  |
  v
[return count]
  |
  v
End

🔍 **Important Note (Size n+1 kyun?)**
Hum `n` tak ke index access karte hain (0 to n), isliye vector ka size `n+1` rakhte hain.
Agar size sirf `n` rakhenge to index `n` pe access karne par out-of-bounds error aayega.

👉 Example: Agar n = 10, hume index 0 se lekar 10 tak access karna hai, isliye size = 11 (n+1)
*/

class Solution {
    public:
        // Sieve ko fill karne wala function, prime number identify karega
        void fillSieve(vector<bool>& sieve){
          // 🔵 sieve vector ka size n+1 hai, kyuki hum 0 se lekar n tak ke numbers handle karte hain
            // 🔵 Lekin number counting mein hume last usable index (n) chahiye, isliye size - 1 kiya
            int n = sieve.size() - 1; // vector ka size n+1 hai, isliye actual n = size-1
            for(int i = 2; i <= sqrt(n); i++){ // i ko 2 se sqrt(n) tak loop karenge bcz wahin tak prime factor hota hai kisi number(n) kaa
                if (sieve[i]) { // agar i abhi bhi prime hai tabhi uske multiples ko hatao
                    for(int j = i * 2; j <= n; j += i){ // i ke multiples ko 0 mark karenge (non-prime), i*2 se start karna better hai
                        sieve[j] = 0; // non-prime number ko 0 set kar rahe hain
                    }
                }
            }
        } 
    
        int countPrimes(int n) {
            if(n <= 2) return 0; // agar n 2 ya usse chhota hai, toh koi prime number nahi hoga
            n = n - 1; // humein n ke just pehle tak ke primes chahiye, isliye n-1 kar diya
            int count = 0; // prime number ka count store karega
            vector<bool> sieve(n + 1, 1); // size n+1 ka vector banaya, initially sabko 1 (prime) maan liya
            fillSieve(sieve); // sieve function se prime identify karenge
            sieve[0] = 0; // 0 prime nahi hota
            sieve[1] = 0; // 1 bhi prime nahi hota
    
            for(int i = 2; i <= n; i++){ // 2 se lekar n tak loop
                if(sieve[i] == 1) count++; // agar i prime hai to count increment karenge
            }
            return count; // final prime count return karenge
        }
    };
    