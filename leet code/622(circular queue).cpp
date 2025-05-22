#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    int f; // front index
    int b; // back/rear index (next insert position)
    int s; // current size of queue
    int c; // total capacity
    vector<int> arr; // array to hold queue elements

    // Constructor: Queue ka size set karte hain
    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        s = 0;
        c = k; // total capacity ko k set karo
        arr = vector<int>(k); // vector initialize with size k
    }

    // Enqueue operation: naya element insert karo
    bool enQueue(int val) {
        if (s == c) return false; // agar full hai, insert nahi kar sakte
        arr[b] = val;             // value ko insert karo back pe
        b = (b + 1) % c;          // circularly agla position set karo
        s++;                      // size increase
        return true;
    }

    // Dequeue operation: front se element hatao
    bool deQueue() {
        if (s == 0) return false; // agar empty hai, hata nahi sakte
        f = (f + 1) % c;          // circularly front aage badhao
        s--;                      // size kam karo
        return true;
    }

    // Front element ko return karo
    int Front() {
        if (s == 0) return -1;    // agar empty hai, to -1
        return arr[f];           // warna front element
    }

    // Rear element ko return karo
    int Rear() {
        if (s == 0) return -1;                // agar empty hai, to -1
        return arr[(b - 1 + c) % c];          // rear element (wrap around)
    }

    // Queue empty hai ya nahi
    bool isEmpty() {
        return s == 0;
    }

    // Queue full hai ya nahi
    bool isFull() {
        return s == c;
    }
};

/*
    🧪 Example:
    -------------------
    MyCircularQueue* obj = new MyCircularQueue(3);  // capacity = 3

    obj->enQueue(10);  // returns true
    obj->enQueue(20);  // returns true
    obj->enQueue(30);  // returns true
    obj->enQueue(40);  // returns false (full)

    obj->Front();      // returns 10
    obj->Rear();       // returns 30

    obj->deQueue();    // removes 10
    obj->enQueue(40);  // adds 40 at circular position

    obj->Rear();       // returns 40
*/

