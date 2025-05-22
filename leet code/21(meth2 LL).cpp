#include<bits/stdc++.h>
using namespace std;
/**
----------------------------------------------------------------------
🔵 PROBLEM LOGIC (Simple Hinglish mein):

🔹 Tumhe do **sorted linked lists** diye gaye hain:
    - List A: 1 -> 3 -> 5
    - List B: 2 -> 4 -> 6

🔹 Tumhe ek nayi sorted list banani hai,
   dono list ke saare elements ka sahi order mein combination.

🔹 Directly existing nodes ka use karenge,
   naye nodes banana nahi padega.

----------------------------------------------------------------------
🔵 FLOWCHART (ASCII Style):

[Start]
   |
   v
[Create Dummy Node 'c' -> temp points to c]
   |
   v
[While (a != NULL && b != NULL)]
   |
   +--(If a->val <= b->val)
   |        |
   |        v
   |   [temp->next = a] and move a, temp forward
   |
   +--(Else)
            |
            v
       [temp->next = b] and move b, temp forward
   |
   v
[If a NULL -> attach b]
[Else -> attach a]
   |
   v
[Return c->next]
   |
   v
[End]

----------------------------------------------------------------------
🔵 DRY RUN Example:

List A: 1 -> 3 -> 5
List B: 2 -> 4 -> 6

Step 1: Compare 1 and 2 → 1 smaller → temp->next = 1
Step 2: Compare 3 and 2 → 2 smaller → temp->next = 2
Step 3: Compare 3 and 4 → 3 smaller → temp->next = 3
Step 4: Compare 5 and 4 → 4 smaller → temp->next = 4
Step 5: Compare 5 and 6 → 5 smaller → temp->next = 5
Step 6: a is NULL, attach remaining b (6)

Result: 1 -> 2 -> 3 -> 4 -> 5 -> 6

----------------------------------------------------------------------
*/

// 🔵 STRUCTURE DEFINATION
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // Default Constructor
    ListNode(int x) : val(x), next(nullptr) {} // Value constructor
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Value + next pointer constructor
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
       
        // 🔹 Step 1: Dummy Node create karo (start point banane ke liye)
        ListNode* c = new ListNode(100); // 100 is random value
        ListNode* temp = c; // temp pointer move karte rahega
        
        // 🔹 Step 2: Jab tak dono list mein elements hain
        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                // Agar a ka value chhota ya barabar hai
                temp->next = a; // temp ke next mein a lagao
                a = a->next; // a ko aage badhao
                temp = temp->next; // temp ko bhi aage badhao
            } 
            else {
                // Agar b ka value chhota hai
                temp->next = b; // temp ke next mein b lagao
                b = b->next; // b ko aage badhao
                temp = temp->next; // temp ko bhi aage badhao
            }
        }
        
        // 🔹 Step 3: Ab koi ek list puri traverse ho chuki hogi
        if (a == NULL) {
            temp->next = b; // a khatam, to b ke remaining elements attach karo
        }
        else {
            temp->next = a; // b khatam, to a ke remaining elements attach karo
        }
        
        // 🔹 Step 4: Dummy node ka next return karo (because dummy mein random value hai)
        return c->next;
    }
};

/*
----------------------------------------------------------------------
🔵 EXTRA EXPLANATION:

✅ Dummy node ka fayda:
    - Naya list banana easy hota hai.
    - Starting ke pointer ko kabhi nahi khona padta.

✅ Difference from previous code:
    - Pehle hum naye nodes banate the (extra space).
    - Ab hum directly existing nodes ka use kar rahe hain (space efficient).
    
✅ Why return c->next?
    - c mein toh random 100 tha (dummy), actual list uske next se start hoti hai.

----------------------------------------------------------------------
*/
