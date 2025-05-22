#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive integer 'n' input lena hai.
- Fir 'n' rows print karni hain.
- Row number 'i' mein 'n+1-i' number of '*' print karenge.

Example:
Input: 5
Output:
*****
****
***
**
*

==========================================
🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
Outer loop i = 1 se n tak (rows ke liye)
   ↓
    Inner loop j = 1 se (n+1-i) tak (stars ke liye)
         ↓
         "*" print karo
   ↓
Row complete hone ke baad ek nayi line (endl)
   ↓
i++ (next row)
   ↓
[End]
==========================================
*/

int main() {
    int n;

    // Step 1: User se ek positive integer input lena
    cout << "Enter a positive integer: ";
    cin >> n;  // Jaise input 5 diya

    // Step 2: Outer loop for rows (i = 1 to n)
    for(int i = 1; i <= n; i++) {

        // Step 3: Inner loop for printing stars
        // Har row mein n+1-i stars print karne hain
        for(int j = 1; j <= n+1-i; j++) {
            cout << "*";  // ek ek star print hoga
        }

        // Step 4: Har row ke baad nayi line mein jaao
        cout << endl;
    }

    return 0;
}
