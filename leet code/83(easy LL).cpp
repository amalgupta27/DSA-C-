#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
📚 LOGIC + FLOW (Hinglish me):

🔹 Problem: 
Hume **sorted linked list** me se **duplicate elements** hataane hain. Sirf ek ek element unique form me rehna chahiye.

🔹 Approach:
- Two pointer method use karenge: `a` aur `b`
- `a` ko current unique node ke paas rakhenge
- `b` ko agle node ke paas rakhenge
- Jab tak `a->val == b->val`, tab tak `b` ko aage badhate rahenge (duplicates ko skip karte rahenge)
- Jab `b` naye element pe aayega (different value), to `a->next = b` karenge (link banana)
- Fir a aur b dono ko ek step aage badha denge
- Jab tak `b != NULL`, ye karte rahenge

🔹 Small Flowchart (ASCII - Hinglish)

START
  |
  v
[Check head NULL or 1 node? -> Return head]
  |
  v
[a = head, b = head->next]
  |
  v
[While b != NULL]
    |
    v
  [While b != NULL && a->val == b->val]
       |
       v
     [Move b ahead]
  |
  v
[a->next = b]
a = b
if(b != NULL) b = b->next
  |
  v
End Loop
|
v
Return head

✅ Example:
Input: 1 -> 1 -> 2 -> 3 -> 3
Working:
- 1 == 1 -> skip
- 1 != 2 -> link 1 -> 2
- 2 != 3 -> link 2 -> 3
- 3 == 3 -> skip
Final Output: 1 -> 2 -> 3

*/
struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            // Step 1: Check if list is empty (head == NULL) or only 1 node (head->next == NULL)
            if(head == NULL || head->next == NULL) return head; 
    
            // Step 2: Initialize two pointers
            ListNode* a = head;       // 'a' points to current unique node
            ListNode* b = head->next; // 'b' points to next node
    
            // Step 3: Traverse the list
            while(b != NULL){
                // Step 4: Skip all duplicate nodes
                while(b != NULL && b->val == a->val){
                    b = b->next; // move b ahead until we find a different value
                }
    
                // Step 5: Connect 'a' to the next unique node
                a->next = b;
    
                // Step 6: Move 'a' to 'b' (current new node)
                a = b;
    
                // Step 7: Move 'b' one step ahead if b exists
                if(b != NULL) b = b->next;
            }
    
            // Step 8: Return the updated head of the linked list
            return head;
        }
    };
    