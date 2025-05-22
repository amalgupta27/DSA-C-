#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    string s; 
    cout<<"Enter a string: ";  //taking input from the user.
    getline(cin, s);
    string temp=s;
    reverse(temp.begin(), temp.end());
    s += temp;
    cout<<"Reversed and concatenated string: "<<s;  //printing the reversed and concatenated string.
    return 0;  
}
