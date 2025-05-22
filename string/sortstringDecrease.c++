#include<iostream>  // Standard input-output stream library
#include<vector>    // Vector library (not used in this code)
#include<bits/stdc++.h> // Includes all standard libraries (not necessary here)

using namespace std;  

int main() {
   // Initializing a string with some characters
   string s = "AXCDFDDGFDZXYZX";  

   // Looping through each character in the string
   for(int i = 0; i < s.size(); i++) {
      // If the character is greater than or equal to 'X' in ASCII value
      if(s[i] >= 'X') {  
         s.push_back(s[i]);  // Append the character to the end of the string
      }
   }

   // Sorting the modified string in ascending order (A-Z)
   sort(s.begin(), s.end());  

   // Reversing the string to get it in descending order (Z-A)
   reverse(s.begin(), s.end());  

   // Printing the final modified string
   cout << s << endl;  

   return 0;  // Returning 0 to indicate successful execution
}
