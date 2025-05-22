#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive number 'n' input lo.
- 'n' rows print karni hain.
- Row number 'i' mein 'i' number of '*' (stars) print karne hain.

Example:
Input: 5
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
Outer loop i = 1 se n tak (rows ke liye)
   ↓
    Inner loop j = 1 se i tak (stars ke liye)
         ↓
         "*" print karo
   ↓
Row complete hone ke baad ek nayi line (endl) print karo
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
    cin >> n;  // jaise input 5 diya

    // Step 2: Outer loop for rows (i = 1 to n)
    for(int i = 1; i <= n; i++) {

        // Step 3: Inner loop for printing stars (j = 1 to i)
        for(int j = 1; j <= i; j++) {
            cout << "*";  // har baar ek star print hoga
        }

        // Step 4: Har row complete hone ke baad nayi line
        cout << endl;
    }

    return 0;
}
