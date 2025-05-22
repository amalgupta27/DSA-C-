#include<bits/stdc++.h>
using namespace std;
/*
📌 **Logic Explanation (Hinglish + Flowchart + Example)**

🔸 **Problem Statement:**
Ek array diya gaya hai `nums[]`, jisme humein sabhi elements ke **distinct prime factors** count karne hain.

🔸 **Example:**
nums = [12, 15]
- 12 ke prime factors = 2, 3
- 15 ke prime factors = 3, 5
→ Distinct prime factors = 2, 3, 5
→ Final Answer = 3

🔸 **Optimized Solution using Sieve of Eratosthenes:**
1. Pehle array me maximum element `mx` find karo.
2. `mx` tak ka Sieve array banao, jisse hum prime numbers identify kar sakein.
3. Sieve fill karke 2 se `mx` tak ke prime numbers store kar lo.
4. Har element ke liye, check karo kaunse prime se divide hota hai → us prime ko taken[] me mark karo.
5. End me jitne primes taken[] me mark huye hain, wahi answer hai.

📊 **Flowchart (Hinglish ASCII Style)**

Start
  |
  v
[Input lo nums[]]
  |
  v
[mx = max element of nums]
  |
  v
[sieve vector banao size = mx+1, fill karo]
  |
  v
[prime list banao using sieve]
  |
  v
[nums ke har element ke liye check karo prime divisors]
  |
  v
[taken[] array me mark karo jo prime factor already gaye]
  |
  v
[count = taken[] me jitne 1's hai]
  |
  v
[Return count]
  |
  v
End
*/

class Solution {
    public:
        // Sieve of Eratosthenes ka use karke prime numbers ko mark karne wali function
        void fillSieve(vector<bool>& sieve){
            int n = sieve.size() - 1; // sieve ka size n+1 hai, isliye actual n = size-1
            for(int i = 2; i <= sqrt(n); i++){ // 2 se sqrt(n) tak loop
                for(int j = i * 2; j <= n; j += i){ // i ke multiples ko non-prime mark karo
                    sieve[j] = 0; // composite number ko false (0) mark karo
                }
            }
        }
    
        // Main function jo distinct prime factors ki counting karega
        int distinctPrimeFactors(vector<int>& nums) {
            int n = nums.size(); // nums vector ka size nikal rahe hain
            int mx = -1; // max number store karne ke liye variable
    
            // Step 1: nums me se maximum element nikalna
            for(int i = 0; i < n; i++){
                mx = max(mx, nums[i]); // mx ko update kar rahe hain
            }
    
            // Step 2: mx tak ka sieve banate hain (true = prime)
            // Size mx + 1 isliye liya gaya kyunki humein index 0 se lekar mx tak access karna hai
            vector<bool> sieve(mx + 1, 1); // initially sabko prime maana
            if(mx + 1 > 0) sieve[0] = 0; // 0 ko non-prime mark karo
            if(mx + 1 > 1) sieve[1] = 0; // 1 ko bhi non-prime mark karo
    
            // Step 3: sieve ko fill karna jisme non-prime ko hata dena
            fillSieve(sieve);
    
            // Step 4: prime numbers ko store karne ke liye vector
            vector<int> primes;
    
            // Step 5: sieve me jo true hain unko prime list me daal do
            for(int i = 2; i <= mx; i++){
                if(sieve[i] == 1) primes.push_back(i); // prime mil gaya
            }
    
            // Step 6: ek boolean array banate hain taken jisse pata chale kaunse prime factor already count kiye
            vector<bool> taken(primes.size(), 0); // initially sab false (0)
    
            // nums ke har element ke liye check karo kaunse prime se divide hota hai
            for(int i = 0; i < nums.size(); i++){
                int ele = nums[i]; // current element
                for(int j = 0; j < primes.size(); j++){
                    if(primes[j] > ele) break; // agar prime number ele se bada ho toh break
                    if(ele % primes[j] == 0) taken[j] = 1; // agar divisible hai toh us prime ko taken mark karo
                }
            }
    
            // Step 7: taken array me jitne 1 (true) hain unka count nikaal lo
            int count = 0; 
            for(int i = 0; i < taken.size(); i++ ){
                if(taken[i] == 1) count++; // agar prime factor mila toh count badhao
            }
    
            return count; // final answer return karo
        }
    };
    