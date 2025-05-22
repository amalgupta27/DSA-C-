/*
    -------------------------------------------------------------
    Fibonacci Sequence Program - Hinglish Explanation & Flowchart
    -------------------------------------------------------------

    Logic (Hinglish mein):
    1. User se ek positive integer n input lete hain.
    2. Fibonacci sequence ke pehle do numbers fix hote hain: 0 aur 1.
    3. Har next number previous do numbers ka sum hota hai.
    4. Hum n terms tak sequence print karenge.

    Example:
    Agar n = 5 diya, toh output hoga: 0 1 1 2 3 5 8
    (0 aur 1 fix, fir 0+1=1, 1+1=2, 1+2=3, 2+3=5, 3+5=8...)

    -------------------------------------------------------------
    Flow Chart (Hinglish mein):

    +-------------------------------+
    |   Start                       |
    +-------------------------------+
                |
                v
    +-------------------------------+
    |   User se n input lo          |
    +-------------------------------+
                |
                v
    +-------------------------------+
    |   a = 0, b = 1 set karo       |
    +-------------------------------+
                |
                v
    +-------------------------------+
    |   Print a aur b               |
    +-------------------------------+
                |
                v
    +-------------------------------+
    |   i = 1 se n tak repeat karo  |
    +-------------------------------+
                |
                v
    +-------------------------------+
    |   sum = a + b                 |
    |   Print sum                   |
    |   a = b                       |
    |   b = sum                     |
    +-------------------------------+
                |
                v
    +-------------------------------+
    |   End                         |
    +-------------------------------+

    -------------------------------------------------------------
    Time Complexity:
    - Is program ki time complexity O(n) hai, kyunki loop n times chalta hai.
    - Har iteration mein sirf addition aur assignment ho raha hai.

    -------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // Example: Agar user n = 5 deta hai, toh output: 0 1 1 2 3 5 8
    // a = 0, b = 1 (pehle do numbers)
    int a = 0, b = 1;
    int sum;

    cout << "Fibonacci sequence up to " << n << " terms:" << endl;
    cout << a << " " << b << " ";  // Pehle do terms print kar diye

    // Loop n times chalega, har bar next term calculate karega
    for (int i = 2; i <= n; i++) {
        sum = a + b;      // Next term = previous do terms ka sum
        cout << sum << " "; // Print karo next term
        a = b;            // a ko update karo (ab b ban gaya)
        b = sum;          // b ko update karo (ab sum ban gaya)
        // Example: 0 1 1 2 3 5 8 ...
    }

    // Program end ho gaya, sari terms print ho gayi
    return 0;
}