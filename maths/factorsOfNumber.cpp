#include<bits/stdc++.h>
using namespace std;
// void factor(int n){
//     for(int i = 1; i <= n;i++){
//         if(n % i == 0) cout << i << "\n";
//     }
// }

//OR
void printFactor(int n){
    for(int i = 1; i < sqrt(n);i++){ //used only once square root 
       if(n % i == 0)  cout << i <<" ";
     }
     for(int i=sqrt(n); i>=1;i--){
        if(n%i==0) cout << n/i <<" ";
     } 
     // here two loop used because we can sequencly print the factors easily
}
int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    //factor(num);
    printFactor(num);
    return 0;
}


// method 2 explained
/*
📌 **Logic Explanation (Hinglish + Flow + Example)**

🔹 **Samasya Ka Vivaran:**
Hume kisi bhi number `n` ke **factors** print karne hain. Jaise agar `n = 12`, toh output: `1 2 3 4 6 12`

🔹 **Optimized Approach:**
Factors hamesha ek dusre ke pair mein hote hain. Jaise: 
→ 2 x 6 = 12, 3 x 4 = 12

Toh hume `1 se √n` tak hi check karna padta hai, agar `i` `n` ko divide kare toh `n/i` bhi ek factor hoga.

🔹 **Why 2 Loops?**
1st loop: `1 to sqrt(n)` tak jaake chhote wale factors print karta hai.
2nd loop: `sqrt(n) to 1` reverse jaake bade wale factors `n/i` ko print karta hai.

⚠️ Ye approach sequentially (in increasing order) print karne ke liye hoti hai.

📊 **Flowchart Representation (ASCII in Hinglish)**

Start
  |
  v
[Input lo n]
  |
  v
[1 to sqrt(n) loop: agar n % i == 0 -> print i]
  |
  v
[sqrt(n) to 1 loop: agar n % i == 0 -> print n/i]
  |
  v
[Done printing all factors]
  |
  v
End

🔢 **Example:**
Input: n = 12
Loop 1: i = 1 2 3 (print: 1 2 3)
Loop 2: i = 3 2 1 (print: 4 6 12)
Output: 1 2 3 4 6 12
*/

// #include<bits/stdc++.h>
// using namespace std;

// // Function to print all factors of a number in increasing order
// void printFactor(int n){
//     // Pehla loop: 1 se sqrt(n) tak jaata hai, chhote wale factors ko print karta hai
//     for(int i = 1; i < sqrt(n); i++){ 
//        // Agar i n ko divide karta hai, toh i ek factor hai
//        if(n % i == 0)  cout << i << " ";
//     }
    
//     // Dusra loop: sqrt(n) se 1 tak reverse jaata hai, bade wale factors (n/i) ko print karta hai
//     for(int i = sqrt(n); i >= 1; i--){
//         // Agar i n ko divide karta hai, toh n/i ek factor hoga
//         if(n % i == 0) cout << n/i <<" ";
//     } 
    
//     // Example:
//     // Input: 12
//     // Loop 1: i = 1,2,3 => print: 1 2 3
//     // Loop 2: i = 3,2,1 => print: 4 6 12
//     // Output: 1 2 3 4 6 12
// }

// int main(){
//     int num;
//     cout << "Enter a number: ";
//     cin >> num; // User input lete hain

//     printFactor(num); // Function call karte hain
//     return 0;
// }
