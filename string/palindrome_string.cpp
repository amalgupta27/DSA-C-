#include <iostream>
#include<string>
using namespace std;

bool isPalindrome(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;

}
int main(){ 
    string s; 
    cout<<"Enter a string: ";
    getline(cin, s);
    
    if(isPalindrome(s)==true) {
        cout<<s<<" is a palindrome."<<endl;
        }
    else cout<<s<<" is not a palindrome."<<endl;
    
    
    return 0;  
}
