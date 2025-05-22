#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- User se ek positive integer 'n' lena hai.
- X shape pattern banana hai using stars '*'.
- Jab:
   - i == j  (matlab row number == column number) ho ya
   - i + j == n + 1  (row + column == n + 1) ho
  tab '*' print karna hai.
- Baaki sab places pe " " (space) print karna hai.

Example:
Input: 5
Output:
*   *
 * * 
  *  
 * * 
*   *

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
         Agar (i == j) ya (i + j == n+1)
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

    // Step 2: Outer loop for rows (1 to n)
    for(int i = 1; i <= n; i++) {

        // Step 3: Inner loop for columns (1 to n)
        for(int j = 1; j <= n; j++) {

            // Step 4: Star kab print karna hai
            if(i == j || i + j == n + 1)
                cout << "*";  // Diagonal ya anti-diagonal pe '*'
            else
                cout << " ";  // Baaki jagah space print karo
        }

        // Step 5: Har row ke baad ek new line
        cout << endl;
    }

    return 0;
}
