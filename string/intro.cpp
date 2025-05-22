#include <iostream>
#include<string>
using namespace std;
int main(){
    char str[5]= {'a', 'b', 'c', 'd','e'};
    // for(int i=0; i<5; i++){
    //     cout << str[i] << " ";
    // }
    // cout << endl;

    //OR

    cout << str << endl; // dirctly we can print in character array it will print till \0 
    //char str[5]= "hello";  //show error because contain one null character so write str[6]

    char ch = '\0'; // null character 
    cout << ch << endl; // it will not print anything because it is null character
}