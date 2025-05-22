/*
👋 Identical Twins Problem (Hinglish Explanation for Beginners)

🧠 Problem Statement:
Humein ek array diya gaya hai, jaise: {3, 4, 2, 3, 7, 2}
Isme humein aise elements dhoondhne hain jo 2 ya usse zyada baar aaye ho — unko print karna hai.

🧠 Logic:
1. Har element ko ek-ek karke left to right check karenge.
2. Pehle ye check karenge ki kya ye element pehle already check/print ho chuka hai.
3. Agar nahi hua hai, to aage jaake dekhenge ki ye kitni baar repeat ho raha hai.
4. Agar count 2 ya zyada hai, to use output karenge.

🔁 Flowchart (Hinglish):
Start
  ↓
Array lo → {3, 4, 2, 3, 7, 2}
  ↓
For loop i = 0 to size-1:
  ↓
  Kya arr[i] pehle aa chuka hai?
     ↓ Yes → Continue (skip karo)
     ↓ No  → Count karo aage se
                ↓
          Kya count >= 2 hai?
             ↓ Yes → Print karo
             ↓ No  → Kuch mat karo
  ↓
Repeat for all elements
  ↓
End
*/

#include <iostream>
using namespace std;

int main() {
    // Step 1: Array define kiya
    int arr[] = {3, 4, 2, 3, 7, 2};
    int size = sizeof(arr) / sizeof(arr[0]); // array ka size nikaala

    cout << "Identical pairs (twins):" << endl;

    // Outer loop: Har element ko check karne ke liye
    for (int i = 0; i < size; i++) {
        bool alreadyPrinted = false;

        /*
        🔍 Step 2: Check karo ki kya arr[i] pehle aa chuka hai?

        Example: arr[] = {3, 4, 2, 3, 7, 2}
        Suppose i = 3 → arr[3] = 3
        Pehle wale elements: arr[0], arr[1], arr[2]
        arr[0] = 3 → match mil gaya ✅ → iska matlab 3 pehle aa chuka hai → skip karo

        Yeh loop sirf isliye hai taaki koi element baar-baar na print ho
        */
        for (int k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                alreadyPrinted = true;  // agar pehle mil gaya to mark karo
                break;  // aur break kar do, kyunki ek baar milna kaafi hai
            }
        }

        if (alreadyPrinted) {
            // Agar pehle hi print ho chuka hai to skip karo
            continue;
        }

        /*
        🔢 Step 3: Agar element pehli baar mila hai,
        to ab uska count nikaalo ki ye aage kitni baar aata hai.

        Example: i = 0, arr[0] = 3
        j = 1 to 5 tak check karenge:
        arr[3] = 3 → ✅ match → count++

        ⚠️ Difference from previous loop:
        - Pehla loop (k) → check karta hai ki pehle aa chuka ya nahi
        - Yeh loop (j) → count karta hai ki baad mein kitni baar aaya
        */

        int count = 1; // khud ke liye ek baar count

        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;  // agar match mila to count++
            }
        }

        // Step 4: Agar element 2 ya usse zyada baar aaya ho to print karo
        if (count >= 2) {
            cout << arr[i] << " appears " << count << " times." << endl;
        }
    }

    return 0;
}
