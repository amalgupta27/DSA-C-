/*
📌 Samasya Ka Bayaan (Hindi)
Humare paas ek binary string hai (sirf 0 aur 1 wali string) aur hume usko decimal number me convert karna hai.

🔹 Binary to Decimal Conversion Ka Basic Concept:
Binary ek base-2 numbering system hai jisme sirf do digits hoti hain: 0 aur 1.
Har ek digit ka ek power-of-2 weight hota hai. 
Example:
    Binary:  1   0   1   0   (Left to Right)
    Weights: 2^3 2^2 2^1 2^0
    Decimal = (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (0 * 2^0)
            = (8 + 0 + 2 + 0)
            = 10

🛠 Tarkika:
1️⃣ Hum ek loop chalakar har binary digit ka decimal value nikalenge.
2️⃣ Har digit ko uske corresponding 2^position se multiply karenge.
3️⃣ Saare values ko add karke final decimal number return karenge.

📊 Flowchart (Hinglish ASCII Representation)

Start
  |
  v
[Input: Binary String]
  |
  v
[Loop through string from last index]
  |
  |---> Multiply each digit with 2^(position)
  |
  v
[Sum all values]
  |
  v
[Return final decimal number]
  |
  v
End
*/

#include<bits/stdc++.h>
using namespace std;

// Function to convert binary string to decimal
int binary_to_decimal(string &binary){
    int n= binary.size(); // Binary string ka size nikalenge
    int result= 0; // Final decimal result ko store karne ke liye variable
    
    // Loop reverse order me chalayenge taki position 0 se start ho
    for(int i=n-1; i>=0; i--){
        char c = binary[i]; // Current character store karenge
        int num = c - '0'; // Character ko integer me convert karenge (0 ya 1)
        
        // Decimal value calculate karenge using power of 2
        // (1 << (n-i-1)) ka matlab hai ki hum 2^(n-i-1) ka calculation bina pow() function ke shift operation se kar rahe hain.
        // Bitwise left shift (1 << x) ka matlab hai 1 ko 2^x jitna shift karna (jo ki fast aur efficient hota hai).
        result += num * (1 << (n-i-1)); // Ya phir pow(2, n-1-i) bhi use kar sakte hain
    }
    return result; // Final decimal number return karenge
}
    
int main(){
    string str= "001101"; // Binary string define kiya
    cout<<binary_to_decimal(str); // Function call aur output print
    return 0;
}

// OR C++ STL Functions ka use karke ek aur easy tareeka:
// int decimal = bitset<16>(binary).to_ulong();
// bitset<16>(binary): Binary string ko 16-bit integer me convert karta hai.
// .to_ulong(): Bitset ko unsigned long integer (decimal number) me convert karta hai.
// Bit size (16) ko aap apni zaroorat ke mutaabik badal sakte hain.
// Example Input: "1010"
// Output: Decimal equivalent: 10
//i.e
// #include <iostream>
// #include <bitset>

// using namespace std;

// int main() {
//     cout << bitset<16>("1101").to_ulong() << endl;
//     return 0;
// }
// output: 13