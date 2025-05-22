#include <iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Recursive function to print numbers from 'i' to 'n' 
// this is using [Extra parameter].
void print(int i, int n) {  
    if (i > n) return; // Base case: If 'i' exceeds 'n', stop recursion  

    cout << i << endl; // Print the current value of 'i'  

    print(i + 1, n); // Recursive call: Increase 'i' and call the function again  
}  

// Main function where execution begins  
int main() {  
    int n; // Declare an integer variable to store user input  

    cout << "Enter a number: "; // Prompt the user to enter a number  
    cin >> n; // Read the user input and store it in variable 'n'  

    print(1, n); // Call the recursive function to print numbers from 1 to 'n'  

    return 0; // Indicate successful program execution  
}  

//or i.e [After Recursion Call]
// #include <iostream> 
// using namespace std; 
// // Function to print numbers from 1 to 'n' using recursion
// void print(int n) {  
//     if (n == 0) return; // Base case: If 'n' is 0, stop the function (end recursion)
//     print(n - 1); // Recursive call: First, call the function for (n-1)
//     cout << n << endl; // Print the current number after returning from recursion
// }  
// // Main function where program execution starts
// int main() {  
//     int n; 

//     cout << "Enter a number: "; // Ask the user to enter a number  
//     cin >> n; // Read and store the input number in 'n'  

//     print(n); // Call the function to print numbers from 1 to 'n'  

//     return 0; 
// }  
