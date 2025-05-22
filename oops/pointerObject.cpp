#include<bits/stdc++.h>
using namespace std;
class Cricketer{
public: 
    string name;
    int runs;
    float avg;
    Cricketer(string name, int runs, float avg){
        this->name = name; // Use 'this' to differentiate member variable from parameter
        this->runs = runs;
        this->avg = avg; 
    }
    
};
int main(){
    Cricketer c1("M.S Dhoni",26000,55.2);
    Cricketer c2("Virat Kohli",25000,47.8);

    Cricketer* p1= &c1;
    cout<<(*p1).runs<<endl; //c1.runs
    (*p1).avg = 77.5; // c1.avg = 77.5
    cout<<c1.avg<<endl;

    // int x=4;
    // cout<<&x<<endl;
    // int* p = &x;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // *p =100; // x=100 , *p is a dereference operator
    // cout<<x<<endl;

}