#include <iostream>
using namespace std;

/*
📚 ✅ Problem Understanding (Hinglish Explanation):

🔹 Humein diya gaya hai ek number `n` aur `r`.
🔹 Humein calculate karna hai:
    - **nCr** = "n choose r"  = kitne tareeko se r cheezein n me se choose kar sakte hain (order matter nahi karta).
    - **nPr** = "n permute r" = kitne tareeko se r cheezein n me se arrange kar sakte hain (order matter karta hai).

🔹 **Formulae:**
    - nCr = n! / (r! * (n-r)!)
    - nPr = n! / (n-r)!

🔹 **Example:**
    - Suppose `n = 5`, `r = 2`
    - 5C2 = 5! / (2! * (5-2)!) = 120 / (2 * 6) = 120/12 = 10
    - 5P2 = 5! / (5-2)! = 120 / 6 = 20

🔹 **Factorial kya hota hai?**
    - Factorial of a number `x` = x * (x-1) * (x-2) * ... * 1
    - Example: 5! = 5×4×3×2×1 = 120

---------------------------------------------------

📊 ✅ Flowchart (ASCII style in Hinglish):

Start
 |
 v
[Input lo n aur r]
 |
 v
[Fact(n) calculate karo]
 |
 v
[Fact(r) calculate karo]
 |
 v
[Fact(n-r) calculate karo]
 |
 v
[nCr = n! / (r! * (n-r)!)]
 |
 v
[nPr = n! / (n-r)!]
 |
 v
[Print nCr aur nPr]
 |
 v
End

---------------------------------------------------
*/

/// Function to calculate factorial of a number
int fact(int x){
    int f = 1;
    // 2 se x tak multiply karte hain
    for(int i = 2; i <= x; i++){
        f *= i; // f = f * i
    }
    return f; // final factorial return
}

int main(){
    int n;
    cout << "Enter n : "; 
    cin >> n; // n input lo
    int r;
    cout << "Enter r : "; 
    cin >> r; // r input lo

    // Factorials calculate karo
    int nfact = fact(n);     // n!
    int rfact = fact(r);     // r!
    int nr = fact(n-r);      // (n-r)!

    // nCr formula apply
    cout << "nCr = " << nfact / (rfact * nr) << endl;
    // nPr formula apply
    cout << "nPr = " << nfact / nr << endl;

    return 0;
}

/*
🚀 ✅ Quick Example Dry Run:

Input:
n = 5
r = 2

Calculation:
nfact = 5! = 120
rfact = 2! = 2
nr = (5-2)! = 3! = 6

nCr = 120 / (2*6) = 120/12 = 10
nPr = 120 / 6 = 20

Output:
nCr = 10
nPr = 20

✅
*/
