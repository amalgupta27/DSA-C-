/*
📌 Samasya Ka Bayaan (Hindi)
Hume ek **integer `x`** diya gaya hai aur hume **`x` ke andar wali sabse badi `power of 2`** nikalni hai.

🔹 Example:
    Input: 10 (Binary: 1010)
    Output: 8 (Binary: 1000)  ✅

🛠 Tarkika (`n & (n-1)` technique ka use):
1️⃣ **`n & (n-1)`** ek technique hai jo sabse **rightmost set bit (1) ko hata deti hai**.
2️⃣ Jab tak `x != 0` hai, hum is operation ko chalayenge.
3️⃣ Jo **last value `temp` me store hogi wahi maximum power of 2** hogi.

📊 Flowchart (Hinglish ASCII Representation)

Start
  |
  v
[Input: Enter x]
  |
  v
[Loop: Jab tak x!=0]
  |
  |---> [temp = x store karna]
  |---> [x = (x & (x-1)) apply karna]
  |
  v
[Print temp (max power of 2)]
  |
  v
End

📝 `x = (x & (x-1))` ka deep explanation:
👉 Ye operation **LSB (Least Significant Set Bit) jo `1` hai usko remove karta hai**

🔹 Example: x = 10 (Binary: 1010)
Step 1:  `x = 10`  (Binary: 1010)
         `x-1 = 9`  (Binary: 1001)
         `x & (x-1) = 1010 & 1001 = 1000`  (x ab 8 ho gaya)

Step 2:  `x = 8`   (Binary: 1000)
         `x-1 = 7`  (Binary: 0111)
         `x & (x-1) = 1000 & 0111 = 0000`  (x ab 0 ho gaya, loop stop)

🛠 Har baar operation se ek `1` bit remove ho rahi hai!

📢 **Binary Representation me Right to Left Traverse ka Logic:**
👉 Jab hum `x` ki binary dekhte hain, toh right se left jaate waqt sabse **badi power of 2 ko find** karna hota hai.
👉 `n-1` lene se pehla `1` aur uske baad ke saare `0` opposite me convert ho jaate hain.
👉 `x & (x-1)` bas wahi part rakhta hai jo pehle ka tha, sirf **sabse pehla `1` remove** ho jata hai.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int x; // Input number store karne ke liye variable
    cout << "Enter a number: ";
    cin >> x; // User se input lena
    
    int temp; // Temporary variable jo max power of 2 store karega
    
    while(x != 0){ // Jab tak x > 0 hai, loop chalega
       temp = x; // Har iteration me current x ko store karna
       x = (x & (x - 1)); // Ek-ek set bit remove karte jayenge
    }
    
    cout << "Max power of 2 till x: " << temp << "\n"; // Result print karna
    
    return 0; // Program successfully terminate hoga
}

// or
// #include<bits/stdc++.h>
// using namespace std;

// int max_power_of_two(int n){
//     // Step 1: Bitwise OR aur Right Shift ka use karke sabhi bits ko 1 banane ki koshish
//     n = n | (n >> 1);  // Right shift karke adjacent bits ko 1 karna
//     n = n | (n >> 2);  // 2 bit shift aur OR operation
//     n = n | (n >> 4);  // 4 bit shift aur OR operation
//     n = n | (n >> 8);  // 8 bit shift aur OR operation
//     n = n | (n >> 16); // 16 bit shift aur OR operation (for large values)
       // if n= 11111 then 2^n -1 is coming but require 2^4 so we return like this:-
//     // Step 2: (n+1)/2 se largest power of 2 nikalna 
//     return (n + 1) / 2;
// }

// int main(){
//     int num;
//     cout << "Enter a number: ";
//     cin >> num;

//     cout << "Max power of 2 till " << num << " : " << max_power_of_two(num) << "\n";
//     return 0;
// }


// agar ek power adhik nikalne ko kaha gya for x toh temp mein 2 se multiply kar do