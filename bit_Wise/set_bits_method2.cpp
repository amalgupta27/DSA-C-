/*
📌 Samasya Ka Bayaan (Hindi)
Hume ek integer `n` diya gaya hai, aur hume uske **set bits** (binary representation me jitne bhi `1` hain) count karne hain.

🔹 Example:
    Input: 5
    Binary: 101
    Set Bits: 2 (kyunki 101 me 2 baar `1` hai)

🛠 Tarkika (`n & (n-1)` technique):
1️⃣ Har baar `n & (n-1)` karne se **least significant set bit** remove hoti hai.
2️⃣ Jab tak `n > 0` hoga, tab tak hum count badhate rahenge.
3️⃣ Ye technique bohot efficient hai kyunki ye **O(log N)** time me answer deti hai.

📊 Flowchart (Hinglish ASCII Representation)

Start
  |
  v
[Input: Enter Number]
  |
  v
[Loop: Jab tak n > 0]
  |
  |---> [count++ karna]
  |---> [n = n & (n-1)]
  |
  v
[Print Number of Set Bits]
  |
  v
End

📝 `n = (n & (n-1))` ka deep explanation:
👉 Ye operation **LSB (Least Significant Bit) jo `1` hai usko remove karta hai**

🔹 Example: n = 5 (Binary: 101)
Step 1:  `n = 5`   (Binary: 101)
         `n-1 = 4`  (Binary: 100)
         `n & (n-1) = 101 & 100 = 100`  (n ab 4 ho gaya)

Step 2:  `n = 4`   (Binary: 100)
         `n-1 = 3`  (Binary: 011)
         `n & (n-1) = 100 & 011 = 000`  (n ab 0 ho gaya, loop stop)

🛠 Har baar operation se ek `1` bit remove ho rahi hai!
**/

#include<bits/stdc++.h>
using namespace std;

// Function jo number ke set bits count karega
int count_set_bits_2(int n){
    int count = 0; // Set bits count karne ke liye ek variable
    
    // Jab tak n > 0 rahega, loop chalega
    while(n > 0){
        count++; // Har baar count badhayenge kyunki ek set bit hat rahi hai
        n = (n & (n-1)); // Ye operation ek `1` bit ko hata dega
    }
    return count; // Total set bits return karenge
}

int main(){
   cout << count_set_bits_2(5) << "\n"; // Function ko call karke output print karenge
   return 0; // Program successfully terminate hoga
}


// or convert number in binary and simply count 1