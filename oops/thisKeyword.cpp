#include<bits/stdc++.h>
using namespace std;
class Cricketer{
public: 
    string name;
    int runs;
    float avg;
    Cricketer(string name, int runs){
        this->name = name; // Use 'this' to differentiate member variable from parameter
        this->runs = runs;
    }
    void print(int runs){ //using function
        cout<<name<<" "<<this->runs<<" "<<avg<<endl;
        cout<<runs<<endl;
    }
    int matches(){
        return runs/avg;
    }
};
int main(){
    Cricketer c1("M.S Dhoni",26000);
    Cricketer c2("Virat Kohli",25000);

    // cout<<c1.name<<" "<<c1.runs<<endl;
    // cout<<c2.name<<" "<<c2.runs<<endl;

    c1.print(5);
    c2.print(7);
    cout<<c1.matches()<<endl;
    cout<<c2.matches()<<endl;

}