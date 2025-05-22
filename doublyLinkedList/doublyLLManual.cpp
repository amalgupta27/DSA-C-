#include<bits/stdc++.h>
using namespace std;

// Node class banayi hai Doubly Linked List (DLL) ke liye
class Node { 
    public:
    int val; // Node ka data
    Node* next; // Next node ka pointer
    Node* prev; // Previous node ka pointer (DLL ka extra feature)

    // Constructor: jab naye node banayein to value set karni hai aur next, prev NULL honge
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Linked list ko aage se print karne ka function
void display(Node* head){
    while (head != NULL){
        cout << head->val << " "; // Node ka data print karte jao
        head = head->next;        // Next node pe move karo
    }
    cout << endl;
}

// Linked list ko piche se (reverse) print karne ka function
void displayRevp(Node* tail){
    while (tail != NULL){
        cout << tail->val << " "; // Node ka data print karte jao
        tail = tail->prev;        // Prev node pe move karo (DLL ka fayda)
    }
    cout << endl;
}

// Linked list ko recursion se aage se print karna
void displayRec(Node* head){
    if(head == NULL) return; // Base case: jab head NULL ho jaye to return kar jao
    cout << head->val << " "; // Pehle current node ka data print karo
    displayRec(head->next);   // Recursively next node pe jao
    cout << endl;             // Line break after each call (aap isse hata bhi sakte ho)
}

// Linked list ko recursion se reverse me print karna
void displayRecRev(Node* head){
    if(head == NULL) return;    // Base case: jab head NULL ho jaye to return
    displayRecRev(head->next);  // Pehle last node tak jao (recursive call)
    cout << head->val << " ";   // Wapas aate waqt data print karo (reverse order me)
}

int main(){
    // Nodes create kiye hain with values: 10 20 30 40 50
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    // Nodes ko aapas me link kiya hai (forward linking)
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // Nodes ko piche se link kiya hai (backward linking - DLL ka feature)
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    // List ko aage se print kar rahe hain
    display(a);

    // List ko recursion se aage se print kar rahe hain
    displayRec(a);

    // List ko recursion se reverse me print kar rahe hain
    displayRecRev(a);

    // List ko piche se print kar rahe hain (using prev pointers)
    displayRevp(e);
}
