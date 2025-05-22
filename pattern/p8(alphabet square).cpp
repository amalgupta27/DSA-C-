#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive integer 'n' lena hai.
- 'n' rows aur 'n' columns print karne hain.
- Har column mein A, B, C... print karna hai using ASCII conversion.
- ASCII Table:
    - A = 65
    - B = 66
    - C = 67
    - and so on...

char(j + 64) se j ke hisaab se character milega.

Example:
Input: 4
Output:
A B C D
A B C D
A B C D
A B C D

==========================================
🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
Outer loop i = 1 se n tak (rows ke liye)
   ↓
    Inner loop j = 1 se n tak (columns ke liye)
        ↓
        char(j + 64) print karo
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

    // Step 1: User se input lena
    cout << "Enter a positive integer: ";
    cin >> n;  // Example: input 4

    // Step 2: Outer loop for rows (i = 1 to n)
    for(int i = 1; i <= n; i++) {

        // Step 3: Inner loop for columns (j = 1 to n)
        for(int j = 1; j <= n; j++) {

            // Step 4: j+64 ko char mein convert karke print karna
            cout << char(j + 64) << " ";
        }

        // Step 5: Har row ke baad ek new line (nayi line)
        cout << endl;
    }

    return 0;
}
