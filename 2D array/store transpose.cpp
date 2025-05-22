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
            cout<<" ";
        }
    }
    //print
     for (int i = 0; i < m; i++) {  //rows
        for (int j = 0; j < n; j++) {  //columns
            cout << arr[i][j];
        }
        cout<<endl;
    }
    //  storing  transpose
    int t[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            t[i][j] = arr[j][i];
        }
    }
    // print transpose
    cout << "Transpose of the given array: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}