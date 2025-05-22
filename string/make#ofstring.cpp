#include<iostream>
#include<string>

using namespace std;

int main(){
    string s= "";
    int n;
    cout<<"Enter the size of string"<<endl;
    cin>>n;
    //original string
    for(int i=0; i<n; i++){
        char c;
        cin>>c;
        s.push_back(c); 
    }
    // # at odd positions
    for(int i=0; i<n; i++){
        if(i%2==0){
            s[i] = '#';
        }
    }
    cout<<s<<endl;
}