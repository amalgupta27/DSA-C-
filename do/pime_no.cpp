#include<iostream>
using namespace std;
int main(){
int n;
cin >> n;
bool flag = true;
for(int i=2; i<=n-1; i++){
    if(n%i == 0){   
     flag = false; 
     break;
 }
}
if(n==1) cout << "1 is neither comosite nor a prime" << endl;
else if(flag==true) cout <<"Prime number";
else cout <<"composite number";

}
