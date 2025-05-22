#include<iostream> // Input/output operations ke liye header file
using namespace std;

int main(){
    int* ptr = NULL; // Ek pointer 'ptr' banaya gaya hai jo abhi kisi valid address ko point nahi kar raha
    // NULL ka matlab hai "kisi bhi variable ko point nahi kar raha" ya "empty address"
    // OR NULL= '\0' = 0; , \0->null character
    cout << ptr; // Pointer ka value print kar rahe hain, jo abhi NULL hai
    // Output: 0x0 (ya 0) — depending on compiler

    // Note: NULL ya nullptr ka use hota hai jab hum pointer ko initialize karte hain
    //       but abhi use nahi karna chahte kisi specific variable ke saath
}
