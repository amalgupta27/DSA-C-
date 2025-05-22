#include<bits/stdc++.h> // 🔹 Sabhi standard libraries include karte hai
using namespace std;

/*
--------------------------------------------------------
🔵 PROBLEM LOGIC (Simple Hinglish mein):

🔹 Question:
    - Do numbers input lo: a aur b.
    - Phir bina koi third variable banaye, dono ka value swap (badal) karna hai.
    - Phir swap hone ke baad unka output print karna hai.

🔹 Trick (Addition-Subtraction swapping):
    - a = a + b
    - b = a - b
    - a = a - b

🔹 Kaise kaam karta hai? Example se:
    Suppose a = 3, b = 5

    Step 1: a = a + b → 3 + 5 = 8 (Now a = 8)
    Step 2: b = a - b → 8 - 5 = 3 (Now b = 3)
    Step 3: a = a - b → 8 - 3 = 5 (Now a = 5)

    Final:
    a = 5, b = 3

🔹 Matlab dono values exchange ho gayi bina third variable use kare!

--------------------------------------------------------
🔵 FLOWCHART (ASCII Hinglish mein):

[Start]
   |
   v
[Input a, b]
   |
   v
[Print a, b]
   |
   v
[a = a + b]
   |
   v
[b = a - b]
   |
   v
[a = a - b]
   |
   v
[Print a, b]
   |
   v
[End]
--------------------------------------------------------
🔵 DRY RUN Example:

Input:
a = 2, b = 7

Process:
Step 1: a = a + b = 2 + 7 = 9
Step 2: b = a - b = 9 - 7 = 2
Step 3: a = a - b = 9 - 2 = 7

Output:
Before swapping: 2 7  
After swapping: 7 2

--------------------------------------------------------
*/

// 🔹 MAIN FUNCTION START
int main() {
    int a, b; // 🔸 Variables to hold the two numbers
    cout<<"Enter a & b : ";
    // 🔹 Step 1: Input from user
    cin >> a >> b;

    // 🔹 Step 2: Print original values
    cout << "Before swapping: " << a << " " << b << endl;

    // 🔹 Step 3: Swap without using third variable
    a = a + b; // a becomes sum of a and b
    b = a - b; // b becomes original a
    a = a - b; // a becomes original b

    // 🔹 Step 4: Print swapped values
    cout << "After swapping: " << a << " " << b << endl;

    return 0; // 🔸 Program ends
}

/*
--------------------------------------------------------
🔵 Important Notes:

✅ Is method mein koi extra space (extra variable) use nahi hota.
✅ Yeh tabhi safe hai jab a+b integer overflow na kare. (Bahut bade numbers ke case mein dikkat aa sakti hai.)

✅ Alternate safe method:
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
(XOR swap method)

--------------------------------------------------------
*/
