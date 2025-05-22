#include <iostream>  // Include standard input-output stream library
#include <string>    // Include string library for string operations
using namespace std; // Use the standard namespace

// Function to check if a string is a palindrome using recursion
bool isPalindrome(string s, int i, int j) {
    // Base case: If the left index (i) crosses the right index (j), return true (valid palindrome)
    if (i > j) return true;

    // If characters at current indices don't match, return false (not a palindrome)
    if (s[i] != s[j]) return false;

    // Recursive call: Check the next pair of characters (moving towards the center)
    return isPalindrome(s, i + 1, j - 1);
}

int main() {
    string s = "mom"; // Define a string to check for palindrome
    cout << isPalindrome(s, 0, s.length() - 1); // Call the function and print the result (1 for true, 0 for false)
}


//method 2
// #include <iostream>
// #include <string>
// using namespace std;
// bool isPalindrome(string s)
// {
//     int i = 0;
//     int j = s.length() - 1;
//     while (i < j)
//     {
//         if (s[i] != s[j])
//             return false;
//         i++;
//         j--;
//     }
//     return true;
// }
// int main()
// {
//     string s = "mom";
//     cout << isPalindrome(s);
// }
