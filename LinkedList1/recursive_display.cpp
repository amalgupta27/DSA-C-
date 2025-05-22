#include<iostream>
using namespace std;

class Node { // Linked List Node
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;  // 'this' used because parameter and member have same name
        this->next = NULL;
    }
};

void displayrecord(Node* head) { //recursive method to print values
    if(head==NULL) return;  //base case
    //Node* temp = head; // this is not required
    cout<<head->val<<" ";
    displayrecord(head->next);
    cout<<endl;
}

void displayreverse(Node* head) { //recursive method to print in revese order values
    if(head==NULL) return;  //base case
    //Node* temp = head; // this is not required
    displayreverse(head->next);
    cout<<head->val<<" ";
}
void insertAtEnd(Node* head, int val){
    Node* t= new Node(val);
    while(head->next!=NULL) head= head->next;
    head->next= t;

}

int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    //displayrecord(a);
    //displayreverse(a);
    insertAtEnd(a,80);
    displayrecord(a); 
    
}
