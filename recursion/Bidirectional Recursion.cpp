#include<iostream>  // Including the standard input-output stream library
using namespace std;  // Using the standard namespace to avoid writing std:: before functions

// Function to print numbers from x to n
void print(int x, int n) {  
    if(x >= n) {  // Base condition: If x is greater than or equal to n
        cout << n << " ";  // Print n without space or newline
        return;  // Exit the function when base condition is met
    }

    cout << x << " ";  // Print the current value of x followed by a dot

    print(x + 1, n);  // Recursive call to print the next number

    cout << x << " ";  // Print x again after the recursive call
}

int main() {  
    int n;  // Declare an integer variable n

    cout << "Enter n : ";  // Prompt user for input
    cin >> n;  // Take input from user and store it in n

    print(1, n);  // Call the print function starting from 1 up to n

    return 0;  // Indicate successful execution of the program
}
