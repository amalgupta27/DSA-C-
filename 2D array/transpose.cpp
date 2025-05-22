#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Enter the number of row: ";
    cin >> m;
    int n;
    cout << "Enter the number of column: ";
    cin >> n;
    int arr[m][n];
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    //print
     for (int i = 0; i < m; i++) {  //rows
        for (int j = 0; j < n; j++) {  //columns
            cout << arr[i][j];
        }
        cout<<endl;
    }
    // print transpose
    for(int j = 0; j < n; j++) { //col
        for(int i = 0 ; i<m; i++){ //row
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}