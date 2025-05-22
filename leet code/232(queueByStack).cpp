#include<bits/stdc++.h>
using namespace std;
/*
🧠 Problem: Queue using Stacks (Implement FIFO using LIFO structure)

🎯 Goal: Queue jisme elements FIFO (First In First Out) tareeke se handle hoon.
Stack naturally LIFO (Last In First Out) hota hai, toh 2 stacks ka use karke queue banana hai.

🛠️ METHOD 2: POP EFFICIENT (Enable below)

- ✅ pop(), peek() = FAST (O(1))
- ❌ push() = SLOW (O(n))

💡 Logic:
- Jab bhi push karna ho:
    - Pehle sab purane elements ko ek helper stack me daal do (taaki order ulta ho jaaye)
    - Phir naye element ko push karo
    - Phir helper se sab wapas original stack me daal do
    ➤ Isse naya element sabse neeche chala jaata hai

- Jab pop/peek karna ho:
    - Simply top se karo (kyunki correct order already maintained hai)

📊 Time Complexity:
- push(x): O(n)
- pop(): O(1)
- peek(): O(1)
- empty(): O(1)

🧠 Example:
Operations: push(10), push(20), push(30), pop()

Step 1: push(10)
    st: [10]

Step 2: push(20)
    helper <- 10
    st <- 20
    st <- 10
    final st: [20, 10]

Step 3: push(30)
    helper <- 10, 20
    st <- 30
    st <- 20, 10
    final st: [30, 20, 10]

Step 4: pop()
    top = 10 (which is front of queue) → perfect!

📈 st = main stack (actual queue)
📉 helper = helper stack (temporary reversal)
*/

class MyQueue {
public:
    // ---------------------
    // METHOD 1: PUSH EFFICIENT (Commented Out)
    /*
    stack<int> st;
    stack<int> helper;

    MyQueue() {}

    void push(int x) {
        st.push(x); // O(1)
    }

    int pop() {
        while (st.size() > 0) {
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        while (helper.size() > 0) {
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }

    int peek() {
        while (st.size() > 0) {
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        while (helper.size() > 0) {
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }

    bool empty() {
        return st.empty();
    }
    */

    // ---------------------
    // METHOD 2: POP EFFICIENT (Enabled)
    stack<int> st;
    stack<int> helper;

    MyQueue() {
        // Constructor – kuch bhi initialize karna ho to yahan kar sakte hain
    }

    // O(n): push karne me lagta hai time kyunki order maintain karna padta hai
    void push(int x) {
        // Agar stack empty hai toh seedha push kar do
        if(st.size() == 0){
            st.push(x);
            return;
        }

        // Step 1: st ke sab elements helper me daalo (reverse order)
        while(st.size() > 0){
            helper.push(st.top());
            st.pop();
        }

        // Step 2: x ko push karo (ye ab sabse neeche chala jaayega)
        st.push(x);

        // Step 3: wapas helper ke elements st me daalo (original order ban jaayega)
        while(helper.size() > 0){
            st.push(helper.top());
            helper.pop();
        }
    }

    // O(1): direct pop from top (jo queue ka front hai)
    int pop() {
        int x = st.top();  // front of queue
        st.pop();
        return x;
    }

    // O(1): just see the top
    int peek() {
        return st.top(); // front of queue
    }

    // O(1): check if stack is empty
    bool empty() {
        return st.empty();
    }
};

/*
🔁 Usage Example:
MyQueue q;
q.push(10);    // queue: 10
q.push(20);    // queue: 10 20
q.push(30);    // queue: 10 20 30
q.pop();       // returns 10
q.peek();      // returns 20
q.empty();     // false

✅ This method is useful when you want fast pop/peek operations
*/
