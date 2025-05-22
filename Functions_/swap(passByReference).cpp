#include<iostream>
#include<cmath> // (yahan math functions ke liye include kiya, par is code mein math use nahi hua)
using namespace std;

// Swap function using pointers
void swap (int *x, int *y) {
    int temp = *x; // temp mein *x (yaani a ka value) daala
    *x = *y;       // *x mein *y ka value daala (yaani a = b)
    *y = temp;     // *y mein temp ka value daala (yaani b = a)
    return;
}

int main() {
    int a;
    cout<<"Enter first number : ";
    cin>>a;
    int b;
    cout<<"Enter second number : ";
    cin>>b;
    
    swap(&a, &b); // 'swap' function ko address bhej rahe hai
    
    cout << "swapping " << a << " " << b << endl; // Swapped values print kar rahe hai
    return 0;
}
  