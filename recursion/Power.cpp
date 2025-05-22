#include<iostream>  
using namespace std;  

// Function to calculate the power of a number using recursion
int pow(int a, int b) {
    if (b == 0) return 1;  // Base case: Any number raised to the power of 0 is 1
    return a * pow(a, b - 1);  // Recursive case: Multiply `a` by `a^(b-1)`
}

int main() {
    int a;  // Variable to store the base value
    cout << "Enter base: " << endl;
    cin >> a;  // Take input for the base

    int b;  // Variable to store the exponent value
    cout << "Enter exponent: " << endl;
    cin >> b;  // Take input for the exponent

    // Call the recursive power function and display the result
    cout << "Power of base " << a << " to the power " << b << " is: " << pow(a, b);
    
    return 0;  
}
