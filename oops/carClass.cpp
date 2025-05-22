#include<iostream>
using namespace std;
class Car{// Student id a new data type
public:
    string name;
    int price;
    float seats;
    string type;
};
void print(Car c){
     cout<<c.name<<" "<<c.price<< " "<<c.seats<<" "<<c.type<<" "<<endl;
}
void change(int x){ //pass by value
     x=10; 
}
int main(){
    int x =4;
    cout<<x<<endl;
    change(x);
    cout<<x<<endl;

    Car c1;
    c1.name = " Honda city";
    c1.price = 1500000;
    c1.seats = 5;
    c1.type = "Sedan";

    Car c2;
    c2.name = " Maruti Swift";
    c2.price = 700000;
    c2.seats = 5;
    c2.type = "Hatchback";

    Car c3;
    c3.name = " Totoya Fortuner";
    c3.price = 3600000;
    c3.seats = 8;
    c3.type = "SUV";

    print(c1);
    print(c2);
    print(c3);

}