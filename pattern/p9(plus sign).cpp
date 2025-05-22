#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive integer 'n' lena hai.
- Cross (plus '+') shape banana hai.
- Cross banane ke liye:
   - Middle row (i == mid) aur
   - Middle column (j == mid) par "*" print karna hai.
   - Baaki sab jagah space " " print karna hai.

mid = (n/2) + 1;   // Middle position calculate karte hain.

Example:
Input: 5
Output:
  *  
  *  
*****
  *  
  *  

==========================================
🛜 Flowchart in Hinglish:

[Start]
   ↓
User se 'n' input lo
   ↓
Calculate mid = n/2 + 1
   ↓
Outer loop i = 1 se n tak (rows ke liye)
   ↓
    Inner loop j = 1 se n tak (columns ke liye)
         ↓
         Agar (i == mid) ya (j == mid)
             → "*" print karo
         Nahi to
             → " " (space) print karo
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
    cin >> n;  // Example: input 5

    // Step 2: Calculate middle position
    int mid = n/2 + 1;  // Example: 5/2 + 1 = 3

    // Step 3: Outer loop for rows
    for(int i = 1; i <= n; i++) {

        // Step 4: Inner loop for columns
        for(int j = 1; j <= n; j++) {

            // Step 5: Agar current position middle row ya middle column hai
            if(i == mid || j == mid)
                cout << "*";  // Tab star print karenge
            else
                cout << " ";  // Warna space print karenge
        }

        // Step 6: Har row ke baad ek new line
        cout << endl;
    }

    return 0;
}
