#include <iostream>  // Include the iostream library for input and output operations
using namespace std;  

// Function to calculate the power of a number using recursion O() complexity
int power(int x, int n) {
    if (n == 0) return 1; // Base case: Any number raised to the power of 0 is 1
    int ans = power(x, n / 2); // Recursively calculate power for n/2

    if (n % 2 == 0)  // If `n` is even, multiply ans by itself
        return ans * ans;
    else  // If `n` is odd, multiply ans by itself and then by x
        return ans * ans * x;
}

int main() {
    cout << power(2, 3); // Call the power function with base 3 and exponent 8, and print the result
    return 0;  // Return 0 to indicate successful execution
}
