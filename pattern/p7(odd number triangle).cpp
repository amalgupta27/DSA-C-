#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive integer 'n' input lena hai.
- 'n' rows print karni hain.
- Har row mein pehle 'i' odd numbers print karne hain.

Example:
Input: 4
Output:
1
1 3 5
1 3 5 7 9
1 3 5 7 9 11 13

==========================================
🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
Outer loop i = 1 se n tak (rows ke liye)
   ↓
    Inner loop j = 1 se (2*i - 1) tak, step size 2
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
    cin >> n;  // Example: input 4

    // Step 2: Outer loop for rows (i = 1 to n)
    for(int i = 1; i <= n; i++) {

        // Step 3: Inner loop for printing first 'i' odd numbers
        // j = 1 se shuru hoga aur 2*i-1 tak jayega, step size 2 (odd numbers ke liye)
        for(int j = 1; j <= 2*i-1; j += 2) {
            cout << j << " ";  // odd number print karenge space ke saath
        }

        // Step 4: Har row ke baad ek new line (nayi line)
        cout << endl;
    }

    return 0;
}
