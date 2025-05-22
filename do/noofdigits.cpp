#include <iostream>
using namespace std;

// int main() {
//     int num, count = 0;
//     cout << "Enter a positive integer: ";
//     cin >> num;
//     int digit;
//     while(num !=0){
//         digit= num%10;
//         count++;
//         num /= 10;
//     }
//     cout << "No. of digits: " << count<< endl;
// }
//OR
int main(){
    int num, count = 0;
    cout << "Enter a positive integer: ";
    cin >> num;
    int a=num;
    while(num!=0){
        num /= 10;
        count++;
    }
    if(a==0) cout<< "No. of digits: "<<1<<endl;
    else cout << "No. of digits: " << count<< endl;
    return 0;
}