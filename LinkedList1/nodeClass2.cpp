#include<iostream>  // Input-Output stream ka header file include kiya
using namespace std; // std namespace ka use kiya, taaki har baar std:: likhne ki zarurat na ho

// Node class banayi - Linked List ka ek node represent karega
class Node { 
public:
    int val;       // Node ke andar ek value hogi
    Node* next;    // aur ek pointer hoga jo next node ko point karega

    // Constructor - jab naya node banega tab value set karega aur next NULL hoga
    Node(int val) {
        this->val = val;   // 'this' ka use kiya kyunki parameter aur member ka naam same hai
        this->next = NULL; // initially koi next node nahi hai, isliye NULL
    }
};

// Function to display Linked List ka data
void display(Node* head) {
    Node* temp = head; // temp pointer se head ko point kiya
    while (temp != NULL) { // jab tak temp NULL nahi hota
        cout << temp->val << " "; // current node ki value print karo
        temp = temp->next;        // temp ko next node par le jao
    }
    cout << endl; // saari values print hone ke baad ek line change
}

// Function to calculate Linked List ka size
int size(Node* head) {
    Node* temp = head; // temp pointer se head ko point kiya
    int n = 0;         // count karne ke liye n variable 0 se initialize kiya
    while (temp != NULL) { // jab tak temp NULL nahi hota
        temp = temp->next; // temp ko next node par le jao
        n++;              // ek node mila to count badhao
    }
    return n; // total nodes ka count return karo
}

// Main function
int main() {
    // 5 naye nodes banaye, values ke saath
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    // Nodes ko link kiya - ek ke baad ek
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    display(a); // Linked List ko print kiya
    cout << "Size of Linked List: " << size(a) << endl; // aur uska size print kiya
}
