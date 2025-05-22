#include<iostream>
#include<queue>
using namespace std;
void display(queue<int> q){
    int n = q.size();
    for(int i=0; i<n; i++){
        cout<<q.front()<<" ";
        q.pop();
        q.push(q.front());
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    // push
    // pop
    // front -> top
    // size , empty
    // back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q); // 10 20 30 40 50
  
    q.pop(); // 10
    display(q); // 20 30 40 50
    cout<<q.front()<<endl; // 20
}