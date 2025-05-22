#include <bits/stdc++.h>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// LinkedList class
class Deque { 
public:
    Node* head;
    Node* tail;
    int s;

    Deque() {
        head = tail = NULL;
        s = 0;
    }

    // Insert at end
    void pushBack(int val) {
        Node* temp = new Node(val);
        if (s == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        s++;
    }

    // Insert at start
    void pushFront(int val) {
        Node* temp = new Node(val);
        if (s == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        s++;
    }

  
    // Delete head
    void popFront() {
        if (s == 0) {
            cout << "List is Empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL; // List becomes empty
        }
        delete temp;
        s--;
    }

    // Delete tail
    void popBack() {
        if(s==0){
            cout<<"List is Empty!"<<endl;
            return;
        }
        else if(s==1){
            popFront();
            return;
        }
        else{
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    void front() {
        if (s == 0) {
            cout << "Deque is Empty!" << endl;
            return;
        }
        cout << head->val << endl;
    }

    void back() {
        if (s == 0) {
            cout << "Deque is Empty!" << endl;
            return;
        }
        cout << tail->val << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int size() {
        return s;
    }
    bool empty() {
        return s == 0;
    }
};
int main() {
    Deque dq;

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40);
    dq.display(); // 10 <-> 20 <-> 30 <-> NULL

    dq.pushFront(5);
    dq.display(); // 5 <-> 10 <-> 20 <-> 30 <-> NULL

    dq.popFront();
    dq.display(); // 10 <-> 20 <-> 30 <-> NULL

    dq.popBack();
    dq.display(); // 10 <-> 20 <-> NULL

    cout << "Front: ";
    dq.front(); // Should print 10
    cout << "Back: ";
    dq.back(); // Should print 20

    return 0;
}