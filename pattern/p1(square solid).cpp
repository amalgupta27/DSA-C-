#include<iostream>
using namespace std;

/*
==========================================
Logic in Hinglish (Samjhaane Wala Part):

✅ Step 1: User se ek positive integer 'n' lena hai.
✅ Step 2: Fir humein 'n' rows aur har row mein 'n' stars '*' print karne hain.
✅ Step 3: Har row ke baad ek nayi line (endl) print karna hai.

Example:
Input: 3
Output:
* * * 
* * * 
* * *

==========================================

🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
i = 1 se leke n tak loop chalao  (row ke liye)
   ↓
    j = 1 se leke n tak loop chalao  (har row mein stars ke liye)
         ↓
       "* " print karo
   ↓
Row complete hone ke baad ek nayi line (endl) print karo
   ↓
i++ (next row ke liye)
   ↓
[End]
==========================================
*/

int main() {
    int n;

    // Step 1: User se input lena hai
    cout << "Enter a positive integer: ";
    cin >> n;  // User input karega jaise 4

    // Step 2: Outer loop for rows (1 se n tak)
    for(int i = 1; i <= n; i++) {
        // Step 3: Inner loop for columns/stars (1 se n tak)
        for(int j = 1; j <= n; j++) {
            cout << "* ";  // Ek star print karna aur space dena
        }
        cout << endl;  // Har row ke baad ek nayi line print karna
    }

    return 0;
}
