#include <iostream>
using namespace std;
int main(){
    char a, b;
    cout << "Enter two characters: ";
    cin >> a >> b;
    cout << "Difference of ASCII values: " << (int)b - (int)a;
    return 0;
}