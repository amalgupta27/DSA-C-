#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "hello world";
    cout << s.size() << endl; // prints 11
    cout << s.length() << endl; // prints 11

    s.push_back('a'); 
    cout<<s<<endl;

    s.pop_back();
    cout<<s<<endl;

    string str ="abc";
    string ttr ="def";
    cout << str + ttr<< endl;

    s= s+'a'; // append
    cout<<s<<endl;

    s="jai"+s; // add
    cout<<s<<endl;
}