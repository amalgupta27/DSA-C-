#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- Har row mein numbers print karna hai (0 aur 1).
- Rule:
   - (i+j) agar even hai to 1 print karo
   - (i+j) agar odd hai to 0 print karo

Example for n = 5:

Row 1: (1,1) → 2 → even → 1
Row 2: (2,1)=3→odd(0), (2,2)=4→even(1)
Row 3: (3,1)=4→even(1), (3,2)=5→odd(0), (3,3)=6→even(1)
Row 4: (4,1)=5→odd(0), (4,2)=6→even(1), (4,3)=7→odd(0), (4,4)=8→even(1)
Row 5: (5,1)=6→even(1), (5,2)=7→odd(0), (5,3)=8→even(1), (5,4)=9→odd(0), (5,5)=10→even(1)

Output:
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1

==========================================
🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
Outer loop i = 1 se n tak (rows ke liye)
   ↓
    Inner loop j = 1 se i tak (row ke elements ke liye)
         ↓
         Check (i+j) % 2 == 0 ?
            ↓Yes
            Print 1
            ↓No
            Print 0
   ↓
Row complete hone ke baad ek nayi line (endl)
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

        // Step 3: Inner loop for elements in the row
        for(int j = 1; j <= i; j++) {

            // Step 4: Check (i+j) % 2
            if((i + j) % 2 == 0) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }

        // Step 5: Row complete hone ke baad ek new line
        cout << endl;
    }

    return 0;
}
