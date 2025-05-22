#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- Har row mein pehle spaces print karo (n - i spaces).
- Phir uske baad i stars print karo.

Example for n = 5:

Row 1: 4 spaces + 1 star
Row 2: 3 spaces + 2 stars
Row 3: 2 spaces + 3 stars
Row 4: 1 space  + 4 stars
Row 5: 0 spaces + 5 stars

Output:
    *
   **
  ***
 ****
*****

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
    Inner loop k = 1 to i (stars ke liye)
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
    cin >> n;  // Example: n = 5

    // Step 2: Outer loop for rows
    for(int i = 1; i <= n; i++) {

        // Step 3: Inner loop for spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";  // space print karna
        }

        // Step 4: Inner loop for stars
        for(int k = 1; k <= i; k++) {
            cout << "*";  // star print karna
        }

        // Step 5: Row complete hone ke baad ek new line
        cout << endl;
    }

    return 0;
}
