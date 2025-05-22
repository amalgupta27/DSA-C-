#include <iostream>
using namespace std;
int main(){
    int num, sum=0;
    cout << "Enter a positive integer: ";
    cin >> num;
    while(num!=0){
        sum += num%10   ;
        num=num/10;
    
    }
    //if(num==0) cout << 0;
     cout << "Sum of digits: " << sum << endl;
    return 0;
}