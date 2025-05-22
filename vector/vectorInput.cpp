#include<bits/stdc++.h>
using namespace std;
int main(){
    // naya vector banaya jisme user se input lenge
    vector<int> userVector;

    // input le rahe hain - agar size predefined nahi hai to is tarah input liya jata hai
    // yaha hum v.size() use nahi kar sakte kyunki size badalta hai har input ke saath
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;         // user se ek element input
        userVector.push_back(x); // vector me add kar diya
    }

    // user ke input wale vector ko print kar rahe hain
    for (int i = 0; i < 5; i++) {
        cout << userVector[i] << " ";
    }

    return 0;
}