#include <iostream>  // Include standard input-output stream library
#include <string>    // Include string library (not needed in this code)
using namespace std; // Use the standard namespace

// Function to calculate the Greatest Common Divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    // Base case: If 'a' becomes 0, return 'b' (GCD is 'b' in this case)
    if (a == 0) return b;

    // Recursive case: Call gcd with 'b % a' and 'a'
    return gcd(b % a, a);
} 

int main() {
    int a = 10000; // Define first number
    int b = 10001; // Define second number

    cout << gcd(b, a); // Call the GCD function and print the result
}


//method 2
// #include <iostream>  // Include standard input-output stream library
// #include <string>    // Include string library (not needed in this code, but doesn't cause issues)
// using namespace std; // Use the standard namespace

// // Function to calculate the Highest Common Factor (HCF) using a loop
// int hcf(int a, int b) {
//     // Start the loop from the smaller of the two numbers and go downwards
//     for (int i = min(a, b); i >= 2; i--) { 
//         // If 'i' is a common divisor of both 'a' and 'b', return it as HCF
//         if (a % i == 0 && b % i == 0) 
//             return i; 
//     }
//     // If no common factor is found, return 1 (indicating numbers are co-prime) 1 can be always HCF
//     return 1; 
// }
// int main() {
//     int a = 24;  // Define first number
//     int b = 60;  // Define second number

//     cout << hcf(a, b); // Call the HCF function and print the result
// }
