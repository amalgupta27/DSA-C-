#include <iostream>
#include<string>
using namespace std;
int main(){
    string s="amal"; 
    int count=0;
    for(int i=0;i<s[i]!='\0';i++){
        if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o' || s[i]=='u'){
            count++;
        }
    }     
    cout<<"Number of vowels in the string "<<s<<" is "<<count;
    return 0;  
}

//OR
// int n;
// cin >>n;
// char s[n];
// for(int i=0; i<n; i++){
//     cin >> s[i];
// }