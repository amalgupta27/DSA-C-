#include <iostream>
#include<string>
using namespace std;
int main(){
    string s; 
    cout<<"Enter a string: ";
    getline(cin, s);
    int x= stoi(s); // builtIn function used
    // int x=0;
    // for(int i=0; i<s.length(); i++){ //without built in functions
    //     x *= 10;
    //     x += s[i]-'0';  // subtracting ASCII value of '0' to get actual digit value
    // }
    cout<<"Converted integer: "<<x+1<<endl;
    return 0;  
}
