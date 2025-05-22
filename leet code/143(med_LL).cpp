#include<bits/stdc++.h>
using namespace std;
/**
 * ---------------------------- LOGIC EXPLANATION ----------------------------
 * Problem: Reorder a singly linked list from this:
 *   L0 -> L1 -> L2 -> ... -> Ln-1 -> Ln
 *   To this:
 *   L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
 *
 * Example:
 * Input: 1 -> 2 -> 3 -> 4 -> 5
 * Output: 1 -> 5 -> 2 -> 4 -> 3
 *
 * ---------------------------- FLOWCHART (Hinglish) ----------------------------
 * 
 * START
 *   |
 *   |---> Check agar list empty hai ya sirf ek node hai (direct return)
 *   |
 *   |---> Step 1: Middle dhoondo (slow & fast pointer se)
 *   |
 *   |---> Step 2: Middle ke baad waali list ko reverse karo
 *   |
 *   |---> Step 3: Dono halves ko alternate tarike se merge karo
 *   |
 *   ---> END (head ab reordered list ka start hoga)
 *
 * ---------------------------- TIME COMPLEXITY ----------------------------
 * Step 1: Find middle -> O(n)
 * Step 2: Reverse second half -> O(n/2) ~= O(n)
 * Step 3: Merge two lists -> O(n)
 * Total Time Complexity = O(n)
 * Space Complexity = O(1) (No extra space used apart from pointers)
 *
 * ---------------------------- NODE DIAGRAM EXPLANATION ----------------------------
 * Input List:
 *   head --> [1] --> [2] --> [3] --> [4] --> [5] --> NULL
 *
 * Step 1: Middle dhoondne ke baad:
 *   First Half: [1] --> [2] --> [3] --> NULL
 *   Second Half (original): [4] --> [5] --> NULL
 *
 * Step 2: Reverse second half:
 *   Reversed Second Half: [5] --> [4] --> NULL
 *
 * Step 3: Merge both halves alternately:
 *   Final Output:
 *   head --> [1] --> [5] --> [2] --> [4] --> [3] --> NULL
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Yeh function linked list ko reverse karta hai
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // base case: empty list ya sirf ek node
        }
        ListNode* newHead = reverseList(head->next); // Recursively reverse rest of list
        head->next->next = head; // agle node ka pointer current node pe laga do
        head->next = NULL; // current node ka pointer NULL kar do
        return newHead; // newHead hamesha last node ban jaayegi
    }

    void reorderList(ListNode* head) {
        // Step 1: Find middle of the list using slow and fast pointer
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow ab middle pe hai

        // Step 2: Reverse second half of the list
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL; // list ko 2 parts mein tod diya

        // Step 3: Merge two halves alternately
        ListNode* c = new ListNode(100); // dummy node banaya
        ListNode* tempC = c;
        ListNode* tempA = a;
        ListNode* tempB = b;

        while(tempA != NULL && tempB != NULL){
            tempC->next = tempA;   // a part ka node lagao
            tempA = tempA->next;
            tempC = tempC->next;

            tempC->next = tempB;   // b part ka node lagao
            tempB = tempB->next;
            tempC = tempC->next;
        }

        // Agar a part mein kuch bacha ho to usse bhi lagao
        tempC->next = tempA;

        head = c->next; // dummy ke next se hi original head set ho jaata hai
    }
};