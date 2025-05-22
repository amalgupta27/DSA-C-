/*
📌 Samasya Ka Bayaan (Hindi)
Hume ek integer number diya gaya hai aur hume uske **set bits** (1 ke count) ko count karna hai.
Set bit ka matlab hai binary representation me jitne bhi `1` present hain.

🔹 Example:
    Input: 5
    Binary: 101
    Set Bits: 2 (kyunki 101 me 2 baar `1` hai)

🛠 Tarkika (Built-in Function `__builtin_popcount()`):
1️⃣ Ye function **binary representation** me jitne `1` honge unka count direct return karta hai.
2️⃣ Iska time complexity O(1) hota hai, yani bohot fast tarika hai.

📊 Flowchart (Hinglish ASCII Representation)

Start
  |
  v
[Input: Enter Number]
  |
  v
[Convert to Binary & Count '1']
  |
  v
[Print Number of Set Bits]
  |
  v
End
*/

#include <iostream>
using namespace std;

int main() {
    int num; // Ek integer variable declare kar rahe hain
    cout << "Enter a number: "; // User se input lene ke liye message print karenge
    cin >> num; // User ka number input lenge

    // `__builtin_popcount(num)` function ka use karke set bits count karenge
    cout << "Number of set bits: " << __builtin_popcount(num) << endl;
    
    return 0; // Program successfully terminate hoga
}
