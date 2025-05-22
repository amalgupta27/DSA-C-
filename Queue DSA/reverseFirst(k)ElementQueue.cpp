/*
    ---------------------------------------------------------------
    |                   REVERSE FIRST K ELEMENTS OF QUEUE         |
    ---------------------------------------------------------------

    Question ka logic (Hinglish mein):

    1. Queue ke first 'k' elements ko reverse karna hai, baaki elements same order mein rehne chahiye.
    2. Iske liye hum stack ka use karenge, kyunki stack LIFO (Last In First Out) hota hai.
    3. Pehle queue ke first 'k' elements stack mein daal do (push karo).
    4. Stack se elements nikaal ke wapas queue mein daal do (ab yeh reverse ho jayenge).
    5. Ab queue ke baaki elements (n-k) ko wapas queue ke end mein bhej do taki order maintain rahe.

    Example:
    Queue: 1 2 3 4 5 6, k = 3
    Step 1: Stack mein 1, 2, 3 daal do (Stack: 3(top),2,1)
    Step 2: Stack se nikaal ke queue mein daalo (Queue: 4 5 6 3 2 1)
    Step 3: Baaki elements (4,5,6) ko wapas end mein bhejo (Queue: 3 2 1 4 5 6)

    ---------------------------------------------------------------
    |                   FLOW CHART (Hinglish)                     |
    ---------------------------------------------------------------

    [Start]
       |
       v
    [Queue aur k input lo]
       |
       v
    [First k elements Stack mein daalo]
       |
       v
    [Stack se elements nikaal ke Queue mein daalo]
       |
       v
    [Baaki (n-k) elements ko Queue ke end mein bhejo]
       |
       v
    [Queue display karo]
       |
       v
    [End]

    ---------------------------------------------------------------
    Time Complexity:
    - Stack mein push/pop: O(k)
    - Queue mein pop/push: O(n)
    - Total: O(n), jahan n = queue ka size

    ---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Queue ko display karne ka function
void display(queue<int> q){
    int n = q.size();
    // Queue ke saare elements print karo
    for(int i=0; i<n; i++){
        cout<<q.front()<<" ";
        q.pop();
        // Queue ka order maintain karne ke liye wapas push kar diya
        q.push(q.front());
    }
    cout<<endl;
}

/*
    reverseK function:
    - k: kitne elements reverse karne hain
    - q: queue ka reference
    Example: Queue = 1 2 3 4 5 6, k = 3
    Output: 3 2 1 4 5 6
*/
void reverseK(int k, queue<int> &q){
    stack<int> st;
    // Step 1: First k elements stack mein daalo
    for(int i=0; i<k; i++){
        st.push(q.front()); // Stack mein push
        q.pop();           // Queue se hatao
    }
    // Step 2: Stack se nikaal ke queue mein daalo (reverse ho jayenge)
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    // Step 3: Baaki (n-k) elements ko wapas end mein bhejo
    int size = q.size();
    for(int i=0; i<size-k; i++){
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    // Queue mein elements daal rahe hain
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout << "Original Queue: ";
    display(q);

    int k = 3;
    reverseK(k, q);

    cout << "Queue after reversing first " << k << " elements: ";
    display(q);

    // Example Output:
    // Original Queue: 1 2 3 4 5 6
    // Queue after reversing first 3 elements: 3 2 1 4 5 6
}