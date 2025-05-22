/*
📌 Samasya Ka Bayaan (Hindi)
Hume ek decimal number diya gaya hai aur usko binary me convert karna hai.
Binary sirf 0 aur 1 ka combination hota hai jo ki computer samajhta hai.

🔹 Decimal to Binary Conversion Ka Basic Concept:
Har ek decimal number ko divide-by-2 method se binary me convert kiya jata hai.
Example:
    Decimal: 5
    Step 1: 5 / 2 = Quotient: 2, Remainder: 1
    Step 2: 2 / 2 = Quotient: 1, Remainder: 0
    Step 3: 1 / 2 = Quotient: 0, Remainder: 1
    Binary = (Bottom to Top) ➝ 101

🛠 Tarkika:
1️⃣ Har baar number ko 2 se divide karenge aur remainder store karenge.
2️⃣ Remainder ko reverse order me store karenge taki correct binary mile.
3️⃣ Jab number 0 ho jaye, to final binary string return karenge.

📊 Flowchart (Hinglish ASCII Representation)

Start
  |
  v
[Input: Decimal Number]
  |
  v
[Loop: Jab tak num > 0]
  |
  |---> num % 2 (Find remainder, store at start)
  |---> num = num / 2
  |
  v
[Reverse Remainder String]
  |
  v
[Return Final Binary String]
  |
  v
End
*/

#include<bits/stdc++.h>
using namespace std;

// Function to convert decimal to binary
string decimal_to_binary(int num){
    string result = ""; // Binary result store karne ke liye string
    
    // Jab tak number greater than 0 hai, loop chalega
    while(num > 0){
       if(num % 2 == 0){
           result = '0' + result; // Agar remainder 0 hai, to binary me '0' add karo
       }
       else{
           result = '1' + result; // Agar remainder 1 hai, to binary me '1' add karo
       }
       num = num / 2; // Number ko divide-by-2 karte rahenge
    }
    return result; // Final binary number return karenge
}

int main(){
    cout << decimal_to_binary(5) << endl; // Function call aur output print
    return 0;
}

// 📌 Alternative method using C++ STL (bitset)
// `bitset<16>(num)` converts num into a 16-bit binary representation.
// You can change 16 to a higher/lower value based on the required number of bits.
// #include <iostream>
// #include <bitset>
// using namespace std;
// int main() {
//     int num = 5;
//     cout << "Binary representation: " << bitset<16>(num) << endl;
//     return 0;
// }
// Output:
// Binary representation: 0000000000000101
