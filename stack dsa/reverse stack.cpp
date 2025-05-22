#include<iostream>
#include<stack>
using namespace std;

// Function to print stack ke elements bina unhe permanently hataye hue
void print(stack<int> st){
    stack<int> temp;

    // Jab tak stack empty nahi ho jaata, tab tak top element print karo aur temp me daal do
    while(st.size() > 0){
        cout << st.top() << " ";  // Top element print karo
        temp.push(st.top());      // Top element temp stack me daal do
        st.pop();                 // Original stack se top element hata do
    }

    // Ab temp stack ke elements wapas original stack me daal do (taaki stack original state me aa jaye)
    while(temp.size() > 0){
        st.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

int main(){
    stack<int> st;

    // Stack me kuch elements daal rahe hain
    st.push(10);
    st.push(20);
    st.push(30); 
    st.push(40);
    st.push(50);

    // Stack ke elements print kar rahe hain (original order me)
    print(st);

    // Ab hum stack ko reverse karne wale hain 3 stacks ka use karke
    stack<int> gt;
    stack<int> rt;

    // Step 1: st ke elements ko gt me daal do
    // st: 10 bottom -> 50 top
    // gt: 50 bottom -> 10 top
    while(st.size() > 0){
        gt.push(st.top());  // Top element gt me daalo
        st.pop();           // st se hata do
    }

    // Step 2: gt ke elements ko rt me daal do
    // rt: 10 bottom -> 50 top (reverse ho gaya ab stack)
    while(gt.size() > 0){
        rt.push(gt.top());
        gt.pop();
    }

    // Step 3: rt ke elements ko wapas st me daal do
    while(rt.size() > 0){
        st.push(rt.top());
        rt.pop();
    }

    // Ab st stack reverse ho chuka hai
    cout << "After reversing it:-" << endl;
    print(st);
}
