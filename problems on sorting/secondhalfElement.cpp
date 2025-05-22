#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={12,14,3,2,4,7,6,5,8,9,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //Bubble Sort
    //i will take n/2 +1 passes
    for(int i=0; i<((n/2)+1);i++){
       for(int j=0; j<n-1-i; j++){
         if(arr[j]>arr[j+1]){
             swap(arr[j],arr[j+1]);
         }
       }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
 
}