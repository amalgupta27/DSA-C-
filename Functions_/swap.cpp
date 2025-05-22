#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a;
    cout<<"Enter first number : ";
    cin>>a;
    int b;
    cout<<"Enter second number : ";
    cin>>b;
    int temp=a;
    a=b;
    b=temp;
    cout<<"After swapping: \nFirst number : "<<a<<"\nSecond number : "<<b;
    return 0;
}