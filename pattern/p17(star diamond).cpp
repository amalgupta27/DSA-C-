#include<iostream>
using namespace std;

/*
==========================================
🧠 LOGIC IN HINGLISH:

- Diamond shape print karna hai using stars (*).
- Pehle stars badhenge, fir ghatenge.
- 'nsp' = spaces aur 'nst' = stars control karte hain row wise.

Example for n = 4:

   *
  ***
 *****
*******
 *****
  ***
   *

==========================================
📈 FLOWCHART (Hinglish):

[Start]
↓
Input n
↓
Initialize nsp = n-1, nst = 1
↓
for i=1 to 2n-1:
    1. Print nsp spaces
    2. Print nst stars
    3. New line
    4. Agar i < n:
         nsp--, nst+=2
       warna:
         nsp++, nst-=2
↓
[End]
==========================================
*/

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;  // Example: n = 4

    int nst = 1;   // Number of stars (start with 1 star)
    int nsp = n-1; // Number of spaces (start with n-1 spaces)

    // Step 1: Outer loop to control total 2*n-1 rows
    for(int i = 1; i <= 2*n-1; i++) {

        // Step 2: Print spaces first
        for(int j = 1; j <= nsp; j++) {
            cout << " "; 
        }

        // Step 3: Print stars
        for(int k = 1; k <= nst; k++) {
            cout << "*";
        }

        // Step 4: Move to next line after completing row
        cout << endl;

        // Step 5: Adjust nsp and nst based on current row
        if(i < n) {
            // Top half of diamond
            nst += 2;  // Stars badhao
            nsp -= 1;  // Space kam karo
        }
        else {
            // Bottom half of diamond
            nst -= 2;  // Stars ghatao
            nsp += 1;  // Space badhao
        }
    }

    return 0;
}
