#include<bits/stdc++.h>
using namespace std;
/**
✅ Question: Remove Nth Node From End of Linked List [Leetcode - 19]

🔵 Simple Hinglish Explanation:
- Tumhare paas ek linked list hai.
- Tumhe end se nth node hataani hai.

🔵 Approach:
1. Pura list traverse karke length (len) nikaalo.
2. Agar n == len, matlab head node hataani hai ➔ direct head = head->next kar do.
3. Nahi toh:
    - n-th from end = (len - n + 1)th from start.
    - Lekin delete karne ke liye usse ek pehle node pe rukna padega. (idx = m-1)
4. temp ko idx-1 tak le jaao aur fir temp->next = temp->next->next kar do.

✅ Real Example:
    List = 1 → 2 → 3 → 4 → 5
    n = 2

    Step 1: len = 5
    Step 2: m = len - n + 1 = 4
    Step 3: idx = m - 1 = 3
    Step 4: Traverse till idx-1 = 2nd node (node with value 3)
    Step 5: 3 ka next (4) ko hata ke 5 ko link kar do.

    Final list = 1 → 2 → 3 → 5

🔵 Flowchart (Hinglish mein):
    Start
      ↓
    Traverse list → find length
      ↓
    if (n == len)
        head = head->next
        return head
      ↓
    m = len - n + 1
    idx = m - 1
      ↓
    Traverse till idx-1 node
      ↓
    temp->next = temp->next->next
      ↓
    return head
      ↓
    End

🖼️ Simple Diagram:

Before:
    [1] → [2] → [3] → [4] → [5] → NULL
                             ↑
                            Target (4)

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
        // Step 1: Find the total length of the linked list
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        // Step 2: If we have to remove the first node (head node)
        if (n == len) {
            head = head->next;
            return head;
        }

        // Step 3: Find the (len - n)th node (previous node of target node)
        int m = len - n + 1;
        int idx = m - 1; // node to delete is at position m, so we stop at idx = m-1
        temp = head;

        // Move temp to (idx - 1)th node (1-based counting)
        for (int i = 1; i <= idx - 1; i++) {
            temp = temp->next;
        }

        // Step 4: Delete the node
        temp->next = temp->next->next;

        return head;

        /*
        ✅ Example Walkthrough:

        Input:
            List = 1 → 2 → 3 → 4 → 5
            n = 2

        Step 1: len = 5
        Step 2: m = len - n + 1 = 4
        Step 3: idx = m - 1 = 3

        Traverse till idx-1 = 2
            - temp points at node with value 3
            - temp->next (4) needs to be deleted
            - temp->next = temp->next->next (5)

        Final List:
            1 → 2 → 3 → 5
        */
    }
};
