#include<bits/stdc++.h>
using namespace std;
/*
📌 **Logic Explanation (Hinglish + Flow + Example)**

🔹 **Samasya (Problem Statement):**
Ek integer `n` diya gaya hai. Aapko batana hai minimum steps kitne lagenge `n` banane ke liye.
Allowed operation: Har step mein aap string ko copy ya paste kar sakte ho.

🔹 **Main Idea (Approach):**
- Har number `n` ko uske largest factor se banane ki koshish karo.
- Agar `n` ek prime hai, to usko banane ke liye `n` steps lagenge (copy + n-1 pastes)
- Agar `n` composite hai, to uska greatest factor `hf` nikaalo, aur `n/hf` steps mein usko banao.

🔹 **Example:**
Let’s say `n = 9`
- 9 is not prime → largest factor = 3
- So, 9 = 3 * 3 → copy 3 once, paste 2 times = 3 steps
- Now reduce n to 3
- 3 is prime → 3 steps
- Total = 3 (for 9→3) + 3 (for 3) = 6 steps

📊 **Flowchart Representation (ASCII - Hinglish)**

Start
  |
  v
[Input lo n]
  |
  v
[n > 1 ?]
  |         
  |-- No --> return count
  |
  v
[n prime hai?]
  |         
  |-- Yes --> count += n → break
  |
  v
[Greatest divisor dhoondo (n / i)]
  |
  v
[count += n / divisor]
  |
  v
[n = divisor → repeat]
  |
  v
End
*/

class Solution {
    public:
        // Prime number check karne ka function
        bool isPrime(int n){
            if(n==1) return false; // 1 prime nahi hota
    
            // 2 se sqrt(n) tak check karo ki koi factor hai ya nahi
            for(int i=2; i<=sqrt(n); i++){
                if(n%i==0) return false; // agar kisi number se divide ho gaya to prime nahi
            }
            return true; // kisi se divide nahi hua to prime hai
        }
    
        // greatest divisor dhoondhne ka function (jo n se chota ho)
        int gd(int n){
            /*
            ✅ Traditional Approach:
            for(int i = n/2; i >= 1; i--){
                if(n%i==0) return i;
            }
    
            ✅ Optimized:
            Agar n = 36
            i = 2 → 36 % 2 == 0 → return 36 / 2 = 18 (sabse bada factor)
            */
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return n / i; // sabse bada factor return karo
            }
            return 1; // agar koi factor nahi mila (n is prime) to 1 return
        }
    
        // Main function - minimum steps find karna
        int minSteps(int n) {
            int count = 0; // steps count karne ke liye variable
    
            while(n > 1){ // jab tak n 1 se bada hai
                if(isPrime(n)){
                    // agar n prime hai, to usko banane ke liye n steps lagenge
                    count += n; 
                    break; // loop se bahar aa jao
                }
    
                int hf = gd(n); // n ka greatest divisor find karo
                count += (n / hf); // jitni baar multiply kiya, utne steps add karo
                n = hf; // ab naye n pe process repeat karo
            }
    
            return count; // final step count return karo
        }
    };
    