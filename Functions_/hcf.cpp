#include<iostream> // Input-Output ke liye
#include<cmath>    // Math functions ke liye (yahan abhi use nahi hua but useful hota hai future mein)
using namespace std;

/*
----------------------------------------------
🔵 PROBLEM LOGIC (Hinglish + Simple Words):

🔹 Hume do numbers ka GCD (Greatest Common Divisor) ya HCF (Highest Common Factor) nikalna hai.
   - Example: a = 12, b = 15
   - 12 ke factors: 1, 2, 3, 4, 6, 12
   - 15 ke factors: 1, 3, 5, 15
   - Common factors: 1, 3
   - Greatest common factor: 3

🔹 Approach:
   - Hum min(x, y) se start karenge aur check karenge kaunsa number dono ko divide karta hai.
   - Jaise hi mil jaaye, wahi GCD hoga.

----------------------------------------------
🔵 FLOWCHART (ASCII Diagram in Hinglish):

[Start]
   |
   v
[Input a aur b lo]
   |
   v
[min(a,b) find karo]
   |
   v
[i = min(a,b) se 1 tak loop chalao]
   |
   v
[Check karo: (a % i == 0 && b % i == 0)]
   |
   v
[Agar haan -> hcf = i, break]
   |
   v
[Return hcf]
   |
   v
[End]

----------------------------------------------
🔵 Important Points:
- Loop min(a,b) se start karte hain kyunki GCD kabhi bhi min(a,b) se bada nahi hota.
- Jitni jaldi common divisor mile, utni jaldi break karte hain (optimization).
- HCF aur GCD ek hi cheez hai.
----------------------------------------------
*/

// 🔹 Function to find GCD (Highest Common Factor)
int gcd(int x, int y) {
    int hcf = 1; // hcf ko 1 se initialize kiya

    // 🔹 min(x,y) se 1 tak loop chalate hain reverse order mein
    for (int i = min(x,y); i >= 1; i--) {
        
        // 🔹 Check karte hain kya i dono numbers ko divide karta hai
        if(x % i == 0 && y % i == 0) {
            hcf = i; // 🔹 Agar karta hai to wohi hcf hoga
            break; // 🔹 Hume sabse bada common divisor chahiye, isliye break karte hain
        }
    }

    return hcf; // 🔹 Final answer return
}

// 🔹 Main function
int main() {
    int a;
    cout << "Enter first number : ";
    cin >> a; // 🔹 First number input

    int b;
    cout << "Enter second number : ";
    cin >> b; // 🔹 Second number input

    cout << gcd(a,b); // 🔹 GCD function call karke answer print
}

/*
----------------------------------------------
🔵 Example Dry Run:

Input:
a = 24
b = 36

min(a,b) = 24

Loop:
i = 24 -> 24%24==0 && 36%24!=0 (fail)
i = 23 -> fail
i = 22 -> fail
.
.
i = 12 -> 24%12==0 && 36%12==0 (pass)

--> hcf = 12
--> break loop

Output:
12

----------------------------------------------
*/
