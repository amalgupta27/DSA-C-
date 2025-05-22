#include<iostream>
using namespace std;

/*
===========================
🧠 LOGIC IN HINGLISH:

- Pehli line me 2n-1 stars print karna hai.
- Uske baad:
   - Left side stars ghate hain
   - Beech me spaces badhte hain
   - Right side stars ghate hain

Example for n=4:

*******
*** ***
**   **
*     *

===========================
*/

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;  // Example: n=4

    // Step 1: Print 2n-1 stars in the first line
    for(int i = 0; i < 2*n-1; i++) {
        cout << "*";
    }
    cout << endl;

    // Step 2: Variables
    int m = n-1;    // m = number of rows in lower half
    int nsp = 1;    // nsp = number of spaces (initially 1)

    // Step 3: Print rest of the pattern
    for(int i = 1; i <= m; i++) {

        // Print left stars
        for(int j = 1; j <= m-i+1; j++) {  
            cout << "*";
        }

        // Print spaces
        for(int k = 1; k <= nsp; k++) {
            cout << " ";
        }

        // Increase number of spaces by 2
        nsp += 2;

        // Print right stars
        for(int j = 1; j <= m-i+1; j++) {  
            cout << "*";
        }

        // Move to next line
        cout << endl;
    }

    return 0;
}
