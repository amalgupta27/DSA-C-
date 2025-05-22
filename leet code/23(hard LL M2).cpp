#include<bits/stdc++.h>
using namespace std;
/*
----------------------------------------------------------------------
🔵 PROBLEM:
Merge k sorted linked lists into a single sorted linked list.
----------------------------------------------------------------------
🔵 STRATEGY (Hinglish):
1. Jab tak lists mein 1 se zyada elements hain:
    a. Front se do list uthao (lists[0] and lists[1])
    b. Unko merge karo ek sorted list mein
    c. Purane dono lists hata do
    d. Naya merged list ko wapas push_back karo

2. Jab sirf ek list bachegi, wohi final answer hai.
----------------------------------------------------------------------
🔵 FLOWCHART (Hinglish - ASCII):

[Start]
   |
   v
[If lists.size == 0] --> [Return NULL]
   |
   v
[While (lists.size > 1)]
   |
   +--[Pick lists[0] and lists[1]]
   |
   +--[Erase lists[0] and lists[1] from front]
   |
   +--[Merge a and b into c]
   |
   +--[Push merged list c into back of lists]
   |
   v
[End of While]
   |
   v
[Return lists[0]]
   |
   v
[End]
----------------------------------------------------------------------
*/

// 🔵 DEFINITION OF LISTNODE
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // Default Constructor
    ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value + next pointer
};

// 🔵 FUNCTION TO MERGE TWO SORTED LINKED LISTS
ListNode* merge(ListNode* a, ListNode* b) {
    // Create a dummy node to simplify edge cases
    ListNode* dummy = new ListNode(100); // Dummy node (any value)
    ListNode* temp = dummy;
    
    // Merge logic (like merge part of Merge Sort)
    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            temp->next = a; // a chhota hai
            a = a->next;    // a aage badhao
        } else {
            temp->next = b; // b chhota hai
            b = b->next;    // b aage badhao
        }
        temp = temp->next; // temp ko bhi aage badhao
    }
    
    // If one list ends, attach remaining other list
    if (a != NULL) {
        temp->next = a;
    } else {
        temp->next = b;
    }
    
    // Return the merged list, skipping the dummy node
    return dummy->next;
}

// 🔵 SOLUTION CLASS
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Base case: Agar vector empty hai
        if (lists.size() == 0) return NULL;
        
        // Jab tak vector mein more than 1 list hai
        while (lists.size() > 1) {
            // Step 1: Pick first two lists
            ListNode* a = lists[0];
            lists.erase(lists.begin()); // Remove first list
            ListNode* b = lists[0]; // again from0 because ek baar pahala nikal gya toh ye ab pahala ho gya hai
            lists.erase(lists.begin()); // Remove second list
            
            // Step 2: Merge them
            ListNode* mergedList = merge(a, b);
            
            // Step 3: Push merged list to end of vector
            lists.push_back(mergedList);
        }
        
        // Final merged list at index 0
        return lists[0];
    }
};

/*
----------------------------------------------------------------------
🔵 IMPORTANT POINTS:

✅ Dummy Node:
    - Simplifies merge logic without worrying about empty head.

✅ Vector.erase(lists.begin()):
    - Erase first element (like pop_front in queue).

✅ Time Complexity:
    - O(N*K) where N = total nodes, K = number of lists.

✅ Space Complexity:
    - O(1) (extra) except final merged list.

✅ Tip:
    - Isse aur optimize karne ke liye Min-Heap method hota hai
      (Priority Queue) ➔ O(N log K) mein kar sakte hain.
----------------------------------------------------------------------
*/
