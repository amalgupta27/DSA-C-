#include<bits/stdc++.h>
using namespace std;

// Node class - har node ek value aur ek pointer rakhta hai jo next node ko point karta hai
class Node {
public:
    int val;         // Node ki value
    Node* next;      // Pointer to next node

    // Constructor – naya node banate waqt value set karna aur next ko NULL karna
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Stack class – Linked List ki help se banayi gayi stack
class Stack {
public:
    Node* head;   // Stack ke top ko point karta hai
    int size;     // Stack ke elements ka count

    // Constructor – initial me head NULL aur size 0 hota hai
    Stack() {
        head = NULL;
        size = 0;
    }

    // Push function – naye element ko stack me daalna (top par)
    void push(int val) {
        Node* temp = new Node(val);  // Naya node banao
        temp->next = head;           // Uska next purane top ko point karega
        head = temp;                 // Ab ye naya node hi top ban gaya
        size++;                      // Size badha do
    }

    // Pop function – stack ke top element ko hataana
    void pop() {
        if (head == NULL) {  // Agar stack empty hai
            cout << "stack is empty!" << endl;
            return;
        }
        head = head->next;  // Top ko uske neeche wale node pe le jao
        size--;             // Size kam kar do
    }

    // Top function – current top value return karta hai
    int top() {
        if (head == NULL) {  // Agar stack khali hai
            cout << "stack is empty!" << endl;
            return -1;
        }
        return head->val;    // Top value return karo
    }

    // Recursive function – stack ke elements ko reverse order me print karta hai
    void printrev(Node* temp) {
        if (temp == NULL) return;       // Base condition
        printrev(temp->next);           // Pehle next call karo (recursion)
        cout << temp->val << " ";       // Baad me print karo (reverse effect)
    }

    // Display function – stack ke elements ko reverse order me dikhata hai (bottom to top)
    void display() {
        Node* temp = head;
        // Agar ascending order me (top to bottom) print karna ho to ye loop use karo:
        /*
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        */
        printrev(temp);  // Recursive reverse print
        cout << endl;
    }
};

int main() {
    Stack st;  // Apna stack object banaya

    // Stack me kuch values push kar rahe hain (LIFO: Last In First Out)
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    // Stack ka current size print karo
    cout << st.size << endl;

    // Stack ke top pe jo value hai usse print karo
    cout << st.top() << endl;

    // Stack ke elements ko display karo (bottom to top)
    st.display();
}
