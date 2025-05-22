/*
📌 Logic Explanation (Hinglish):

🔹 Problem Statement:
Hume kisi number `n` tak ke factorial calculate karne hain. Lekin factorial bahut tezi se bada ho jata hai,
isliye hume modulo (10^9 + 7) ke sath factorial lena padega taki result manageable rahe.

🔹 Factorial Definition:
Factorial of n => `n! = n * (n-1) * (n-2) * ... * 1`

🔹 Approach:
1️⃣ Ek vector banate hain jisme fact[0] = 1, fact[1] = 1 initialize kar dete hain.
2️⃣ Fir loop chala kar fact[i] = (fact[i-1] * i) % MOD calculate karte hain.
3️⃣ MOD (10^9 + 7) lagate hain taaki number overflow na ho.

🔸 Final Result: fact[0], fact[1], ..., fact[n] vector ke form me return karte hain.

📊 Flowchart (ASCII style - Hinglish):

[Start]
   |
   v
[Input n]
   |
   v
[Vector banao size n+1, initialize all with 1]
   |
   v
[i = 2 se n tak loop chalao]
   |
   v
[Har i ke liye: fact[i] = (fact[i-1] * i) % MOD]
   |
   v
[Return fact vector]
   |
   v
[Print all factorials]
   |
   v
[End]
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long int> factorial(int n){
    vector<long long int> fact(n+1, 1); // fact[0] = 1, fact[1] = 1 se initialize
    int MOD = 1000000000 + 7; // Large prime number for modulo

    for(int i=2; i<=n; i++){
        fact[i] = (fact[i-1]%MOD * i%MOD) % MOD; // pehle ka factorial lo, usme i multiply karo, fir MOD lo
    }
        
    return fact; // vector return karo jisme 0! se n! tak hai
}

int mai(){
  vector<long long int> res=  factorial(25); // 25 tak ke factorials calculate karo
  for(int i=0; i<res.size(); i++){
    cout<<i<<res[i]<<" "; // har factorial ko print karo
  }
  return 0;
}
