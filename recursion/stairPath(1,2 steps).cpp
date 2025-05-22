#include <iostream>  // Include the iostream library to enable input and output operations
using namespace std; // Use the standard namespace to avoid using "std::" before functions like cout

// Function to calculate the number of ways to climb stairs using recursion
// Only 1-step and 2-step jumps are allowed
int stair(int n) { 
    if (n == 2) return 2;  // Base case: If there are 2 steps, there are 2 ways to climb (1+1 or 2)
    if (n == 1) return 1;  // Base case: If there is only 1 step, there is only 1 way to climb

    // Recursive case: The number of ways to climb `n` steps is the sum of ways to climb (n-1) and (n-2) steps
    return stair(n - 1) + stair(n - 2);
}

// Main function where the program execution starts
int main() {
    cout << stair(6); // Call the `stair` function with 6 steps and print the result
    return 0; // Return 0 to indicate successful program execution
}

/*
Examples:

1. stair(3):
   Ways to climb:
   - (1,1,1)
   - (1,2)
   - (2,1)
   Total ways = 3

2. stair(4):
   Ways to climb:
   - (1,1,1,1)
   - (1,1,2)
   - (1,2,1)
   - (2,1,1)
   - (2,2)
   Total ways = 5

3. stair(5):
   Ways to climb:
   - (1,1,1,1,1)
   - (1,1,1,2)
   - (1,1,2,1)
   - (1,2,1,1)
   - (2,1,1,1)
   - (1,2,2)
   - (2,1,2)
   - (2,2,1)
   Total ways = 8

General Formula:
stair(n) = stair(n-1) + stair(n-2) (like Fibonacci series)
*/
