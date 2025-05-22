#include <iostream>
#include <vector>
using namespace std;

int main() {
    // vector declare kiya - yaha size batana zaroori nahi hota
    vector<int> v;

    // vector me elements push_back() se add kar rahe hain
    v.push_back(6);
    v.push_back(1);
    v.push_back(9);
    v.push_back(0);
    v.push_back(7);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);

    // vector ka current size print karenge (kitne elements hain)
    cout << "Size is: " << v.size() << endl;

    // vector ki current capacity print karenge (kitni memory reserve ki gayi hai)
    // Note: jab size aur capacity same ho jate hain, to capacity double ho jati hai
    cout << "capacity is: " << v.capacity() << endl;

    // vector ke elements print kar rahe hain using indexing
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // pop_back() se last 2 elements remove kar diye
    v.pop_back();
    v.pop_back();

    // ab updated vector print karte hain
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
      