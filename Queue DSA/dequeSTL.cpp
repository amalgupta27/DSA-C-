#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(0);
    cout<<dq.front()<<endl; // 0
    cout<<dq.back()<<endl; // 3
    cout<<dq.size()<<endl; // 4
    dq.pop_front();
    cout<<dq.front()<<endl; // 1
    dq.pop_back();
    cout<<dq.back()<<endl; // 2
    cout<<dq.size()<<endl; // 2
    dq.clear();
    cout<<dq.size()<<endl; // 0
    cout<<dq.empty()<<endl; // 1 (true)
    dq.push_back(5);
    cout<<dq.front()<<endl; // 5
    cout<<dq.back()<<endl; // 5
}