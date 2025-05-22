#include <iostream>
#include<vector>
using namespace std;

int main() {
    
    int m;
    cout << "Enter the number of row : ";
    cin >> m;
    int n;
    cout << "Enter the number of column : ";
    cin >> n;
    int arr[m][n];
    //take input
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    cout<<endl;
    vector<int> v;
    int maxr=m-1;
     int maxc=n-1;
    int minr=0;
    int minc=0;
    while(minr<=maxr && minc<=maxc) {
       //right
    for(int j=minc; j<=maxc; j++){
       v.push_back(arr[minr][j]);
    }
     minr++;
     if(minr>maxr || minc>maxc) break;
    //down
    for(int i=minr; i<=maxr; i++){
        v.push_back(arr[i][maxc]);
    }
    maxc--;
     if(minr>maxr || minc>maxc) break;
    //left
    for(int j=maxc; j>=minc; j--){
        v.push_back(arr[maxr][j]);
       
    }
     maxr--;
      if(minr>maxr || minc>maxc) break;
    //up
    for(int i=maxr; i>=minr; i--){
        v.push_back( arr[i][minc]);
    }
    minc++;
     if(minr>maxr || minc>maxc) break;
    }
     
}