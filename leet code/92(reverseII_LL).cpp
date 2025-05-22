#include<bits/stdc++.h>
using namespace std;
/**
 * Problem: Given a singly linked list, reverse the nodes of a sublist between positions left and right.

 * 🔁 Time Complexity: O(n)
 * 💾 Space Complexity: O(1) [In-place reverse]

 * Example:
 * Input:  1 -> 2 -> 3 -> 4 -> 5,  left = 2, right = 4
 * Output: 1 -> 4 -> 3 -> 2 -> 5
 */

// ✅ Helper function to reverse a linked list
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
        NEXT = curr->next;      // 🔃 Next node store kar liya
        curr->next = prev;      // 🔄 Reverse current node ka pointer
        prev = curr;            // ⏩ Prev ko aage le gaye
        curr = NEXT;            // ⏩ Curr ko bhi aage le gaye
    }

    return prev;  // 📌 Yeh hai new head of reversed list
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // 🔁 Edge case: left == right => kuch reverse karna hi nahi
        if (left == right) return head;

        // 🔎 Humko 4 pointers chahiye:
        ListNode* a = NULL;  // Left se pehle ka node
        ListNode* b = NULL;  // Left position node (start of reverse)
        ListNode* c = NULL;  // Right position node (end of reverse)
        ListNode* d = NULL;  // Right ke baad ka node

        // ⏩ Traverse list and find positions
        ListNode* temp = head;
        int n = 1;

        while (temp != NULL) {
            if (n == left - 1) a = temp;
            if (n == left) b = temp;
            if (n == right) c = temp;
            if (n == right + 1) d = temp;
            temp = temp->next;
            n++;
        }

        // 🚫 Disconnect the part that needs to be reversed
        if (a != NULL) a->next = NULL;
        c->next = NULL;

        // 🔄 Reverse b to c
        c = reverseList(b); //Ab reverse karne ke baad, jo new starting node hoga, 
                            //wo c banega (kyunki reverse hone ke baad right wala node left pe aa jaata hai).

        // 🔗 Reconnect
        if (a != NULL) a->next = c;  // Left se pehle node ko new head se jodo
        b->next = d;                 // Reversed part ke end ko d se jodo

        // 🧠 Head decide karo:
        if (a != NULL) return head;  // Agar a hai to head wahi rahega
        return c;                    // Agar a NULL hai (left == 1), to new head c hoga
    }
};
