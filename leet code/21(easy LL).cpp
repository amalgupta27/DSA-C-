#include<bits/stdc++.h>
using namespace std;
/**
--------------------------------------------------------
🔵 PROBLEM LOGIC (Simple Hinglish mein):

🔹 Tumhe do **sorted linked lists** di gayi hain:
    - List A: jaise 1 -> 3 -> 5
    - List B: jaise 2 -> 4 -> 6

🔹 Tumhe ek **nayi sorted linked list** banani hai:
    - 1 -> 2 -> 3 -> 4 -> 5 -> 6

🔹 Rules:
    - Dono list ko merge karna hai.
    - Nayi list bhi sorted hi rehni chahiye.
    - Do pointer (`tempA` and `tempB`) use karke dono list ko compare karenge.
    - Jo chhota element hoga use nayi list mein daal denge.

--------------------------------------------------------
🔵 FLOWCHART (ASCII Hinglish mein):

[Start]
   |
   v
[Initialize dummy node 'c' and temp pointers]
   |
   v
[While both tempA != NULL && tempB != NULL]
   |
   +--(If tempA->val <= tempB->val)
   |       |
   |       v
   |   [Insert tempA->val in new list]
   |   [Move tempA ahead]
   |
   +--(Else)
           |
           v
       [Insert tempB->val in new list]
       [Move tempB ahead]
   |
   v
[If tempA NULL, link tempB]
[Else link tempA]
   |
   v
[Return merged list from c->next]
   |
   v
[End]
--------------------------------------------------------
🔵 DRY RUN Example:

List A: 1 -> 3 -> 5  
List B: 2 -> 4 -> 6

Step 1: Compare 1 and 2 → 1 is smaller → Add 1
Step 2: Compare 3 and 2 → 2 is smaller → Add 2
Step 3: Compare 3 and 4 → 3 is smaller → Add 3
Step 4: Compare 5 and 4 → 4 is smaller → Add 4
Step 5: Compare 5 and 6 → 5 is smaller → Add 5
Step 6: tempA is NULL, attach remaining tempB (6)

Final List: 1 -> 2 -> 3 -> 4 -> 5 -> 6

--------------------------------------------------------
*/

// 🔵 STRUCTURE DEFINITION (Already given)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // default constructor
    ListNode(int x) : val(x), next(nullptr) {} // value constructor
    ListNode(int x, ListNode *next) : val(x), next(next) {} // value + pointer constructor
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        // 🔹 Step 1: Create pointers for traversal
        ListNode* tempA = a;
        ListNode* tempB = b;
        
        // 🔹 Step 2: Create a dummy node to start the new list
        ListNode* c = new ListNode(100); // 100 is random value, not important
        ListNode* tempC = c; // Pointer to build new list
        
        // 🔹 Step 3: Traverse both lists
        while (tempA != NULL && tempB != NULL) {
            if (tempA->val <= tempB->val) {
                // tempA ka value chhota ya barabar hai tempB se
                ListNode* t = new ListNode(tempA->val); // naye node mein tempA ka value
                tempC->next = t; // naye node ko jod do
                tempC = t; // tempC ko aage move karo
                tempA = tempA->next; // tempA ko aage move karo
            } else {
                // tempB ka value chhota hai
                ListNode* t = new ListNode(tempB->val); // naye node mein tempB ka value
                tempC->next = t; // naye node ko jod do
                tempC = t; // tempC ko aage move karo
                tempB = tempB->next; // tempB ko aage move karo
            }
        }
        
        // 🔹 Step 4: Ab ek list khatam ho gayi hogi
        // Agar tempA NULL ho gaya
        if (tempA == NULL) {
            tempC->next = tempB; // bache hue tempB ke nodes ko chipka do
        }
        else { 
            // tempB NULL ho gaya
            tempC->next = tempA; // bache hue tempA ke nodes ko chipka do
        }
        
        // 🔹 Step 5: Return final list, c->next (because c ke first node mein random 100 tha)
        return c->next;
    }
};

/*
--------------------------------------------------------
🔵 EXTRA EXPLANATION:

✅ Dummy node ka fayda:
    - Hamesha ek extra node bana ke kaam karte hai, taaki hume starting node ka address yaad rahe.
    - Last mein hum c->next return karte hai jisme actual merged list ka start hota hai.

✅ Agar kisi list ka end aa gaya (NULL ho gaya):
    - Direct doosri list ko connect kar dete hain kyunki dono already sorted thi.

--------------------------------------------------------
*/
