#include <iostream>  // Include the iostream library to enable input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: with every standard function

// Function to calculate the Fibonacci number using recursion
int fib(int n) {  
    // Base case: If n is 1 or 2, return 1 (first two Fibonacci numbers are 1)
    if(n == 1 || n == 2) return 1;

    // Recursive case: Fibonacci of n is the sum of the previous two Fibonacci numbers
    else return fib(n - 1) + fib(n - 2);  
}  

// Main function where execution of the program begins
int main() {
    // Print the 8th Fibonacci number by calling the fib function with 8 as the argument
    cout << fib(8);

    // Return 0 to indicate successful execution of the program
    return 0;
}
