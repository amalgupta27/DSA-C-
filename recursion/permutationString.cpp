#include <iostream>
#include <string>
using namespace std;
/*
Function: permutations
Purpose: Prints all possible orders (permutations) of the given string.
Parameters:
    - ans      : The arranged part of the string so far.
    - original : The remaining letters we need to arrange.
*/
void permutations(string ans, string original) {
    // If there are no more letters left, print the arranged string
    if (original == "") {
        cout << ans << endl;  // Print one possible arrangement
        return;  // Stop further processing
    }
    // Loop through each character in `original`
    for (int i = 0; i < original.length(); i++) {
        char ch = original[i];  // Pick one character
        string left = original.substr(0, i);  // Part before the picked character
        string right = original.substr(i + 1);  // Part after the picked character
        // Call the function again with the new arrangement
        permutations(ans + ch, left + right);
    }
}
int main() {
    string str = "abcd";  // The string we want to find permutations for
    permutations("", str);  // Call function to start generating permutations
    // Example to understand how substr() works:
    // Suppose str = "abcde"
    // 'c' is at index 2, and the string length is 5 (index 0 to 4)
    string left = str.substr(0, 2);  // Get substring before 'c' → "ab"
    cout << "Left part: " << left << endl;  // Output: Left part: ab
    string right = str.substr(2 + 1);  // Get substring after 'c' → "de"
    cout << "Right part: " << right << endl;  // Output: Right part: de
    return 0;
}

/*
Example Execution:
Input: "ABC"

Step-by-Step Process:
permutations("", "ABC")
    - Picks 'A' → permutations("A", "BC")
        - Picks 'B' → permutations("AB", "C")
            - Picks 'C' → permutations("ABC", "") → Prints "ABC"
        - Picks 'C' → permutations("AC", "B")
            - Picks 'B' → permutations("ACB", "") → Prints "ACB"
    - Picks 'B' → permutations("B", "AC")
        - Picks 'A' → permutations("BA", "C")
            - Picks 'C' → permutations("BAC", "") → Prints "BAC"
        - Picks 'C' → permutations("BC", "A")
            - Picks 'A' → permutations("BCA", "") → Prints "BCA"
    - Picks 'C' → permutations("C", "AB")
        - Picks 'A' → permutations("CA", "B")
            - Picks 'B' → permutations("CAB", "") → Prints "CAB"
        - Picks 'B' → permutations("CB", "A")
            - Picks 'A' → permutations("CBA", "") → Prints "CBA"

Final Output:
ABC
ACB
BAC
BCA
CAB
CBA
*/
