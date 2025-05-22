#include<iostream>  // Input-output stream include kar rahe hain, taki cout/cin ka use kar sakein
using namespace std; // Standard namespace use kar rahe hain taki std:: likhne ki zarurat na ho

// Student ek user-defined class hai jisme student ka data store kar sakte hain
class Student{ // user defined data type
public:
    string name;    // Student ka naam store karega
    int rno;        // Student ka roll number store karega
    float marks;    // Student ke marks store karega

    // Constructor banaya gaya hai jo name, rno, aur marks initialize karega
    Student(string n, int r, float m){
        this->name = n;  // "this" pointer current object ko refer karta hai
                         // C++ mein object pointer ke through access hota hai isliye "->" use hota hai
                         // Java mein objects reference hote hain, wahan "." ka use hota hai

        this->rno = r;   // Roll number set kar rahe hain
        this->marks = m; // Marks set kar rahe hain
    }
};

// Ye function Student object ka pointer leta hai aur uska naam change karta hai
void change(Student* s){
    s->name = "God"; // Arrow operator se pointer ke through object ka name change kar rahe hain
}

int main(){ 
    // 'new' keyword se heap memory mein Student object create kiya ja raha hai
    Student* s = new Student("Amal", 76, 92.6);  // Amal naam ka student object banaya

    cout << s->name << endl; // Pehle student ka naam print karenge (Amal)

    change(s); // change function call kar rahe hain jo naam "God" mein badal dega

    cout << s->name << endl; // Ab updated naam print hoga (God)
}

//OR

// void change(Student s){
//     s.name= "God";
// }
// int main(){ 
//     // Student s("Amal",76,92.6);
//     // cout<<s.name<<endl;
//     // // s.name="God";
//     // // cout<<s.name<<endl;
//     // change(s); // it will not change name i.e it will pass by value , so try to do it by pass reference using(&);
//     // cout<<s.name<<endl;

//     //or do it by pointer
//     Student s("Amal",76,92.6);
//     Student* ptr= &s;
//     cout<<s.name<<endl;
//     //(*ptr).name= "Vikash"; //OR⬇️
//     ptr->name = "Vikash";
//     cout<<s.name<<endl;
    
    
// } 

