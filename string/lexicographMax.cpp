#include <iostream>
#include <string>
#include <bits/stdc++.h> // Requires all standard headers (not recommended for production)
#include <climits> // For INT_MAX, INT_MIN etc. (not used here)

using namespace std;

int main() {
    string s; 
    cout << "Enter first String: " << endl; // Prompt user for input
    getline(cin, s); // Read the entire line of input into string 's'
    
    string word = ""; // Initialize an empty string to store current words
    string maxWord = ""; // Initialize an empty string to keep track of the longest word
    
    for (int i = 0; i < s.length(); i++) { 
        if (s[i] == ' ') { // Check if the current character is a space
            maxWord = max(maxWord, word); // Update maxWord if the current word is longer than previous longest word
            word = ""; // Reset current word after encountering a space
        } else {
            word += s[i]; // If not a space, keep adding characters to form a new word
        }
    }
    
    maxWord = max(maxWord, word); // Final check at end of sentence in case last word is longest
    
    cout << maxWord << endl; // Output the longest word found in the input

    return 0; 
}
