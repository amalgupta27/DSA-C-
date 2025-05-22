#include<iostream>
using namespace std;

int main() {
    int m;
    cout<<"Enter the row: ";
    cin>>m;
    int n;
    cout<<"Enter the column: ";
    cin>>n;
    int sum=0;
    int arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
        
    }
    cout<<"sum of elements is: "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            sum+=arr[i][j];
           
        }
       
    }
    cout<<sum<<endl;
    return 0;
}