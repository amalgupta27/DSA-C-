#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s; 
    cout<<"Enter a string: ";  //prompting user to enter a string
    getline(cin, s);  //taking input from user

    // reverse(s.begin()+2 ,s.end()); // reverse from 2

    int n= s.length();
    int i=n/2; //reverse from middle of string
    int j=n-1;
    while(i<j){
        // swap characters at i and j positions
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
 cout<<s<<endl;
    
    return 0;  
}
