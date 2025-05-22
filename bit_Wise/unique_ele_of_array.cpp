/*
📌 **Logic Explanation (Hinglish)**

🔹 **Samasya Ka Vivaran:**
Ek array diya gaya hai jismein kuch numbers repeat ho rahe hain, **sirf ek number aisa hai jo ek baar aata hai**. Hume us **unique number** ko dhoondhna hai.

🔹 **Approach (XOR Trick):** Here XOR used as commutative property
1️⃣ XOR (`^`) operation ka use karke **duplicate elements cancel ho jaate hain**.
2️⃣ Jo element sirf ek baar aayega **wohi bachega**.
3️⃣ XOR ki properties use kar rahe hain:
   - `a ^ a = 0` (koi bhi number apne aap se XOR hoke 0 ban jaata hai)
   - `a ^ 0 = a` (koi bhi number agar 0 se XOR ho, to wahi number aayega)
   
📊 **Flowchart Representation (Hinglish ASCII)**

Start
  |
  v
[Input: Array elements]
  |
  v
[Initialize res = 0]
  |
  v
[Loop through array & perform XOR]
  |
  v
[Unique number obtained]
  |
  v
[Print result]
  |
  v
End
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4,4,1,3,2,3,5,1,2};
    int n = sizeof(arr)/sizeof(arr[0]); // Array ka size nikal rahe hain
    
    int res = 0; // XOR store karne ke liye variable
    
    for(int i=0; i<n; i++){
        res = res ^ arr[i]; // Har element ko XOR kar rahe hain
    }
    
    cout << "Unique element: " << res << endl; // Jo ek baar aaya wahi output hoga
    
    return 0; 
}
