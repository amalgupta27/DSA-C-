#include<iostream> // Input-output stream ko include kiya gaya hai
using namespace std; // Standard namespace ka use kiya jaa raha hai

int main() // Main function jahan se program start hota hai
{
    // Pehle kuch integer pointer ka example diya gaya tha, par wo ab comment kiya hua hai
    
    // bool type ka ek variable 'flag' banaya gaya hai jisme true assign kiya gaya hai
    bool flag = true;

    // Ek pointer 'ptr' banaya gaya hai jo bool type ka hai, aur usme 'flag' ka address store kiya gaya hai
    bool* ptr = &flag;

    // Pointer ke andar jo address store hai usse print kar rahe hain
    cout << ptr << endl; // Ye address print karega jahan 'flag' variable memory me store hai

    // Ab pointer ko 1 increment kiya jaa raha hai
    ptr = ptr + 1;

    // Fir se pointer ka updated address print kiya jaa raha hai
    cout << ptr << endl; // Ab ye next memory location ka address print karega (bool size ke hisaab se)
}
// int x =4;
// int* ptr = &x;
// cout <<* ptr << endl; // 4
// *ptr = *ptr +1;
//OR
// (*ptr) --; // x = x + 1
// cout <<* ptr << endl; // 5