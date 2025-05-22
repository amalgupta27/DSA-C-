#include <iostream> // Includes the input-output library
using namespace std; // Allows using standard functions without 'std::'

// Function to print numbers from 'n' to 1 using recursion
void print(int n) {  
    if (n == 0) return; // Base case: If 'n' is 0, stop the function  

    cout << n << endl; // Print the current number  

    print(n - 1); // Call the function again with 'n-1' (next smaller number)  
}  

// Main function where the program starts
int main() {  
    int n; // Variable to store user input  

    cout << "Enter a number: "; // Ask the user for a number  
    cin >> n; // Store the input number in variable 'n'  

    print(n); // Call the function to print numbers from 'n' to 1  

    return 0; // End the program successfully  
}  
