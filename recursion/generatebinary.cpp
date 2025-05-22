#include<iostream>  // Includes the input-output stream library for using cout and cin
#include<string>    // Includes string library for using string data type
using namespace std; // Allows usage of standard library names without prefixing with std::

/*
Function to generate binary strings of length 'n' without consecutive '1's
Parameters:
- s: The current binary string being formed
- n: The desired length of the binary string
*/
void generate(string s, int n) {
    // Base case: If the length of the string reaches 'n', print it and return
    if (s.size() == n) {
        cout << s << endl;
        return;
    }

    // Recursive call: Append '0' to the string and continue generating
    generate(s + '0', n);

    // Condition to append '1': Only if the last character is not '1' (to avoid "11")
    if (s == "" || s[s.size() - 1] == '0') { // Ensures '11' is not formed
        generate(s + '1', n);
    }
}

int main() {
    int n; // Variable to store the length of binary strings to generate
    cout << "Enter the length of binary string: ";
    cin >> n; // Takes user input for 'n'

    generate("", n); // Calls the function with an empty string to start the recursion

    return 0; // Program execution ends
}

/*
Example:

Input:
Enter the length of binary string: 3

Output:
000
001
010
100
101

Explanation:
- The function generates all possible binary strings of length 3, ensuring that "11" does not appear.
- It starts with an empty string and adds '0' and '1' following the given conditions.
*/ 
