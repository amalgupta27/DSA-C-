#include <iostream> // For input/output
using namespace std;

int main() {
    int a, r, n; // a = first term, r = common ratio, n = number of terms

    // Get input from the user
    cout << "Enter first term (a): ";
    cin >> a;

    cout << "Enter common ratio (r): ";
    cin >> r;

    cout << "Enter number of terms (n): ";
    cin >> n;

    int term = a; // Initialize the first term

    // Print GP using repeated multiplication
    cout << "Geometric Progression: ";
    for (int i = 0; i < n; i++) {
        cout << term << " ";   // Print the current term
        term *= r;             // Multiply by common ratio to get next term
    }

    return 0; // Program ends
}

//OR
// #include <iostream>  // For input and output
// #include <cmath>     // For using pow() to calculate powers
// using namespace std;

// int main() {
//     int a, r, n; // a = first term, r = common ratio, n = number of terms

//     // Ask user to enter the first term
//     cout << "Enter first term (a): ";
//     cin >> a;

//     // Ask user to enter the common ratio
//     cout << "Enter common ratio (r): ";
//     cin >> r;

//     // Ask user to enter number of terms
//     cout << "Enter number of terms (n): ";
//     cin >> n;

//     // Print the GP
//     cout << "Geometric Progression: ";
//     for (int i = 0; i < n; i++) {
//         // Calculate and print a * r^i
//         cout << a * pow(r, i) << " ";
//     }

//     return 0; // End of program
// }
