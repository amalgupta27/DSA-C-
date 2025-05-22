#include <iostream>
using namespace std;

/*
📌 **Logic Explanation (Hinglish)**

🔹 **Samasya Ka Vivaran:**  
Hume **do integers `x` aur `y` diye gaye hain**, aur hume **minimum bits find karni hai jo `x` ko `y` me convert kar sakein**.  
Yeh **Hamming Distance** ya **Bit Difference** bhi kehlata hai.

🔹 **Approach:**  
1️⃣ **XOR (`^`) ka use:**  
   - Jab hum **XOR (`^`) operation** apply karte hain `x` aur `y` par, toh:
     - **Agar dono bits same hain (`0 0` ya `1 1`), toh result `0` hota hai.**  
     - **Agar dono bits different hain (`0 1` ya `1 0`), toh result `1` hota hai.**  
   - Iska matlab yeh hai ki **XOR ka result un bits ko identify karega jo `x` aur `y` me different hain**.

2️⃣ **Inbuilt function `__builtin_popcount()` ka use:**  
   - **`__builtin_popcount(n)` ek aisa function hai jo `n` me set (1) bits ki counting karta hai**.  
   - Jab hum **XOR result ka popcount nikalenge, toh yeh bata dega ki kitni bits different hain**.  
   - **Yehi minimum bit flips honge jo `x` ko `y` me badalne ke liye chahiye**.

🔹 **Example:**  
```cpp
x = 23  →  10111  (Binary representation of 23)
y = 32  → 100000  (Binary representation of 32)
x ^ y   → 110111  (XOR result)
Total 1s in XOR result = 4  (Hume 4 bits flip karni padengi)
```

📊 **Flowchart Representation (Hinglish ASCII)**  
```
Start
  |
  v
[Input: Enter x and y]
  |
  v
[XOR operation apply karo: x ^ y]
  |
  v
[Count karo kitni 1s hain (__builtin_popcount)]
  |
  v
[Print min bit flips]
  |
  v
End
```
*/

int main() {
    int x = 23;  // Example input: 23
    int y = 32;  // Example input: 32

    // XOR se different bits find karna aur __builtin_popcount se counting karna
    cout << "Min bits required to convert " << x << " to " << y << ": " << __builtin_popcount(x ^ y) << endl;
    
    return 0; // Program successfully terminate hoga
}
