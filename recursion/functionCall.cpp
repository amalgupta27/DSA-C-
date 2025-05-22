#include<iostream>
using namespace std;
int fun(int n){
    if(n==0) return 0;
    cout<<"Good morning"<<endl;
    fun(n-1);

}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin >> n;
    fun(n);
    return 0; 
}