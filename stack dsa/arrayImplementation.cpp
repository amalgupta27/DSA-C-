#include<bits/stdc++.h>
using namespace std;

// User-defined Stack class (custom stack implementation using array)
class Stack {
public:
    int arr[5];    // Fixed size array of 5 elements (stack ka storage)
    int idx = -1;  // Index of top element, initially -1 means stack is empty

    // Push function - value ko stack me daalna
    void push(int val) {
        if (idx == 4) {  // Agar idx 4 hai to stack full ho gaya (kyunki size 5 hai)
            cout << "stack is full means overflow" << endl;
            return;  // Aur kuch mat karo, wapas chalo
        }
        idx++;           // Pehle index badhao
        arr[idx] = val;  // Phir us index pe value daal do
    }

    // Pop function - stack se top value hataana
    void pop() {
        if (idx == -1) {  // Agar idx -1 hai to stack khali hai
            cout << "stack is empty! means underflow" << endl;
            return;
        }
        idx--;  // Top value hataane ke liye sirf index kam karna hai
    }

    // Top function - current top value return karega
    int top() {
        if (idx == -1) {  // Agar stack empty hai
            cout << "stack is empty! means underflow" << endl;
            return -1;  // Error value return karte hain
        }
        return arr[idx];  // Current top value return karo
    }

    // Size function - stack me kitne elements hain wo batata hai
    int size() {
        return idx + 1;  // Kyunki idx 0-based hai, isliye +1 karna padega
    }
};

int main() {
    Stack st;  // Apna custom stack banaya

    // Stack me kuch values push kar rahe hain
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // Ye 6th value hai, stack full ho chuka hai, isliye overflow message aayega
    st.push(60);

    // Stack ka size print karo (jitne elements successfully daale gaye)
    cout << st.size() << endl;

    // Stack ka top element print karo (last inserted value)
    cout << st.top() << endl;
}
