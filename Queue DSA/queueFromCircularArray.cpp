#include<iostream>
#include<vector>
using namespace std;
class Queue{
public:   
    int f; // front
    int b; // rear
    int s; // size
    vector<int> arr; // array to store queue elements
    Queue(int val){
        f = 0;
        b = 0; 
        s =0;
        vector<int> v(val);
        arr = v;
    }
    void push(int val){
        if(b==arr.size()){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[b] = val;
        b++;
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f++;
        s--;
    }
    int front(){
        if(s==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(s==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0){
            return true;
        }
        return false;
    }
    void display(){
        if(s==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=f; i<b; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};

int main(){
    Queue q(5);
    // push , pop , front -> top , back , size , empty
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display(); // 10 20 30 40
    q.push(50);
    q.push(60);
    q.display(); // 10 20 30 40 50 60
    q.pop(); // 10
    q.display(); // 20 30 40 50 60
}