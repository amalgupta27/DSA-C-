#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s = "hello world";
    int n= s.size();

    cout << s << endl; // prints hello world

    cout<<s.substr(2);// 2 to all

    cout<<s.substr(2,2); // 2 se 2 length kaa

    cout<<s.substr(n/2); // print right half of string

}