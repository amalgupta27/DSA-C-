// Includes all standard C++ libraries (not recommended for large projects, but okay for small ones)
#include<bits/stdc++.h>

// Standard namespace to avoid writing std:: again and again
using namespace std;

// Main function - execution starts here
int main(){
    int n;  // Declare an integer variable 'n' to store user input

    // Ask the user to enter a number
    cout << "Enter a number: ";

    // Take input from the user and store it in variable 'n'
    cin >> n;

    // Loop to print the multiplication table of 'n' from n to n*10
    // 'i' starts from 'n' and increases by 'n' each time, until 'i' is less than or equal to n*10
    for(int i = n; i <= n * 10; i += n){
        // Print the current value of 'i' followed by a space
        cout << i << " ";
    }

    // Program ends
}
