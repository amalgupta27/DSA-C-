#include<bits/stdc++.h>
using namespace std;
/**
🟦 Logic (Hinglish):
Ye code ek singly linked list ko sort karta hai using Merge Sort.
- Merge sort recursion + merging sorted parts ka use karta hai.
- Time Complexity = O(n log n)
- Space Complexity = O(log n) due to recursion

🟩 Flow:
Step 1: List ko 2 halves mein divide karo
Step 2: Recursively sort karo dono halves ko
Step 3: Dono sorted halves ko merge karo using helper function

🟨 Example:
Input: 4 -> 2 -> 1 -> 3
-> Divide: (4,2) and (1,3)
-> Sort: 2->4 and 1->3
-> Merge: 1->2->3->4
**/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 🔄 Helper function to merge two sorted linked lists
ListNode* merge(ListNode* a, ListNode* b) {
    ListNode* dummy = new ListNode(0); // Starting node (dummy node)
    ListNode* temp = dummy;

    // Jab tak dono lists empty nahi ho jaati
    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            temp->next = a;  // Smaller value ko link karo
            a = a->next;
        } else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;  // Move temp forward
    }

    // Agar a list khatam ho gayi, b list bachi ho
    if (a == NULL) temp->next = b;
    // Agar b list khatam ho gayi, a list bachi ho
    else temp->next = a;

    return dummy->next; // dummy node ke baad se actual result
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: empty list ya single element list
        if (head == NULL || head->next == NULL) return head;

        // 🟠 Slow-Fast technique to find middle (left middle for even)
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {// left middle nikalne ke liye aisa kiye hain
            //fast->next!=NULL odd ke liye aur fast->next->next!=NULL even ke liye  
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split list into two halves
        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = NULL; // Break the list in 2 parts

        // 🔁 Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // 🔁 Merge sorted halves
        return merge(left, right);
    }
};
