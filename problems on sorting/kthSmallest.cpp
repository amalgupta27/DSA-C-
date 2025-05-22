#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[]={12,14,3,2,4,7,6,5,8,9,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //selection sort upto k
    for(int i=0; i<k; i++){
       int max=arr[i];
       int minIndex=i;
       for(int j=i; j<n; j++){
         if(arr[j]<max){
             max=arr[j];
             minIndex=j;
         }
       }
       swap(arr[i],arr[minIndex]);
    }
    //displaying
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}