#include<bits/stdc++.h>
using namespace std;

// Custom Stack class using vector (vector se overflow ka issue nahi hota)
class Stack {
public:
    vector<int> v;  // Vector ka use kiya gaya hai stack ko banane ke liye

    // Default constructor
    Stack() {
        // Kuch bhi initialization ki zarurat nahi hai yahan
    }

    // Push function – naya element stack me daalne ke liye
    void push(int val) {
        v.push_back(val);  // Vector ke end me element add karo
    }

    // Pop function – top element hataane ke liye
    void pop() {
        if (v.size() == 0) {  // Agar vector empty hai to stack bhi khali hai
            cout << "stack is empty! means underflow" << endl;
            return;
        }
        v.pop_back();  // Vector ke end se element hata do (top se)
    }

    // Top function – current top element ko return karega
    int top() {
        if (v.size() == 0) {  // Agar stack empty hai
            cout << "stack is empty! means underflow" << endl;
            return -1;  // Error value return karo
        }
        return v[v.size() - 1];  // Last element hi stack ka top hota hai
    }

    // Size function – stack me kitne elements hai yeh batata hai
    int size() {
        return v.size();  // Vector ka size hi stack ka size hai
    }
};

int main() {
    Stack st;  // Apna custom stack banaya vector ke through

    // Stack me kuch values daal rahe hain
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    // Stack ka size print karo (total elements kitne hain)
    cout << st.size() << endl;

    // Stack ka top element print karo (last pushed element)
    cout << st.top() << endl;
}
