#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"Enter a string :";
    getline(cin, s);
    int count =0;
    int answer = 0;
    for(int i=0;i<s.length();i++){ //we can add upper case if you want
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            count++;
        
        else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            count++;
        else {
            answer += count*(count+1)/2;
            count =0;
        }
           
    }
    answer += count*(count+1)/2;
    cout<<answer;
    return 0;  
}