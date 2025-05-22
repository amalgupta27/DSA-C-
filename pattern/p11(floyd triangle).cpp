#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive integer 'n' lena hai.
- Numbers ko 1 se lekar continuously print karna hai 
  triangle ke shape mein.
- Har row mein jitna row ka number hai (i.e., row 3 mein 3 numbers).
- Ek variable 'k' use karenge jo 1 se start hoke 
  har number ke baad 1 se badhta rahega.

Example:
Input: 5
Output:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

==========================================
🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
k = 1 initialize karo
   ↓
Outer loop i = 1 se n tak (rows ke liye)
   ↓
    Inner loop j = 1 se i tak (current row ke elements ke liye)
         ↓
         k print karo
         ↓
         k = k + 1
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
    cin >> n;  // Example: n = 5

    int k = 1; // Step 2: k variable initialize, jo 1 se start hoga

    // Step 3: Outer loop for rows
    for(int i = 1; i <= n; i++) {

        // Step 4: Inner loop for columns (kitne numbers print karne hain)
        for(int j = 1; j <= i; j++) {

            cout << k << " "; // Current number print karo
            k++; // k ko badhao (next number ke liye)
        }

        // Step 5: Row complete hone ke baad ek new line
        cout << endl;
    }

    return 0;
}
