#include<iostream>
using namespace std;
class Student{// Student id a new data type
public:
    string name;
    int rno;
    float cgpa;
};

int main(){
    Student s1;
    s1.name= "Amal Gupta";
    //s1.rno = 25;
    //or 
    cout<<"Enter the roll no. of s1: "<<endl;
    cin>>s1.rno;
    s1.cgpa = 8.0;

    Student s2;
    s2.name= "Vikash Gupta";
    s2.rno = 52;
    s2.cgpa = 8.4;

    cout<<s1.name <<" "<<s1.cgpa <<" "<<s1.rno<<endl;
    cout<<s2.name <<" "<<s2.cgpa <<" "<<s2.rno<<endl;
    
}