#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive integer 'n' input lena hai.
- 'n' rows print karni hain.
- Har row ke starting mein likhna hai: "Row number i: "
- Fir har row mein 'i' number ko 'i' times print karna hai.

Example:
Input: 5
Output:
Row number  1: 1
Row number  2: 22
Row number  3: 333
Row number  4: 4444
Row number  5: 55555

==========================================
🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
Outer loop i = 1 se n tak (rows ke liye)
   ↓
    "Row number i: " print karo
   ↓
    Inner loop j = 1 se i tak (i ko print karne ke liye)
         ↓
         i print karo
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
    cin >> n;  // Example: input 5

    // Step 2: Outer loop for rows (i = 1 to n)
    for(int i = 1; i <= n; i++) {

        // Step 3: Har row ke starting mein "Row number i:" print karna
        cout << "Row number  " << i << ": ";

        // Step 4: Inner loop for printing 'i' number 'i' times
        for(int j = 1; j <= i; j++) {
            cout << i;  // 'i' print kar rahe hain har column mein
        }

        // Step 5: Har row ke baad ek new line (nayi line)
        cout << endl;
    }

    return 0;
}
