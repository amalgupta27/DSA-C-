#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Invalid input! Only binary digits (0 or 1) are allowed." << endl;
            return 1;
        }
    }
    int sum=0;
    int x=1;
    for(int i=n-1; i>=0 ;i--) {
       sum+=arr[i]*x;
       x*=2;
    }
    cout<<"Decimal form: "<<sum<<endl;
    return 0;

}