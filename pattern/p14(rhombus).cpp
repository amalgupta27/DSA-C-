#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- Har row mein (n-i) spaces print karo.
- Har row mein exactly 'n' stars print karo.

Example for n = 4:

Row 1: 3 spaces + 4 stars
Row 2: 2 spaces + 4 stars
Row 3: 1 space  + 4 stars
Row 4: 0 spaces + 4 stars

Output:
   ****
  ****
 ****
****

==========================================
🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
Outer loop i = 1 to n (rows ke liye)
   ↓
    Inner loop j = 1 to (n-i) (spaces ke liye)
       ↓
       Print " "
   ↓
    Inner loop k = 1 to n (stars ke liye)
       ↓
       Print "*"
   ↓
Row complete hone ke baad new line (endl)
   ↓
[End]
==========================================
*/

int main() {
    int n;

    // Step 1: User se input lena
    cout << "Enter a positive integer: ";
    cin >> n;  // Example: n = 4

    // Step 2: Outer loop for rows
    for(int i = 1; i <= n; i++) {

        // Step 3: Inner loop for spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";  // space print karna
        }

        // Step 4: Inner loop for stars (n stars har row mein)
        for(int k = 1; k <= n; k++) {
            cout << "*";  // star print karna
            // Agar numbers chahiye toh cout << k; use kar sakte hain
        }

        // Step 5: Row complete hone ke baad ek new line
        cout << endl;
    }

    return 0;
}
