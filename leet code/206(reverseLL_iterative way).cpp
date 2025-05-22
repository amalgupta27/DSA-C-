#include<bits/stdc++.h>
using namespace std;
/**
📝 Question:
Tumhe ek singly linked list di gayi hai. Tumhe is list ko reverse karna hai, yaani:
Example:
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1

🎯 Approach:
    - Har node ka pointer reverse karo ek loop mein
    - 3 pointers ka use hoga: prev, curr, NEXT

🔁 Flow Chart (Hinglish):
    [Start]
        |
    prev = NULL
    curr = head
    NEXT = NULL
        |
    [Jab tak curr != NULL]
        |
        |--> NEXT = curr->next       // next node store karo
        |--> curr->next = prev       // current ka next reverse karo
        |--> prev = curr             // prev aage badhao
        |--> curr = NEXT             // curr ko next node pe bhejo
        |
    [End pe prev return karo]
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
        ListNode* reverseList(ListNode* head) {
            // 🔁 3 pointers use karenge
            ListNode* prev = NULL;      // Pehle koi node nahi, so NULL
            ListNode* curr = head;      // current node jisse hum kaam karenge
            ListNode* NEXT = NULL;      // next node jisko aage traverse karna hai
    
            // Jab tak current node NULL nahi hoti, loop chalayenge
            while (curr != NULL) {
                NEXT = curr->next;      // Step 1: Next node store karo
                curr->next = prev;      // Step 2: current ka next ko reverse karo
                prev = curr;            // Step 3: prev ko aage badhao
                curr = NEXT;            // Step 4: curr ko next node pe le jao
            }
    
            // Jab sab nodes reverse ho gaye, prev ab head ban gaya hai
            return prev;
        }
    };
    