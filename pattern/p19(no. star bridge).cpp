#include<iostream>
using namespace std;

/*
===========================
🧠 LOGIC IN HINGLISH:

- Pehle line me 1 se (2n-1) tak numbers print karna hai.
- Fir neeche:
   - Left numbers kam hote hain
   - Beech me spaces badhte hain
   - Right numbers increment hote hain

Example for n=4:

1234567
123 456
12   78
1     9

===========================
*/

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;  // Example: n=4

    // Step 1: Print numbers from 1 to (2n-1)
    for(int i = 1; i < 2*n; i++) {
        cout << i;
    }
    cout << endl;

    // Step 2: Variables
    int m = n-1;    // m = number of rows after first line
    int nsp = 1;    // nsp = number of spaces (initially 1)

    // Step 3: Print rest of the pattern
    for(int i = 1; i <= m; i++) {

        int a = 1;  // Starting number for each line

        // Left Numbers
        for(int j = 1; j <= m-i+1; j++) {  
            cout << a;
            a++;
        }

        // Middle Spaces (and increase 'a' during spaces)
        for(int k = 1; k <= nsp; k++) {
            cout << " ";
            a++;
        }

        // Increase number of spaces by 2 after every line
        nsp += 2;

        // Right Numbers
        for(int j = 1; j <= m-i+1; j++) {  
            cout << a;
            a++;
        }

        // Move to next line
        cout << endl;
    }

    return 0;
}
