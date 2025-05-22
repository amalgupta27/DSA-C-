#include<iostream> // Input-output ke liye header file
using namespace std;

int main(){
    int x = 5; // Ek integer variable 'x' banaya gaya jisme 5 assign kiya gaya

    int* ptr = &x; // 'ptr' ek pointer hai jo 'x' ka address store karta hai

    int** p = &ptr; // 'p' ek double pointer hai, jo 'ptr' ka address store karta hai

    cout << &x << endl;   // x ka address print karega
    cout << ptr << endl;  // ptr ke andar jo address hai (x ka) wo print karega
    cout << *p << endl;   // p ke through ptr ka value print karega (yani phir se x ka address)

    cout << x << endl;    // x ka actual value print karega (5)
    cout << *ptr << endl; // ptr dereference karke x ka value print karega (5)
    cout << **p << endl;  // p ko 2 baar dereference karke x ka value print karega (5)
}
