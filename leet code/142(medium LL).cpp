#include<bits/stdc++.h>
using namespace std;
/**
✅ Question: Detect the starting node of cycle in a Linked List. (Leetcode - 142)

🔵 Hinglish Simple Explanation:

- Tumhe ek linked list di gayi hai.
- Pehle check karna hai ki koi cycle exist karti hai ya nahi.
- Agar cycle hai, to cycle ka **starting point (node)** return karo.
- Agar cycle nahi hai, to `NULL` return karo.

🔵 Approach (Floyd’s Cycle Detection + Finding Start Point):

1. Do pointer lo: slow aur fast, dono ko head pe rakho.
2. Fast ko 2 steps aur slow ko 1 step move karte raho.
3. Agar slow aur fast mil jaate hain ➔ cycle exist karta hai.
4. Phir ek new pointer (`temp`) head pe rakho aur slow ko wahi chhod do.
5. Ab dono (slow aur temp) ko ek step ek step move karao.
6. Jaha pe dono milenge wahi cycle ka starting node hai.

✅ Real Example:
List: `3 → 2 → 0 → -4`
               ↖         ↘
                  ← ← ← ← 
Starting of cycle: Node with value `2`

🔵 Flow Chart (Hinglish mein):

    Start
      ↓
    slow = head, fast = head
      ↓
    Jab tak (fast != NULL && fast->next != NULL):
        - slow = slow->next
        - fast = fast->next->next
        - Agar slow == fast → Cycle mil gaya → break
      ↓
    Agar flag false → return NULL (  No cycle)
    warna:
        - temp = head
        - Jab tak (temp != slow):
            - temp = temp->next
            - slow = slow->next
        - Return temp (Starting point of cycle)
      ↓
    End

🧠 Important:
- Time Complexity ➔ O(N)
- Space Complexity ➔ O(1)

---------------------------------------------------
**/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        // Step 1: Initialize two pointers slow and fast at head
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false; // Initially assume no cycle

        // Step 2: Move slow by 1 step, fast by 2 steps
        while (fast != NULL && fast->next != NULL) {
            
            // Move slow 1 step ahead
            slow = slow->next;
            
            // Move fast 2 steps ahead
            fast = fast->next->next;
            
            // If slow and fast meet -> cycle detected
            if (slow == fast) {
                flag = true;
                break;
            }
        }

        // Step 3: If no cycle found, return NULL
        if (flag == false) return NULL;

        // Step 4: Cycle detected, now find the starting node of the cycle
        else {
            ListNode* temp = head;
            
            // Move both temp and slow one step at a time
            while (temp != slow) {
                temp = temp->next;
                slow = slow->next;
            }
            
            // Both meet at the starting point of the cycle
            return slow; // or return temp (both same)
        }
    }
};
