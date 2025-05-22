#include<bits/stdc++.h> // Saari standard C++ libraries include ho jaati hain
using namespace std;

int main() {
    vector<int> v; // Ek empty vector 'v' declare kiya

    v.push_back(9);  // Vector ke end mein 9 add kiya
    v.push_back(10); // Vector ke end mein 10 add kiya
    v.push_back(6);  // Vector ke end mein 6 add kiya
    v.push_back(1);  // Vector ke end mein 1 add kiya

    // v.at(2)=90;  // (Commented) Index 2 pe value ko 90 set karne ke liye
    // cout<<v.at(2); // (Commented) Index 2 ki value print karne ke liye

    // Pehla for loop - vector ke sabhi elements ko print karne ke liye
    for(int i = 0; i < v.size(); i++) {  // i ko 0 se shuru karke vector ke size tak loop chalayenge
        cout << v.at(i) << " "; // Har element ko print karenge
    }
    cout << endl; // Nayi line ke liye

    // Vector ko ascending order mein sort kar rahe hain
    sort(v.begin(), v.end()); // v.begin() se v.end() tak sort karega

    // Sorted vector ko print karne ke liye loop
    for(int i = 0; i < v.size(); i++) {  // i ko 0 se shuru karke vector ke size tak loop chalayenge
        cout << v.at(i) << " "; // Sorted elements print karenge
    }
    cout << endl; // Nayi line ke liye
}
