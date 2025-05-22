#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Enter the number of row : ";
    cin >> m;
    int n;
    cout << "Enter the number of column : ";
    cin >> n;
    int arr[m][n];
    for(int i=0; i<m ; i++) {
        for(int j=0; j<n; j++) {
            cout << "Enter element at position (" << i << "," << j << "): ";
            cin >> arr[i][j];
        }
    }
    cout<<"\n";
    // print array
     for(int i=0; i<m; i++) {
        for(int j=0; j<n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
     }
     cout << endl;
     // printing curve matrix
     for(int i=0; i<m; i++) {
        if(i%2==0){
            for(int j=0; j<n; j++)
                cout << arr[i][j] << " ";
        }
        else{
            for(int j=n-1; j>=0; j--)
                cout << arr[i][j] << " ";
        }
        cout << endl;
     }
 
}