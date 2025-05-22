/*
--------------------------------------------
LOGIC OF THE QUESTION (HINGLISH MEIN SAMAJHIYE)
--------------------------------------------
Humein ek array diya gaya hai, jismein kuch numbers hain.
Humein ye find karna hai ki kaunsa number **max sabse zyada baar** repeat ho raha hai, // max bitwise AND value.
Aur wo kitni baar occur ho raha hai.

Example:
----------
Input: {12, 3, 1, 6, 1, 6, 6, 6, 4, 3, 8, 13, 13, 13, 13, 8}
Output: 13 appears 4 times.

Logic:
---------
1. **Ek maxe variable rakhenge**, jo track karega **sabse bada number** jo mila.
2. **Ek count variable rakhenge**, jo track karega ki wo number **kitni baar aya** hai.
3. **Loop chalayenge** pura array par:
   - Agar koi number **maxe se bada hai**, toh maxe update karenge aur count `1` set karenge.
   - Agar koi number **maxe ke barabar hai**, toh count badhayenge.
   - `ans` variable use karenge **maximum occurrence store karne ke liye**.
4. **Last mein maxe aur ans print karenge.**

--------------------------------------------
FLOWCHART (HINGLISH MEIN)
--------------------------------------------

1. START
2. maxe = INT_MIN, count = 0, ans = 0 set karo
3. Loop chalao **i = 0 se n tak**
4. Agar **arr[i] > maxe**, toh maxe = arr[i] aur count = 1 karo
5. Agar **arr[i] == maxe**, toh count badhao
6. ans = max(ans, count)
7. Loop ke baad maxe aur ans print karo
8. END

--------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {12, 3, 1, 6, 1, 18, 18, 6, 4, 3, 8, 13, 13, 13, 13, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int ans = 0; // Maximum occurrence store karne ke liye
    int maxe = INT_MIN; // Sabse bada element store karne ke liye
    int count = 0; // Maximum element ka count
    
    // Array traverse karna hai
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxe) {
            // Agar naya max element milta hai, toh usko update karenge
            // Example: Pehle maxe = INT_MIN tha, phir 12 mila toh maxe = 12 ho gaya
            maxe = arr[i];
            count = 1; // Naya element 1 baar mila
        }
        else if (arr[i] == maxe) {
            // Agar max element dobara milta hai, toh count badhayenge
            // Example: Pehle maxe = 12, aur 12 firse mila toh count = 2 ho gaya
            count++;
        }
        ans = max(ans, count); // Maximum occurrence track kar rahe hain
    }
    
    // Loop complete hone ke baad maxe mein wo element hoga jo sabse zyada mila
    // ans mein uski frequency hogi
    
    // Answer print karo
    cout << "The element that appears most frequently is " << maxe 
         << " and it appears " << ans << " times." << endl;
    
    return 0;
}
