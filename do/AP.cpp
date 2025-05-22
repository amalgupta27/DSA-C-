#include <iostream> // Header file to use input and output functions
using namespace std; // So we can use cout and cin without std:: prefix

int main() {
    int a, d, n; // Declare variables: a = first term, d = common difference, n = number of terms

    // Ask the user to enter the first term of the AP
    cout << "Enter first term (a): ";
    cin >> a; // Read and store the first term

    // Ask the user to enter the common difference
    cout << "Enter common difference (d): ";
    cin >> d; // Read and store the common difference

    // Ask the user to enter how many terms to print
    cout << "Enter number of terms (n): ";
    cin >> n; // Read and store number of terms

    // Print message before the AP output
    cout << "Arithmetic Progression: ";

    // Loop from 0 to n-1 to print n terms
    for (int i = 0; i < n; i++) {
        // Calculate and print the i-th term of AP using the formula: a + i * d
        cout << a + i * d << " ";
    }

    return 0; // Indicate successful program end
}
