#include<iostream>
using namespace std;

int main() {
    int x = 12;      // Ek integer variable x jisme 12 store hai
    int* p = &x;     // p ek pointer hai, jo x ka address store karta hai
    cout << *p << endl; // p ko dereference karke x ka value print kar rahe hain
}
