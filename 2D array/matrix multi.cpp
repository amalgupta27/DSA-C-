#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Enter the number of row of 1: ";
    cin >> m;
    int n;
    cout << "Enter the number of column of 1: ";
    cin >> n;
    int a[m][n];
    
    int p;
    cout << "Enter the number of row of 2 : ";
    cin >> p;
    int q;
    cout << "Enter the number of column of 2: ";
    cin >> q; 
    int b[p][q];
    //multiply array
    int res[m][q];
    if(n==p){
        cout << "Enter the elements of the first matrix: ";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        cout << "Enter the elements of the second matrix: ";
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                cin >> b[i][j];
            }
        } 
        //multiply
        
            for(int i=0; i<m; i++){
                for(int j=0; j<q; j++){
                    res[i][j] = 0;
                    for(int k=0; k<n; k++){ // ek row kitne baar multiply ho raha  we can use k<p also at place of k<n
                        res[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            cout<<endl;
            //print result
            for(int i=0; i<m; i++){
                for(int j=0; j<q; j++){
                    cout << res[i][j] << " ";
                }
                cout << endl;
 
            }
        
    }
    else{
        cout << "Error: The number of columns of first matrix must be equal to the number of rows of second matrix." << endl;
        return 0;
    }
   
}