#include<bits/stdc++.h>
using namespace std;
/**
📝 ❓ Question:
Check karo ki di gayi singly linked list **palindrome** hai ya nahi.
Palindrome = Aisa sequence jo ulta karne par same dikhe.

Example:
Input:  1 -> 2 -> 2 -> 1
Output: true  ✅

Input:  1 -> 2 -> 3
Output: false ❌

------------------------------------------------------
💡 💭 LOGIC (Hinglish mein):

1️⃣ Sabse pehle original list ka **deep copy** banate hain.
2️⃣ Us copy ko **reverse** karte hain.
3️⃣ Original aur reversed copy ko node-by-node compare karte hain.
4️⃣ Agar saare values match karein => Palindrome ✅
    Nahi match karein => Not Palindrome ❌

------------------------------------------------------
📊 Dry Run Example:

Original List:       1 -> 2 -> 3 -> 2 -> 1
Copy & Reversed:     1 -> 2 -> 3 -> 2 -> 1

Step-by-step:
   Compare 1 == 1 ✔️
   Compare 2 == 2 ✔️
   Compare 3 == 3 ✔️
   Compare 2 == 2 ✔️
   Compare 1 == 1 ✔️
=> All matched, so it's a palindrome ✅

------------------------------------------------------
🧠 FLOW CHART (ASCII Art in Hinglish)

[Start]
   |
   v
Create dummy node 'c'
   |
Traverse 'head' and deep copy into 'c'
   |
Reverse list 'c' using reverseList()
   |
Compare each node of original and reversed list
   |
   |--- If mismatch found --> return false ❌
   |
   |--- If all match ---> return true ✅

------------------------------------------------------
⏱️ TIME COMPLEXITY:

- Copy Linked List: O(n)
- Reverse List:     O(n)
- Compare Both:     O(n)
Total Time:         O(n)
Space:              O(n) (because of deep copy)

------------------------------------------------------
👇👇 FINAL CODE with Detailed Comments 👇👇
**/

// Helper function to reverse a linked list (Iterative)
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
        NEXT = curr->next;       // Next node save karo
        curr->next = prev;       // Current node ka pointer ulta karo
        prev = curr;             // prev ko aage badhao
        curr = NEXT;             // curr ko aage badhao
    }

    return prev; // Ye hi ab new head hai (ulta list ka)
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // ✅ Step 1: Ek dummy node 'c' banate hain
        ListNode* c = new ListNode(10);  // dummy node (val random hai)
        
        // ✅ Step 2: Deep copy of 'head' banate hain
        ListNode* temp = head;
        ListNode* tempC = c;

        while (temp != NULL) {
            ListNode* node = new ListNode(temp->val); // naye node banaye, same value
            tempC->next = node;  // link add kiya
            temp = temp->next;   // original list mein aage badhe
            tempC = tempC->next; // copied list mein bhi aage badhe
        }

        // ✅ Step 3: Copied list ko reverse karo
        c = c->next;             // dummy node skip karke actual head pe aaye
        c = reverseList(c);      // copied list ko reverse kiya

        // ✅ Step 4: Dono list compare karo (original & reversed)
        ListNode* a = head;      // original list ka pointer
        ListNode* b = c;         // reversed copy ka pointer

        while (a != NULL) {
            if (a->val != b->val) {
                return false;   // agar koi value match nahi ki, toh not palindrome
            }
            a = a->next;
            b = b->next;
        }

        // ✅ All matched => It's a Palindrome
        return true;
    }
};
