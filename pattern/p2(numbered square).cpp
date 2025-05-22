#include<iostream>
using namespace std;

/*
==========================================
Logic in Hinglish (Samjhaane Wala Part):

✅ Step 1: User se ek positive integer 'n' lena hai.
✅ Step 2: Outer loop (i) se 1 se n tak jao → rows ke liye
✅ Step 3: Har row ke starting mein "Row number i: " print karo
✅ Step 4: Fir inner loop (j) se 1 se n tak numbers print karo
✅ Step 5: Har row ke baad endl lagao taaki nayi line mein jaaye

Example:
Input: 3
Output:
Row number 1: 123
Row number 2: 123
Row number 3: 123

==========================================

🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
i = 1 se n tak chalao (rows ke liye)
   ↓
    "Row number i:" print karo
    ↓
    j = 1 se n tak chalao (columns ke liye)
        ↓
       j print karo
    ↓
Row khatam → endl se nayi line
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
    cin >> n;  // Example: user ne 4 input kiya

    // Step 2: Outer loop (for rows)
    for(int i = 1; i <= n; i++) {
        
        // Step 3: Row ke starting mein 'Row number i:' print karna
        cout << "Row number " << i << ": ";

        // Step 4: Inner loop (for printing 1 se n tak numbers)
        for(int j = 1; j <= n; j++) {
            cout << j;  // j print hoga, side by side
        }

        // Step 5: Har row complete hone ke baad ek nayi line mein jaate hain
        cout << endl;
    }

    return 0;
}
