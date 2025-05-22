#include<bits/stdc++.h>
using namespace std;
/**
✅ Question: Remove Nth Node From End of Linked List [Leetcode - 19] (Method 2)

🔵 Simple Hinglish Explanation:
- Tumhare paas ek linked list hai.
- Tumhe **end se nth node** ko hataana hai.
- Is baar hum **Two Pointer Technique** use karenge (fast and slow pointer).

🔵 Approach (Two Pointer Method):
1. Pehle fast pointer ko (n+1) steps aage bhej do.
   (taaki jab fast end pe ho, slow exactly delete hone wale node ke pehle ho)
2. Fir slow aur fast dono ko ek-ek step aage badhaate raho jab tak fast NULL na ho jaaye.
3. Jab fast NULL pahunch jaaye, slow->next waala node delete kar dena hai.
4. return head.

✅ Special Case:
- Agar fast pehle hi NULL ho jaaye during (n+1) steps ka travel ➔ iska matlab head ko hataana hai.
  (Isliye return head->next)

✅ Real Example:
    List = 1 → 2 → 3 → 4 → 5
    n = 2

    Step 1: Move fast pointer (n+1=3) steps ahead:
       fast at 4

    Step 2: Now move slow and fast together:
       slow at 2, fast at 5
       slow at 3, fast at NULL

    Step 3: slow is at node 3
    Step 4: delete slow->next (which is 4)

    Final list = 1 → 2 → 3 → 5

🔵 Flowchart (Hinglish mein):
    Start
      ↓
    Move fast n+1 steps
      ↓
    if (fast == NULL before move)
        delete head
        return head->next
      ↓
    Move slow and fast together till fast reaches NULL
      ↓
    slow->next = slow->next->next
      ↓
    return head
      ↓
    End

🖼️ Simple Diagram:

Before:
    [1] → [2] → [3] → [4] → [5] → NULL
                     ↑
                  Slow Pointer

After:
    [1] → [2] → [3] → [5] → NULL

✅ Node 4 deleted successfully!

----------------------------------------------------------
**/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        // ✅ Two Pointer Method (Fast and Slow)
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Step 1: Move fast (n+1) steps ahead
        for (int i = 1; i <= n + 1; i++) {
            if (fast == NULL) {
                // Special case: Delete head node
                return head->next;
            }
            fast = fast->next;
        }
        
        // Step 2: Move both slow and fast together
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Now slow is exactly before the node to be deleted
        slow->next = slow->next->next;
        
        return head;

        /*
        ✅ Example Walkthrough:

        Input:
            List = 1 → 2 → 3 → 4 → 5
            n = 2

        Step 1:
            Move fast 3 steps:
                - fast = 1 → 2 → 3 → 4

        Step 2:
            Move slow and fast:
                - slow at 2, fast at 5
                - slow at 3, fast at NULL

        Step 3:
            slow is at 3
            slow->next (4) is deleted

        Output:
            1 → 2 → 3 → 5
        */
    }
};
