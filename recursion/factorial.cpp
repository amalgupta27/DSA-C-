#include <iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Function to calculate the factorial of a number using recursion
int fact(int n) {  
    // Base case: If n is 0 or 1, return 1 (as 0! and 1! both equal 1)
    if (n == 0 || n == 1) return 1;  
    
    // Recursive case: Multiply n with the factorial of (n-1)
    else return n * fact(n - 1);  
}  

// Main function where execution begins
int main() {  
    int n; // Declare an integer variable to store user input
    
    // Prompt the user to enter a number
    cout << "Enter a number for its factorial: ";  
    
    cin >> n; // Read the user input and store it in variable 'n'
    
    // Call the 'fact' function and print the result
    cout << fact(n);  
    
    return 0; // Indicate successful program execution
}  
 