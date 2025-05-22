/*
-------------------------------------------------------------
🧠 LOGIC OF THE QUESTION (Hinglish Explanation with Flow Chart)
-------------------------------------------------------------
👉 Problem: Ek array diya gaya hai. Humein recursive function ka use karke uska maximum element find karna hai.

✅ Recursive Approach:
- Hum ek function banate hain jo har element ko check kare aur max value update karta rahe.
- Har step pe:
   1. Check karo: kya current element max se bada hai?
   2. Agar haan, toh max ko update karo.
   3. Phir agle index pe jaane ke liye recursive call karo.

➡️ Base Case: Jab index array ke end tak pahuch jaaye (i.e., idx == n), tab hum max print kar denge.

📦 Initial Call: idx = 0 se start karenge, aur max = INT_MIN rakhenge.

----------------------------------------
📊 FLOWCHART (Hinglish mein):
----------------------------------------
         +------------------------+
         |   Function Call Start  |
         +-----------+------------+
                     |
                     v
         +------------------------+
         |  Kya idx == n hai?     |
         +-----------+------------+
                     |
            No       |     Yes
                     v
       +-----------------------------+
       |  Kya arr[idx] > max hai?   |
       +-----------+----------------+
                   |
         No        |      Yes
         |         v
         |     max = arr[idx]
         v         
+--------------------------+
| Recursive call with     |
| idx + 1 and updated max |
+--------------------------+
                     |
                     v
              (Repeat Again)

Agar idx == n ho jaaye:
+-------------------+
| Print max value   |
+-------------------+

*/

#include <bits/stdc++.h> // Sabhi standard C++ libraries include karta hai
using namespace std;

// ✅ Recursive function to find maximum value in array
// Parameters:
// arr[]: input array
// n: array ka size
// idx: current index
// max: ab tak ka maximum value
void printMax(int arr[], int n, int idx, int max) {
    if (idx == n) {  // 🛑 Base Case: jab index array ke size ke barabar ho jaaye
        cout << "Maximum value is: " << max << endl; // max value print karo
        return; // recursion khatam
    }

    // ✅ Agar current element max se bada ho to max update karo
    if (arr[idx] > max) {
        max = arr[idx];
    }

    // 🔁 Recursive call for next index
    printMax(arr, n, idx + 1, max);
}

int main() {
    // 🔢 Input array
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};

    // 🔢 Array ka size calculate karna
    int n = sizeof(arr) / sizeof(arr[0]);

    // 🚀 Function call with initial index 0 and max = INT_MIN
    printMax(arr, n, 0, INT_MIN);

    return 0;
}

/*
✅ Sample Output:
Maximum value is: 60

✅ Example Flow:
Array: [10, 22, 9, 33, 21, 50, 41, 60]
- Initial max = -inf
- 10 > -inf -> max = 10
- 22 > 10 -> max = 22
- 9 < 22 -> max = 22
- 33 > 22 -> max = 33
- 21 < 33 -> max = 33
- 50 > 33 -> max = 50
- 41 < 50 -> max = 50
- 60 > 50 -> max = 60
-> Final Output: 60
*/
