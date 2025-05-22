#include<iostream>
using namespace std;

int main() {
    int x = 4;        // Integer variable x ka value 4
    int* p = &x;      // p ek pointer hai jo x ke address ko store karta hai

    float x2 = 5;     // Float variable x2 ka value 5
    float* p2 = &x2;  // p2 ek pointer hai jo x2 ke address ko store karta hai

    cout << &x << endl;   // x ka address print hoga
    cout << p << endl;    // p ka value print hoga, jo ki x ka address hai
    cout << *p << endl;   // p ke through x ka value print hoga (dereference)

    cout << &x2 << endl;  // x2 ka address print hoga
    cout << p2 << endl;   // p2 ka value print hoga, jo ki x2 ka address hai
    cout << *p2 << endl;  // p2 ke through x2 ka value print hoga (dereference)

    return 0;
}
