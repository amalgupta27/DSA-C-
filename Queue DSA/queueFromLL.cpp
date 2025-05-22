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
class Queue {
public:
    Node* head;
    Node* tail;
    int s; // size

    Queue() {
        head = tail = NULL;
        s = 0;
    }

    void push(int val) {
        Node* temp = new Node(val);
        if (s == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        s++;
    }

    void pop(){
        if(s==0){
            cout<<"queue is Empty!";
            return;
        }
        Node* temp= head;
        head = head->next;
        s--;
        delete(temp);
    }
    int front(){
        if(s==0){
            cout<<"queue is Empty!";
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s==0){
            cout<<"queue is Empty!";
            return -1;
        }
        return tail->val;
    }
    

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout<< endl;
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0){
            return true;
        }
        return false;
    }
};
int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Queue: ";
    q.display();
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    q.pop();
    cout << "After pop, Queue: ";
    q.display();
    return 0;
}
