#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive integer 'n' input lo.
- 'n' rows print karni hain.
- Har row ke starting mein likhna hai: "Row number i: "
- Fir us row mein numbers 1 se lekar i tak print karne hain.

Example:
Input: 5
Output:
Row number  1: 1
Row number  2: 12
Row number  3: 123
Row number  4: 1234
Row number  5: 12345

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
    Inner loop j = 1 se i tak (numbers ke liye)
         ↓
         j print karo
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

    // Step 1: User se positive integer input lena
    cout << "Enter a positive integer: ";
    cin >> n;  // Jaise input 5 diya

    // Step 2: Outer loop for rows (i = 1 to n)
    for(int i = 1; i <= n; i++) {
        
        // Step 3: Har row ke starting mein "Row number i:" print karna
        cout << "Row number  " << i << ": ";

        // Step 4: Inner loop for printing numbers from 1 to i
        for(int j = 1; j <= i; j++) {
            cout << j;  // har column mein j print ho raha hai
        }

        // Step 5: Har row ke baad ek new line (nayi line)
        cout << endl;
    }

    return 0;
}
