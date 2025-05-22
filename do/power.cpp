#include<iostream>
using namespace std;
int main(){
    int a, b;
    cout << "Enter two base: ";
    cin >> a ;
    cout << "Enter the exponent: ";  //exponent is b in the formula a^b, so b is entered as input.  //b is the power of the base a.  //a is the base number.  //power is the result.  //i is a counter variable.  //a*a*a*a*a*a*a*a*a*a is the same as a^10.  //power is initialized as 1
    cin>> b;
    bool flag = true; //means power is positive
    if(b<0){ 
       flag=false; // power is negative
       b=-b;
    }
    float power=1;
    for(int i=1;i<=b;i++){
        power=power*a;
    }
    if(flag==false){
        power=1/power;
        b=-b;
    }
    if(a==0 && b==0){
        cout<<"undefined"<<endl;
    }
    else cout<<power;
}