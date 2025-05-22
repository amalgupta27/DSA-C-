#include<bits/stdc++.h>
using namespace std;
/**
✅ Question: Detect cycle in a linked list. (Leetcode - 141)

🔵 Hinglish Simple Explanation:

- Tumhe ek linked list di gayi hai.
- Check karna hai ki isme koi cycle (loop) ban raha hai ya nahi.
- Agar cycle milta hai to `true` return karo, warna `false`.

🔵 Approach (Floyd’s Cycle Detection Algorithm - Tortoise and Hare):

1. Do pointers le lo: **slow** aur **fast**. Dono ko head par rakho.
2. Slow pointer 1 step chalega, Fast pointer 2 steps chalega.
3. Agar kabhi slow aur fast ek dusre ko mil gaye => cycle hai (return true).
4. Agar fast NULL tak pahunch gaya ya fast->next NULL hua => cycle nahi hai (return false).

✅ Real Example:
List: `3 → 2 → 0 → -4`
               ↖         ↘
                  ← ← ← ← 

✅ Flow Chart (Hinglish mein):

    Start
      ↓
    slow = head, fast = head
      ↓
    Jab tak (fast != NULL && fast->next != NULL):
        - slow = slow->next
        - fast = fast->next->next
        - Agar slow == fast → cycle mil gaya → return true
      ↓
    Agar fast NULL ho gaya → No cycle → return false
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
    bool hasCycle(ListNode *head) {
        
        // Step 1: Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Step 2: Traverse the list
        
        // Jab tak fast pointer NULL nahi hota aur fast ka next bhi NULL nahi hota
        // (Agar fast ya fast->next NULL ho gaya to hum list ke end tak aa gaye, to cycle nahi hai)
        while (fast != NULL && fast->next != NULL) {
            
            // Slow moves one step
            slow = slow->next;
            
            // Fast moves two steps
            fast = fast->next->next;
            
            // If slow aur fast mil jaate hain, iska matlab cycle hai
            if (slow == fast) {
                return true;
            }
        }
        
        // Step 3: Agar fast NULL tak pahunch gaya to koi cycle nahi hai
        return false;

        /*
        ✅ Example Dry Run:

        List: 3 → 2 → 0 → -4 → (points back to 2)

        - slow = 3, fast = 3
        - slow = 2, fast = 0
        - slow = 0, fast = 2
        - slow = -4, fast = -4 (slow == fast)

        Hence, cycle detected → return true
        */
    }
};
