#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sort01(vector<int> &v){
    int noo= 0;
    int noz=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]==0){
            noz++;
        }
        else noo++;
    }
    for(int i=0; i<v.size(); i++){
        if(i<noz) v[i]=0;
        else v[i]=1;
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v={0,1,1,0,0};
    for(int i=0; i<=v.size()-1; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
   // sort(v.begin(), v.end());
   //OR
    sort01(v);
    cout<<"\nSorted array: ";
    for(int i=0; i<=v.size()-1; i++){
        cout<<v[i]<<" ";
    }
}