#include<bits/stdc++.h> // Saari standard C++ libraries ko include karta hai
using namespace std;

// Function jisme vector 'a' reference ke through pass ho raha hai ( & lagaya hai )
void change(vector<int> &a) { // a -> 9 10 6 1 (original vector ka hi reference hai)
    a[0] = 100; // Pehle element ko 100 bana diya (a -> 100 10 6 1)

    // Is loop mein updated vector print ho raha hai
    for(int i = 0; i < a.size(); i++) {  
        cout << a[i] << " "; // Har element ko print kar rahe hain
    }
    cout << endl; // New line ke liye
}

int main() {
    vector<int> v; // Ek empty vector declare kiya

    v.push_back(9);   // Vector mein 9 add kiya
    v.push_back(10);  // Vector mein 10 add kiya
    v.push_back(6);   // Vector mein 6 add kiya
    v.push_back(1);   // Vector mein 1 add kiya

    // Original vector ko print kar rahe hain
    for(int i = 0; i < v.size(); i++) {  
        cout << v[i] << " "; 
    }
    cout << endl;

    change(v); // Vector ko function mein bhej rahe hain (by reference)

    // Function ke baad vector phir se print kar rahe hain to check changes
    for(int i = 0; i < v.size(); i++) {  
        cout << v[i] << " "; 
    }

    // 👉 Isliye vectors ko agar aap bina & ke bhejte ho to wo copy ban jaati hai
    // Lekin agar aap '&' (reference) ka use karte ho to original vector mein hi change hota hai
}
