#include<iostream>
using namespace std;
class Node{ // Linked List Node
    public:
      int val;
      Node* next;
      Node(int val){
        this->val=val;  // this used becuse in parameter val itself is called
        this->next = NULL;
    }
};
int main(){
    // 10 20 30 40
    // without using constructor
    // Node a;
    // a.val =10;
    // Node b;
    // b.val =20;
    // Node c;
    // c.val =30;
    // Node d;
    // d.val =40;
    
    //by the help of constructor
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    cout<<&a<<endl;
    cout<<a.next<<endl;
    // forming linked list

    a.next= &b;
    b.next= &c;
    c.next= &d;
    d.next= NULL;  // null will be in capital letter in c++
    // if d mein ab null nhi kiye toh ye bydefault null hoga because of this->next = NULL; in constructor
    // b kko direct ni print karna hai 
    // Node* ptr =&b;
    // ptr->val= 60;
    // cout<<(*ptr).val;
    //or
    //cout<<(a.next)->val;

    //a se sabpe jana hai
    //cout<<(((a.next)->next)->next)->val;
    Node temp =a;
    //while(temp.next!= NULL){   //iss line se d kaa value print nhi hoga
    while(1){// run for infinite loop
        cout<<temp.val<<" ";
        if(temp.next== NULL) break;
        temp = *(temp.next);
    }

}