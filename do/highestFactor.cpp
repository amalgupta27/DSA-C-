// ✅ Problem: Find the highest factor (other than the number itself) of a given number
// ✅ Example: 
//     n = 90
//     Factors = {1, 2, 3, 5, 6, 9, 10, 15, 18, 30, 45, 90}
//     Highest proper factor = 45

/*
------------------------------------------------
                📈 Flow Chart (Hinglish)
------------------------------------------------
Start
   ↓
Input n
   ↓
Initialize i = n/2
   ↓
Repeat while (i >= 1):
   ↓
   Check if (n % i == 0)
        ↓
    If YES → return i (sabse bada factor mil gaya)
        ↓
    Else → i = i-1
   ↓
End Loop
↓
Return 1 (agar koi aur factor nahi mila)
*/

#include <iostream>
using namespace std;

// ✅ Function to find the highest proper factor
int highestProperFactor(int n) {
    // 🔴 Start i from n/2, kyunki ek number ka sabse bada proper factor maximum n/2 tak hi ho sakta hai
    for (int i = n / 2; i >= 1; i--) {
        // 🔵 Check karte hain ki i se n perfectly divide hota hai ya nahi
        if (n % i == 0) {
            return i; // ✅ Pehla factor mila → wahi sabse bada hoga
        }
        // ⚪ Else, i ko 1 se kam karte jaayenge
    }
    // ⚫ Agar koi bhi factor nahi mila, toh by default 1 return karte hain (har number ka factor hota hai)
    return 1;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n; // 🔵 User se input lete hain

    int highestFactor = highestProperFactor(n); // 🔵 Function ko call karte hain
    cout << "The highest proper factor of " << n << " is: " << highestFactor << endl; // ✅ Output

    return 0;
}
