#include <iostream>
#include <algorithm> // for reverse
using namespace std;

int main() {
    string s = "hello world";

    // Reverse the string using built-in reverse function
    //reverse(s.begin(), s.end());

    // Reverse the string without using built-in reverse, using while loop
    int left = 0;
    int right = s.size() - 1;
    while(left < right) {
        // Swap characters from both ends
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    
    // Print the reversed string
    cout << "Reversed string: " << s << endl;

    return 0;
}