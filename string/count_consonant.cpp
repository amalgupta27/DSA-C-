#include <iostream>
#include<string>
using namespace std;
bool isConsonant(char c){ // this will not consider spaces,numbers,etc as consonant
    if(c<65) return false;
    else if(c>90 && c<97) return false;
    else if(c>122) return false;
    else if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return false;
    else if(c== 'A' || c=='E' || c=='I' || c=='O' || c=='U') return false;
    else return true; 
}
int main(){
    string s; 
    cout<<"Enter a string: ";  // Prompt user to enter a string
    getline(cin, s);  // Taking input from user
    int count=0;
    for(int i=0;i<s[i]!='\0';i++){
        if(isConsonant(s[i])) count++;
    }     
    cout<<"Number of consonant in the string "<<s<<" is "<<count;
    return 0;  
}
