#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- Har row mein:
  1. (n-i) spaces print karni hain.
  2. (2*i-1) stars print karne hain.

Example for n = 4:

Row 1: 3 spaces + 1 star
Row 2: 2 spaces + 3 stars
Row 3: 1 space  + 5 stars
Row 4: 0 spaces + 7 stars

Output:
   *
  ***
 *****
*******

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
    Inner loop j = 1 to (2*i-1) (stars ke liye)
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

        // Step 3: Inner loop to print spaces (n-i spaces)
        for(int j = 1; j <= n - i; j++) {
            cout << " ";  // Print a space
        }

        // Step 4: Inner loop to print stars (2*i-1 stars)
        for(int j = 1; j <= 2*i - 1; j++) {
            cout << "*";  // Print a star
        }

        // Step 5: Row complete, move to next line
        cout << endl;
    }

    return 0;
}
