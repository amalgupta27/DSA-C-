#include<bits/stdc++.h>
using namespace std;
/**
📝 ❓ QUESTION:
Check karo ki di gayi singly linked list **palindrome** hai ya nahi.
Palindrome = Aisa sequence jo ulta karne pe bhi same dikhe.

Example:
Input:  1 -> 2 -> 2 -> 1
Output: true ✅

Input:  1 -> 2 -> 3
Output: false ❌

------------------------------------------------------
💡 💭 LOGIC (Hinglish mein):

1️⃣ Slow and fast pointer ka use karke **middle** tak pahuchte hain.
   (Slow ek step le raha, Fast 2 steps — jab fast end pe hoga, slow middle pe hoga)

2️⃣ Slow ke baad ke part ko **reverse** karte hain.
   e.g. 1->2->3->2->1  => middle = 3, reverse part = 1->2

3️⃣ First half (head se middle tak) aur second half (reversed) ko compare karte hain.

4️⃣ Agar saare values match karein => Palindrome ✅
   Nahi match karein => Not Palindrome ❌

------------------------------------------------------
📊 Dry Run Example:

Original List:       1 -> 2 -> 3 -> 2 -> 1

Step 1: Slow at 3 (middle)
Step 2: Reverse list from slow->next => 1 -> 2
Step 3: Compare: 1 == 1 ✔️, 2 == 2 ✔️, 3 skip, done => Palindrome ✅

------------------------------------------------------
🧠 FLOW CHART (ASCII Art in Hinglish):

[Start]
   |
   v
Use slow-fast pointer to reach middle
   |
Reverse second half of list (slow->next)
   |
Compare head se lekar middle tak & reversed half
   |
   |--- If mismatch --> return false ❌
   |
   |--- If all match --> return true ✅

------------------------------------------------------
⏱️ TIME COMPLEXITY:

- Finding Middle:     O(n)
- Reversing Half:     O(n/2) ~ O(n)
- Comparing Halves:   O(n/2) ~ O(n)

👉 Total Time:         O(n)
👉 Space:              O(1) (in-place reverse)

------------------------------------------------------
👇👇 FINAL CODE with Detailed Comments 👇👇
**/

// 🔁 Helper function to reverse a linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // Default Constructor
    ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value + next
};
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* NEXT = NULL;

    while (curr != NULL) {
        NEXT = curr->next;      // 🔃 Next node ko store karlo
        curr->next = prev;      // 🔄 current ka pointer ulta karo
        prev = curr;            // ⏩ prev ko aage badhao
        curr = NEXT;            // ⏩ curr ko aage badhao
    }

    return prev;  // 📌 New head of reversed list
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 🔍 Step 1: Use slow & fast pointers to reach middle
        ListNode* slow = head;
        ListNode* fast = head;

        // 🐢 slow ek ek step, 🐇 fast do do step
        // Jab fast end ya end ke just pehle pahuchta, slow is at middle (left-middle for even)
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 🛠️ Step 2: Reverse second half of the list from slow->next
        // e.g. if list is 1->2->3->2->1, then slow is at 3, reverse(2->1)
        ListNode* newHead = reverseList(slow->next);

        // 👀 Step 3: Compare first half (head) with second half (reversed)
        ListNode* a = head;        // start of original
        ListNode* b = newHead;     // start of reversed second half

        while (b != NULL) {  // Second half might be shorter
            if (a->val != b->val)  // mismatch found
                return false;
            a = a->next;
            b = b->next;
        }

        // ✅ All matched, it's a palindrome
        return true;
    }
};
