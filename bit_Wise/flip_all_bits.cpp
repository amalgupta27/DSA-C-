/*
📌 **Logic Explanation (Hinglish)**

🔹 **Samasya Ka Vivaran:**
Hume ek integer `n` diya gaya hai, aur hume **uski sabhi bits flip** karke maximum power of 2 nikalni hai.

🔹 **Approach:**
1️⃣ **Step 1:** `n` ko **right shift aur OR (`|`) operation** se modify karna taki sabhi bits `1` ho jayein.
2️⃣ **Step 2:** `x ^ n` se **sabhi bits flip** karna taki hume required power of 2 mile.

📊 **Flowchart Representation (Hinglish ASCII)**

Start
  |
  v
[Input: Enter n]
  |
  v
[Right Shift & OR operations for setting all bits]
  |
  v
[XOR with original n to flip bits]
  |
  v
[Print max power of 2]
  |
  v
End

*/

#include<bits/stdc++.h>
using namespace std;

int max_power_of_two(int n){
    int x;
    // Step 1: Bitwise OR aur Right Shift ka use karke sabhi bits ko 1 banane ki koshish
    x = n | (n >> 1);  // Right shift karke adjacent bits ko 1 karna
    x = x | (x >> 2);  // 2 bit shift aur OR operation
    x = x | (x >> 4);  // 4 bit shift aur OR operation
    x = x | (x >> 8);  // 8 bit shift aur OR operation
    x = x | (x >> 16); // 16 bit shift aur OR operation (for large values)

    // Step 2: XOR operation se sabhi bits flip karna
    return x ^ n; // Flipped bits ka output dega
}

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Flipped bits of " << num << " : " << bitset<16>(max_power_of_two(num)) << "\n";
    return 0;
}


// or
// for leet code
// class Solution {
//     public:
//         int flipBit(int n, int pos) {
//             return n ^ (1 << pos); // Flip the bit at 'pos'
//         }
//     };
    