#include<bits/stdc++.h>
using namespace std;
/**
📝 ❓ Question:
Ek singly linked list di gayi hai, tumhe usko reverse (ulta) karna hai using **Recursion**.

🎯 Example:
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1

------------------------------------------
💡 🔁 Recursive Approach Logic (Hinglish):

👉 Base Case:
Agar list khali hai (head == NULL) ya sirf ek node hai (head->next == NULL), to wahi head return kar do (ulta already hai).

👉 Recursive Step:
Har baar head ke baad wali list ko reverse karo, aur phir current head ko uske peeche laga do.

Jaise hi hum recursion se return aate hain, hum list ke nodes ke "next" pointers ko ulta karte hain.

Example dry run:
  Input: 1 -> 2 -> 3

  Call Stack:
     reverseList(1)
       ↳ reverseList(2)
           ↳ reverseList(3)
               ↳ returns 3 (base case)

  Now while returning:
    2->next->next = 2 (3->next = 2)
    2->next = NULL

    1->next->next = 1 (2->next = 1)
    1->next = NULL

  Output: 3 -> 2 -> 1

------------------------------------------
🧠 Flow Chart (in Hinglish):

[Start]
   |
   v
head == NULL or head->next == NULL ?
   | yes -> return head
   |
   no
   |
   v
newHead = reverseList(head->next)
   |
head->next->next = head
head->next = NULL
   |
   v
return newHead
------------------------------------------

🕒 Time Complexity:
- Time: O(n)  -> n is the number of nodes (each node visited once)
- Space: O(n) -> due to recursive call stack (depth of recursion = n)

**/

// ✅ Fully Commented Recursive Code Below:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            // 🧱 Base case: agar list empty hai ya ek hi node hai
            if (head == NULL || head->next == NULL) {
                return head;  // wahi head return kar do
            }
    
            // 🧠 Step 1: Recursively reverse the remaining list
            ListNode* newHead = reverseList(head->next); // rest of list reversed mil gaya
    
            // 🔄 Step 2: Current node ko uske baad wale node ke "next" mein set karo
            head->next->next = head; // example: 2->next = 1
            head->next = NULL;       // 1 ka link hata do, warna loop ban jaayega
    
            // ✅ Return new head (jo last node thi, ab woh head hai)
            return newHead;
        }
    };
    