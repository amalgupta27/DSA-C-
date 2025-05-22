#include<bits/stdc++.h>
using namespace std;
/*
==================== PROBLEM: Min Stack ====================

🧠 Question ka Matlab (Hinglish me):
Ek special stack banana hai jisme 4 operations fast ho sakein:

1. push(x)    → stack me x daalo
2. pop()      → top element hatao
3. top()      → top element batao
4. getMin()   → stack ka ab tak ka minimum element batao

⚠️ Sab operations O(1) time me hone chahiye.

---------------------------------------------------------------------
💡 Best Optimized Logic (Method 3): Single stack + encoded value

Jab bhi koi element stack me daalte ho, check karo:
- Agar `val >= min`, toh normal push karo.
- Agar `val < min`, toh ek **fake encoded value** push karo => `2*val - min`
  Aur phir `min = val` bana do.

Pop karte waqt:
- Agar top >= min: normal pop
- Agar top < min: toh wo fake value hai
  Decode karo: `min = 2*min - st.top()`

📦 Dry Run Example:
Let’s push: [5, 3, 7, 2]
Initial min = ∞

Push(5): st = [5], min = 5  
Push(3): st = [5, (2*3 - 5)=1], min = 3  
Push(7): st = [5, 1, 7], min = 3  
Push(2): st = [5, 1, 7, (2*2 - 3)=1], min = 2

Pop(): st.top() = 1 < min, so min = 2*2 - 1 = 3  
=> New min = 3

-------------------------------------------------------------
📊 Flow Chart in Hinglish (ASCII-art Style):

           +-----------------------------+
           | Push karte waqt             |
           +-----------------------------+
                  |
                  v
    +---------------------------+
    | Agar val >= min → normal |
    +---------------------------+
                  |
                  v
    +---------------------------+
    | Agar val < min  →         |
    | Push fake = 2*val - min  |
    | Update min = val         |
    +---------------------------+

           +-----------------------------+
           | Pop karte waqt              |
           +-----------------------------+
                  |
                  v
    +---------------------------+
    | Agar top >= min → normal |
    +---------------------------+
                  |
                  v
    +---------------------------+
    | Agar top < min →          |
    | It's fake value → decode |
    | min = 2*min - top         |
    +---------------------------+

-------------------------------------------------------------
⏱️ Time & Space Complexity:
- push(), pop(), top(), getMin() → O(1)
- Space: O(1) extra, O(n) for stack
*/

class MinStack {
public: 
    // METHOD 3 : Most Optimized (Single Stack)
    // TC = O(1), SC = O(1) extra

    stack<long long> st;
    long long min;  // current minimum

    MinStack() { 
        min = LLONG_MAX;
    }
    
    void push(int val) {
        long long x = (long long)val;
        if (st.empty()) {
            st.push(x);
            min = x;
        } else if (x >= min) {
            st.push(x);
        } else {
            // push fake value
            st.push(2*x - min);
            min = x;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        if (st.top() >= min) {
            st.pop();
        } else {
            // fake value detected → update min
            min = 2*min - st.top();
            st.pop();
        }
    }
    
    int top() {
        if (st.top() >= min) return (int)st.top();
        else return (int)min; // top is fake → real top is min
    }
    
    int getMin() {
        return (int)min;
    }
};


/*
==================== METHOD 2 ====================
🎯 Extra Stack (Same size)
💡 Logic: har push ke sath min bhi helper stack me push karo

stack<int> st;
stack<int> helper;

MinStack() {}

void push(int val) {
    st.push(val);
    if (helper.empty() || val < helper.top()) 
        helper.push(val);
    else 
        helper.push(helper.top());  // repeat previous min
}

void pop() {
    st.pop();
    helper.pop();
}

int top() {
    return st.top();
}

int getMin() {
    return helper.top();
}

⏱️ Time Complexity: O(1) for all ops
📦 Space Complexity: O(n) extra
*/


/*
==================== METHOD 1 ====================
🎯 Naive Approach
💡 Logic: getMin() me har baar stack traverse karo

stack<int> st;

MinStack() {}

void push(int val) {
    st.push(val);
}

void pop() {
    st.pop();
}

int top() {
    return st.top();
}

int getMin() {
    stack<int> temp;
    int mn = INT_MAX;
    while (!st.empty()) {
        mn = min(mn, st.top());
        temp.push(st.top());
        st.pop();
    }
    // Restore elements back
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
    return mn;
}

⏱️ Time Complexity:
- push/pop/top → O(1)
- getMin() → O(n) ❌ TLE
📦 Space: O(n) temporary
*/


/*
🔁 How to use:
MinStack* obj = new MinStack();
obj->push(5);
obj->push(3);
obj->getMin(); // returns 3
obj->top();    // returns 3
obj->pop();    // removes 3
obj->getMin(); // returns 5
*/

