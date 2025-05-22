#include<bits/stdc++.h>
using namespace std;
/**
📝 Question Summary:
Tumhe ek singly linked list aur ek value x di gayi hai.
Tumhe list ko aise todna hai ki:
  - Sabse pehle aise nodes aayein jinki value < x ho
  - Fir aise nodes jinki value >= x ho
  - Lekin sabka original order same rehna chahiye (stable order)

🔁 Flow:
    Input: 1 -> 4 -> 3 -> 2 -> 5 -> 2, x = 3
    Output: 1 -> 2 -> 2 -> 4 -> 3 -> 5

🎯 Solution Idea:
    1. Do alag-alag dummy nodes banao: lo & hi
    2. Har node ko uski value ke hisaab se lo ya hi list mein daalo
    3. Fir lo list ko hi list se jod do
    4. Return lo->next (dummy node ko hataake)
**/
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            // 🔹 Dummy nodes: lo and hi (initial value kuch bhi ho sakti hai, use nahi hoga)
            ListNode* lo = new ListNode(0);  // for nodes < x
            ListNode* hi = new ListNode(0);  // for nodes >= x
    
            // 🔹 Iterators (pointers) to build both lists
            ListNode* tempLo = lo;
            ListNode* tempHi = hi;
    
            // 🔹 Traverse original list
            ListNode* temp = head;
    
            while (temp != NULL) {
                if (temp->val < x) {
                    // Value chhoti hai → lo list mein daalo
                    tempLo->next = temp;      // lo list ke next mein daala
                    tempLo = tempLo->next;    // pointer aage badhaya
                } else {
                    // Value badi ya barabar hai → hi list mein daalo
                    tempHi->next = temp;      // hi list ke next mein daala
                    tempHi = tempHi->next;    // pointer aage badhaya
                }
                temp = temp->next;  // original list mein aage badho
            }
    
            // 🔹 Dono list ke end manage karo
            tempHi->next = NULL;           // hi list ke last node ke baad kuch nahi aana chahiye
            tempLo->next = hi->next;       // lo list ko jod diya hi list se
    
            // 🔹 Return answer (dummy node skip karke lo->next se start)
            return lo->next;
        }
    };
    