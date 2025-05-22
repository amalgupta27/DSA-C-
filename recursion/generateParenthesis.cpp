#include<iostream>  // Including the input-output stream library to use cout for printing output.
#include<string>    // Including string library to use string manipulation functions.
using namespace std; // This allows us to use standard library functions without writing std:: before them.

// Function to generate all valid parentheses combinations
void generate(string s, int open, int close, int n) {
    // Base condition: If the number of closing brackets used reaches 'n', we print the combination.
    if (close == n) {  
        cout << s << endl; // Print the generated valid parentheses string.
        return; // Return to stop further recursion.
    }

    // Condition to add an opening bracket '(' if we haven't used all 'n' open brackets yet.
    if (open < n) 
        generate(s + '(', open + 1, close, n); // Add '(' to the string and increase 'open' count by 1.

    // Condition to add a closing bracket ')' if the number of open brackets used is greater than close brackets.
    if (open > close) 
        generate(s + ')', open, close + 1, n); // Add ')' to the string and increase 'close' count by 1.
}

// Main function, which is the entry point of the program.
int main() {
    int n = 3; // Define the total number of pairs of parentheses.
    
    generate("", 0, 0, n); // Call the function to generate valid parentheses with an empty string and 0 open and close brackets.

    return 0; // Return 0 to indicate successful execution of the program.
}

/* Example Explanation:

For n = 3, the function generates all valid combinations of 3 pairs of parentheses:

1. "((()))"  -> Open: 3, Close: 3 (Valid)
2. "(()())"  -> Open: 3, Close: 3 (Valid)
3. "(())()"  -> Open: 3, Close: 3 (Valid)
4. "()(())"  -> Open: 3, Close: 3 (Valid)
5. "()()()"  -> Open: 3, Close: 3 (Valid)

Step-by-step breakdown for n = 2:

1. Start with empty string ""
2. Add '(' → "("
3. Add '(' → "(("
4. Add ')' → "(()"
5. Add ')' → "(())"  (Valid)

All valid combinations for n=2: 
- "(())"
- "()()"
*/
