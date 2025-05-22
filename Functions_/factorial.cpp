#include<iostream>
using namespace std;
// int fact(int x){
//     int f=1;
//     for( int i=2;i<=x;i++){
//         f*=i;
//     }
//     return f;
// }
int main() {
    int n;
    cout<<"Enter a positive integer: ";
    cin>>n;
    // int product = 1;
    // for (int i=1; i<=n; i++) {
    //     cout<<fact(i)<<" ";
    // }
    int fact=1;
    for(int i=1; i<=n; i++) {
      fact*=i;
     cout<<fact<<endl;
}
}