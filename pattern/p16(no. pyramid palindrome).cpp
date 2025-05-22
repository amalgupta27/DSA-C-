#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- Har row mein:
  1. (n-i) spaces print karo.
  2. 1 se i tak increasing numbers print karo.
  3. (i-1) se 1 tak decreasing numbers print karo.

Example for n = 4:

Row 1: "   1"
Row 2: "  121"
Row 3: " 12321"
Row 4: "1234321"

==========================================
📈 FLOWCHART (Hinglish):

[Start]
   ↓
User se 'n' input lo
   ↓
Outer loop i = 1 to n
   ↓
    Space print loop (j = 1 to n-i)
    Number increasing loop (k = 1 to i)
    Number decreasing loop (l = i-1 to 1)
   ↓
Print newline
   ↓
[End]
==========================================
*/

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;  // Example: n = 4

    // Step 1: Outer loop for rows
    for(int i = 1; i <= n; i++) {
        
        // Step 2: Spaces before numbers
        for(int j = 1; j <= n - i; j++) {
            cout << " ";  // Print space
        }
         
        // Step 3: Increasing numbers from 1 to i
        for(int k = 1; k <= i; k++) {
            cout << k;  // Print numbers in ascending
        }

        // Step 4: Decreasing numbers from i-1 to 1
        for(int l = i-1; l >= 1; l--) {
            cout << l;  // Print numbers in descending
        }
        
        // Step 5: Row complete, move to next line
        cout << endl;
    }
 
    return 0;
}
