/**
✅ Question: Delete Node in a Linked List [Leetcode - 237]

🔵 Logic in simple Hinglish:
- Tumhare paas ek linked list ka ek node ka pointer diya hai, jisko delete karna hai.
- Tumhare paas pura head nahi hai, sirf delete karne wale node ka pointer hai.
- Isliye hum pichle node se link nahi tod sakte.
- To hum kya karte hain:
    1. Current node ka value badal dete hain (next node ke value se).
    2. Phir current node ka next pointer aage ke next node pe kar dete hain.
- Isse next node delete ho jata hai, aur list me koi dikkat nahi hoti.

🔵 Real Life Example:
    Linked List: 
        10 -> 20 -> 30 -> 40 -> 50 -> NULL

    Suppose target node = 30

    Step 1:
        - Copy next node (40) ka value in 30
        - Now list becomes:
          10 -> 20 -> 40 -> 40 -> 50 -> NULL

    Step 2:
        - Delete 2nd 40 (next node)
        - Now final list:
          10 -> 20 -> 40 -> 50 -> NULL

✅ ✅ Tumne effectively 30 delete kar diya! 😎

🔵 Flowchart (Hinglish mein):
    Start
      ↓
    tar->val = tar->next->val
      ↓
    tar->next = tar->next->next
      ↓
    End

🖼️ Flow Diagram (Reference Image):
(see below explanation as per the uploaded image)

    Initial:
    10 → 20 → 30 → 40 → 50 → NULL
              ↑
             tar (target)

    After copying next value:
    10 → 20 → 40 → 40 → 50 → NULL
              ↑
             tar

    After skipping next node:
    10 → 20 → 40 → 50 → NULL
              ↑
             tar

😎 Conclusion: Node delete ho gaya bina head ke help ke!

----------------------------------------------------------
**/

// Linked List Node structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Current node ka value update karo next node ke value se
        node->val = node->next->val; 

        // Step 2: Current node ka next update karo next ke next se
        node->next = node->next->next; 

        /*
        ✅ Example:

        Before:
        10 -> 20 -> 30 -> 40 -> 50

        deleteNode(30) call hua

        Step 1:
        - 30 ka value ban gaya 40
        - List ban gayi: 10 -> 20 -> 40 -> 40 -> 50

        Step 2:
        - 2nd 40 (original) node delete kar diya
        - Final List: 10 -> 20 -> 40 -> 50

        ✅ So effectively, 30 delete ho gaya!

        🖼️ Reference Flow Chart Image:
        [Image you uploaded is used here as diagram for better understanding!]
        */
    }
};
