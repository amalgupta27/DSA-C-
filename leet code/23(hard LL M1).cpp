#include<bits/stdc++.h>
using namespace std;
/*
----------------------------------------------------------------------
🔵 PROBLEM LOGIC (Simple Hinglish mein):

🔹 Tumhare paas "k" sorted linked lists ka ek array diya gaya hai.
    (Har list already sorted hai individually.)

🔹 Tumhe ek hi final sorted linked list banani hai
   jo saare lists ke elements ko ek sahi tarike se merge kare.

🔹 Example:
    Input:  lists = [1->4->5, 1->3->4, 2->6]
    Output: 1->1->2->3->4->4->5->6

🔹 Strategy:
    - Do-do lists ko uthakar merge karte jao.
    - Har baar ek naya merged list banta jaayega.
    - Jab tak sirf ek list bache, process repeat karo.

----------------------------------------------------------------------
🔵 FLOWCHART (ASCII Style - Hinglish mein):

[Start]
   |
   v
[If lists.size == 0] --> [Return NULL]
   |
   v
[While (lists.size > 1)]
   |
   +--[Pick last two lists: a and b]
   |
   +--[Merge a and b into c]
   |
   +--[Remove a and b from array]
   |
   +--[Push merged list c back into array]
   |
   v
[End of While]
   |
   v
[Return lists[0] (final merged list)]
   |
   v
[End]

----------------------------------------------------------------------
🔵 DRY RUN Example:

Input: [1->4->5, 1->3->4, 2->6]

- Step 1:
    a = 2->6
    b = 1->3->4
    c = Merge(a, b) => 1->2->3->4->6

    Now lists = [1->4->5, 1->2->3->4->6]

- Step 2:
    a = 1->2->3->4->6
    b = 1->4->5
    c = Merge(a, b) => 1->1->2->3->4->4->5->6

    Now lists = [1->1->2->3->4->4->5->6]

Final answer: 1->1->2->3->4->4->5->6

----------------------------------------------------------------------
*/

// 🔵 STRUCTURE DEFINATION
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // Default Constructor
    ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value + next
};

// 🔵 FUNCTION TO MERGE TWO LISTS
ListNode* merge(ListNode* a, ListNode* b) {
       
    // Step 1: Create a dummy node
    ListNode* c = new ListNode(100); // Random value
    ListNode* temp = c; // Temp pointer to move and connect nodes
    
    // Step 2: Merge two lists like merge process in merge sort
    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            temp->next = a; // a chhota hai, use lagao
            a = a->next;    // a ko aage badhao
            temp = temp->next; // temp ko aage badhao
        }
        else {
            temp->next = b; // b chhota hai, use lagao
            b = b->next;    // b ko aage badhao
            temp = temp->next; // temp ko aage badhao
        }
    }
    
    // Step 3: Jo list bach gayi ho, seedha attach kar do
    if (a == NULL) {
        temp->next = b;
    }
    else {
        temp->next = a;
    }
    
    // Step 4: Return dummy ke next ko (skip dummy node itself)
    return c->next;
}

// 🔵 MAIN SOLUTION CLASS
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Base Case: Agar koi list hi nahi hai
        if (lists.size() == 0) return NULL;
        
        // Jab tak zyada than 1 list bachti hai
        while (lists.size() > 1) {
            
            // Step 1: Pick last two lists
            ListNode* a = lists[lists.size()-1];
            lists.pop_back(); // Remove last list
            ListNode* b = lists[lists.size()-1];
            lists.pop_back(); // Remove second last list
            
            // Step 2: Merge these two lists
            ListNode* c = merge(a, b);
            
            // Step 3: Push the merged list back into lists
            lists.push_back(c);
        }
        
        // Step 4: Finally one list bachi hogi
        return lists[0];
    }
};

/*
----------------------------------------------------------------------
🔵 EXTRA POINTS:

✅ Dummy Node:
    - New merged list banane mein starting point help karta hai.
    - Dummy se actual head ko easily access kar sakte hain.

✅ Time Complexity:
    - O(N*k), where N = total number of nodes, k = number of lists.

✅ Space Complexity:
    - O(1) (excluding output list)
    - Hum naye nodes nahi bana rahe, existing nodes ko point kar rahe hain.

✅ Improvement:
    - Hum Priority Queue (Min-Heap) ka use karke time complexity O(N log k) tak la sakte hain.
    - Abhi ka approach bhi bahut acha hai beginner ke liye!

----------------------------------------------------------------------
*/
