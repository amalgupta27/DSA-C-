#include<iostream>
using namespace std;
class Student{// Student id a new data type
public:
    string name;
    int rno;
    float cgpa;
    //constructor
    // In C++, a constructor is a special member function of a class 
    // that is automatically called when an object of that class is created. 
    // It has the same name as the class and does not have a return type.

    //default constructor
    // Student(){

    // }
    Student(string s, int r){ //parameterised constructor
         name = s;
         rno = r;
    }
    Student(string s, int r, float g){ //parameterised constructor
         name = s;
         rno = r;
         cgpa = g;   
    }
    Student(int r,string s, float g){ //parameterised constructor
         name = s;
         rno = r;
         cgpa = g;   
    }
};

int main(){
    Student s1("Amal Gupta",25);
    //s1.name= "Amal Gupta";
    //s1.rno = 25;
    //or 
    // cout<<"Enter the roll no. of s1: "<<endl;
    // cin>>s1.rno;
    // s1.cgpa = 8.0;

    Student s2("vikash gupta",52,8.2);
    // s2.name= "Vikash Gupta";
    // s2.rno = 52;
    // s2.cgpa = 8.4;
    Student s3(12,"Rahul",7.0);

    Student s4=s2; // deep copy
    s4.name= "Don";

    Student s5(s1); // copy constructor -> deep copy

    cout<<s1.name <<" "<<" "<<s1.rno<<endl;
    cout<<s2.name <<" "<<s2.cgpa <<" "<<s2.rno<<endl;
    cout<<s3.name <<" "<<s3.cgpa <<" "<<s3.rno<<endl;
    cout<<s4.name <<" "<<s4.cgpa <<" "<<s4.rno<<endl;
    cout<<s5.name <<" "<<s5.cgpa <<" "<<s5.rno<<endl;
    
} 