#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
    if(n == 1) return false; // 1 ko prime nahi maana jaata
    
    // Loop 2 se sqrt(n) tak hi chalana kaafi hota hai
    for(int i = 2; i <= sqrt(n); i++){
        /*
        ✅ Logic of using sqrt(n):

        Agar kisi number n ka koi factor ho, toh wo factor ya toh sqrt(n) ke pehle aayega 
        ya uske baad. Jaise:

        Example: n = 36
        Factors = (1,36), (2,18), (3,12), (4,9), (6,6)
        √36 = 6, toh 6 tak check karna kaafi hai.
        
        Agar 6 tak koi bhi factor nahi mila, toh uske baad wale sab factors 
        already pehle wale factors ke pair honge.

        Isiliye loop ko sirf 2 se √n tak chala ke hum time save karte hain.

        Time Complexity: O(√n)
        */
        if(n % i == 0) return false; // koi factor mil gaya toh prime nahi hai
    }

    return true; // agar koi bhi factor nahi mila, toh number prime hai
}

int main(){
    int n;

    cin >> n;

    // Check prime status and print result
    if(prime(n)) 
        cout << n << " is a prime number";
    else 
        cout << n << " is not a prime number";

    return 0;
}
