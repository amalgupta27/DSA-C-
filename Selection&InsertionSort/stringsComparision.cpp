#include<iostream>
#include<string>
using namespace std;
int main(){
string s = "abdc";
string t = "aydc";
cout << s.compare(t);

// 0 if s == t
// +ve if s>t
// -ve if s<t
}