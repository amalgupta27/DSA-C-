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
class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // Insert at start
    void insertAtStart(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    // Insert at specific index
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
            for (int i = 0; i < idx - 1; i++) {
                temp = temp->next;
            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            size++;
        }
    }

    // Get value at index
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

    // Delete head
    void deleteAtHead() {
        if (size == 0) {
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
        size--;
    }

    // Delete tail
    void deleteAtTail() {
        if (size == 0) {
            cout << "List is Empty!" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        else {
            head = NULL; // List becomes empty
        }
        delete temp;
        size--;
    }

    // Delete at specific index
    void deleteAtIdx(int idx) {
        if (size == 0) {
            cout << "List is Empty!" << endl;
            return;
        }
        if (idx < 0 || idx >= size) {
            cout << "Invalid Index" << endl;
            return;
        }
        if (idx == 0) {
            deleteAtHead();
            return;
        }
        if (idx == size - 1) {
            deleteAtTail();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display backward
    void displayBackward() {
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->val << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.displayForward();       

    ll.insertAtStart(9);
    ll.displayForward();        

    ll.insertAtIdx(3, 25); // Insert 25 at index 3
    ll.displayForward();          

    // Testing getAtIdx
    cout << "Value at index 2: " << ll.getAtIdx(2) << endl; // Should print 20
    cout << "Value at index 3: " << ll.getAtIdx(3) << endl; // Should print 25

    // Deleting nodes
    ll.deleteAtHead();
    ll.displayForward();

    ll.deleteAtTail();
    ll.displayForward();

    ll.deleteAtIdx(2);
    ll.displayForward();

    cout << "Display backward:" << endl;
    ll.displayBackward();
}
