#include <bits/stdc++.h>
using namespace std;

// Node class
class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// LinkedList class
class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtEnd(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtStart(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtIdx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid Index" << endl;
        }
        else if (idx == 0) {
            insertAtStart(val);
        }
        else if (idx == size) {
            insertAtEnd(val);
        }
        else {
            Node* temp = head;
            for (int i = 1; i <= idx - 1; i++) {
                temp = temp->next;
            }
            Node* t = new Node(val);
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    // Corrected getAtIdx function
    int getAtIdx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid Index" << endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void deleteAtHead(){
        if(size==0){
            cout<<"List is Empty!";
            return;
        }
        head = head->next;
        size--;
    }

    void deleteAtTail(){
        if(size==0){
            cout<<"List is Empty!";
            return;
        }
        Node* temp= head;
        while(temp->next!=tail){
            temp= temp->next;
        }
        temp->next= NULL;
        tail= temp;
        size--; 
    }

    void deleteAtIdx(int idx){
        if(size==0){
            cout<<"List is Empty!";
            return;
        }
        else if(idx<0 || idx>=size){
            cout<<"Invalid Index";
            return;
        }
        else if(idx==0) return deleteAtHead();
        else if(idx==size-1) return deleteAtTail();
        else{
            Node* temp = head;
            for(int i=1; i<=idx-1;i++){
                temp =temp->next;
            }
            temp->next=temp->next->next;
            size--;
        }
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insertAtEnd(10); 
    ll.insertAtEnd(20); 
    ll.insertAtEnd(30); 
    ll.display();       

    ll.insertAtStart(9); 
    ll.display();        

    ll.insertAtIdx(3, 25); // Insert 25 at index 3
    ll.display();          // Expected: 9 -> 10 -> 20 -> 25 -> 30 -> NULL

    // Testing getAtIdx
    cout << "Value at index 2: " << ll.getAtIdx(2) << endl; // Should print 20
    cout << "Value at index 3: " << ll.getAtIdx(3) << endl; // Should print 25
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIdx(2);
    ll.display();
}
