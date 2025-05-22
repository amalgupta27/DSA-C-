#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    //method 1
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int n = s.size();           // Storing the length of the string
    if (n < 2) {                // Handling the case where string is too short
        cout << "String is too short to find the second largest character." << endl;
        return 0;
    }

    char max ='!' , secmax='!' ;
    for(int i = 0; i<s.length(); i++) {
        if(max < s[i]) {
            secmax = max;
            max = s[i];
        } else if(secmax < s[i] && s[i]!=max) {
            secmax = s[i];
        }
    }
    //Above loop explaination

    //So, we update the second largest (secmax) to be the previous maximum (secmax = max).
    //Then, we update the maximum to the new largest character (max = s[i]).
    //else if(secmax < s[i] && s[i] != max):
    //If the current character is not larger than the maximum but is greater than the current second maximum (secmax), and it’s not equal to the current maximum (to avoid duplicates),
    //Then, we update secmax to this character (secmax = s[i]).
    if(secmax == '!') cout<< "No secmax";
    else cout << "Second largest character in the string: " << secmax << endl;
    
    //method 2
    // string s; 
    // cout << "Enter a string: ";
    // getline(cin, s);

    // sort(s.rbegin(), s.rend()); // Sort in descending order

    // char maxChar = s[0];
    // char secLar = '\0';

    // for (char c : s) {
    //     if (c != maxChar) { // Find the first character different from maxChar
    //         secLar = c;
    //         break;
    //     }
    // }

    // if (secLar != '\0') {
    //     cout << "Second Largest character in the string: " << secLar << endl;
    // } else {
    //     cout << "No second largest character exists." << endl;
    // }

    return 0;
}
