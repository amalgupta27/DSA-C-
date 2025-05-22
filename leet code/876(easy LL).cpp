#include<bits/stdc++.h>
using namespace std;
/**
✅ Question: Find Middle Node of Linked List [Leetcode - 876]

🔵 Logic in simple Hinglish:
- Tumhare paas ek singly linked list hai.
- Tumhe uska middle node return karna hai.

🔵 Approach:
1. Pehle hum pura linked list traverse karke length nikalte hain. (len)
2. Fir length ka aadha (midIdx = len/2) nikalte hain.
3. Phir starting se midIdx tak jaakar middle node dhoond lete hain.

✅ Real Life Example:
    Linked List:
        1 → 2 → 3 → 4 → 5

    Step 1: Length (len) = 5
    Step 2: midIdx = 5/2 = 2 (0-based indexing)
    Step 3: Start from head, move 2 steps → node with value 3
    So, middle node = 3

✅ Another Example:
    Linked List:
        1 → 2 → 3 → 4 → 5 → 6

    Step 1: Length (len) = 6
    Step 2: midIdx = 6/2 = 3
    Step 3: Start from head, move 3 steps → node with value 4
    So, middle node = 4

🔵 Flowchart (Hinglish mein):
    Start
      ↓
    temp = head
      ↓
    Traverse list and count len++
      ↓
    midIdx = len/2
      ↓
    mid = head
      ↓
    Traverse midIdx times → mid = mid->next
      ↓
    Return mid
      ↓
    End

🖼️ Flow Diagram:

Step 1: Find Length
[1] → [2] → [3] → [4] → [5] → NULL
len = 5

Step 2: Find Middle Index
midIdx = len / 2 = 2

Step 3: Traverse till midIdx
Move 2 steps → Reach Node 3

✅ Middle Node Found!

----------------------------------------------------------
**/

// Linked List Node structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Step 1: Find the total length of the linked list
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;              // Har node pe length badhao
            temp = temp->next;   // Next node pe jao
        }

        // Step 2: Find the middle index
        int midIdx = len / 2;

        // Step 3: Traverse again to reach middle node
        ListNode* mid = head;
        for (int i = 1; i <= midIdx; i++) {
            mid = mid->next;   // midIdx steps move karo
        }

        // Step 4: Return middle node
        return mid;

        /*
        ✅ Example Walkthrough:

        Input Linked List:
            1 -> 2 -> 3 -> 4 -> 5

        Step 1:
            len = 5

        Step 2:
            midIdx = 5 / 2 = 2

        Step 3:
            Start at head:
                i=1: move to 2
                i=2: move to 3

        Step 4:
            Mid node = 3 ✅

        ✅ Itna simple and easy!
        */
    }
};
