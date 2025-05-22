 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

int main(){
    vector<int> v={5,-1,2,-6,0};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int s=0;
    int e=v.size()-1;
    while(s<e){
        if(v[s]<0) s++;
        else if(v[e]>=0)  e--;
        else{
            swap(v[s],v[e]);  
            s++;
            e--;
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
 
}