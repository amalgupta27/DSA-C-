#include <iostream>
#include<string>
using namespace std;
int main(){
    string str= "Amal gupta"; // its size is 11 because of space and null(\0) character
    cout << "Original string: " << str << endl;

    //taking input string
    string s;
    cout << "Enter a string: ";
    getline(cin, s); //to get space one string
    cout << "Entered string: " << s << endl;
}