#include <iostream>
using namespace std;
int fact(int x){
    int f=1;
    for( int i=2;i<=x;i++){
        f*=i;
    }
    return f;
}

int combinations(int n, int r){
    int nCr = fact(n)/(fact(r)*fact(n-r));
    return nCr;
}
int main(){
   int n;
   cout<<"Enter a positive integer: ";
   cin>>n;
   for(int i=0; i<=n; i++){

     for(int k=0; k<n-i+1; k++){
        cout<<" ";
     }
      for(int j=0; j<=i; j++){
        cout<<combinations(i,j)<<" ";
}
cout<<endl;
}
}