#include<bits/stdc++.h>
using namespace std;
/**
✅ Question: Find Middle Node of Linked List using Two Pointer Approach [Leetcode - 876]

🔵 Logic in Simple Hinglish:
- Tumhare paas ek singly linked list hai.
- Tumhe middle node find karna hai.
- Lekin iss baar length calculate nahi karni!
- Hum 2 pointer ka use karenge: ek slow aur ek fast.

🔵 Approach:
1. Dono pointers slow aur fast ko head pe rakho.
2. Jab tak fast aur fast->next NULL nahi hote:
   - slow ko 1 step aage badhao (slow = slow->next)
   - fast ko 2 step aage badhao (fast = fast->next->next)
3. Jab fast end pe pahunchta hai ya uske aage kuch nahi hota:
   - slow middle node pe hota hai.
4. slow ko return kar do.

✅ Real Life Example:
    Linked List:
        1 → 2 → 3 → 4 → 5

    Starting:
        slow = 1
        fast = 1

    Step 1:
        slow = 2 (1 step)
        fast = 3 (2 steps)

    Step 2:
        slow = 3 (1 step)
        fast = 5 (2 steps)

    Step 3:
        fast ka next NULL hai → stop

    Output:
        slow is at 3 → Middle Node = 3 ✅

✅ Another Example:
    Linked List:
        1 → 2 → 3 → 4 → 5 → 6

    Starting:
        slow = 1
        fast = 1

    Step 1:
        slow = 2
        fast = 3

    Step 2:
        slow = 3
        fast = 5

    Step 3:
        slow = 4
        fast = NULL → stop

    Output:
        slow is at 4 → Middle Node = 4 ✅

🔵 Flowchart (Hinglish mein):
    Start
      ↓
    slow = head
    fast = head
      ↓
    while(fast != NULL && fast->next != NULL)
        slow = slow->next
        fast = fast->next->next
      ↓
    Return slow
      ↓
    End

🖼️ Flow Diagram Visualization:

    [1] → [2] → [3] → [4] → [5] → NULL
     ↑      ↑
   slow   fast

    (after 1st move)
    [1] → [2] → [3] → [4] → [5] → NULL
              ↑      ↑
            slow    fast

    (after 2nd move)
    [1] → [2] → [3] → [4] → [5] → NULL
                      ↑
                    slow

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
        // Step 1: Initialize two pointers slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 2: Move slow by 1 step and fast by 2 steps
        while (fast != NULL && fast->next != NULL) { //fast!=NULL even ke liye aur fast->next!=NULL odd ke liye hai
            slow = slow->next;          // slow moves 1 step
            fast = fast->next->next;    // fast moves 2 steps
        }

        // Step 3: When fast reaches end, slow will be at middle
        return slow;

        /*
        ✅ Example Walkthrough:

        Input Linked List:
            1 -> 2 -> 3 -> 4 -> 5

        Initialization:
            slow = 1
            fast = 1

        1st Iteration:
            slow = 2
            fast = 3

        2nd Iteration:
            slow = 3
            fast = 5

        3rd Iteration:
            fast->next == NULL → loop ends

        Output:
            slow is at 3 → Middle node is 3 ✅

        ✅ Super efficient method — O(n/2) time, O(1) space!
        */
    }
};
