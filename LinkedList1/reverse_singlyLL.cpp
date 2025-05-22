#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
💡 PROBLEM: Reverse a singly linked list

🛠️ GOAL:
Original:   1 → 2 → 3 → 4 → NULL
Reversed:   4 → 3 → 2 → 1 → NULL

🎯 HUMARA TARGET HAI:
Har node ka direction ulta karna bina koi extra list banaye.

📘 POINTERS KA USE:
- prev  : peechla node jisko current point karega (initially NULL)
- curr  : current node jisko hum reverse kar rahe hain
- NEXT  : current ke next node ko temporarily store karega (taaki link na toote)

---------------------------------------------------
🔄 FLOWCHART (Hinglish ASCII Style):
---------------------------------------------------

        +-------------------------+
        |  prev = NULL           |
        |  curr = head           |
        +-----------+-------------+
                    |
                    v
           +--------+--------+
           |  Jab tak curr != NULL  |
           +--------+--------+
                    |
                    v
         +----------+----------+
         | NEXT = curr->next   |   ← STEP 1
         +----------+----------+
                    |
                    v
         +----------+----------+
         | curr->next = prev   |   ← STEP 2 (reverse link)
         +----------+----------+
                    |
                    v
         +----------+----------+
         | prev = curr         |   ← STEP 3 (move prev forward)
         +----------+----------+
                    |
                    v
         +----------+----------+
         | curr = NEXT         |   ← STEP 4 (move curr forward)
         +----------+----------+
                    |
                    v
           Repeat until curr == NULL
                    |
                    v
              Return prev (new head)

---------------------------------------------------

🧪 DRY RUN (Example):

➡️ INPUT:  head → 1 → 2 → 3 → NULL

🔁 Iteration 1:
  curr = 1
  NEXT = 2
  curr->next = NULL (prev)
  prev = 1
  curr = 2

🔁 Iteration 2:
  curr = 2
  NEXT = 3
  curr->next = 1
  prev = 2
  curr = 3

🔁 Iteration 3:
  curr = 3
  NEXT = NULL
  curr->next = 2
  prev = 3
  curr = NULL (loop ends)

➡️ OUTPUT:  3 → 2 → 1 → NULL

---------------------------------------------------
🕰️ TIME COMPLEXITY: O(n)
   (Har node sirf ek baar touch ho rahi hai)

🧠 SPACE COMPLEXITY: O(1)
   (Koi extra array/list use nahi ki gayi — bas 3 pointers)
*/
class Node { 
public:
    int val;       // Node ke andar ek value hogi
    Node* next;    // aur ek pointer hoga jo next node ko point karega

    // Constructor - jab naya node banega tab value set karega aur next NULL hoga
    Node(int val) {
        this->val = val;   // 'this' ka use kiya kyunki parameter aur member ka naam same hai
        this->next = NULL; // initially koi next node nahi hai, isliye NULL
    }
};

class Solution {
public:
    Node* reverseList(Node* head) {
        // Step 0: Initialize the pointers
        Node* prev = NULL;     // prev initially NULL hoga
        Node* curr = head;     // curr head ko point karega
        Node* NEXT = NULL;     // NEXT temporary node pointer

        // Step 1 to 4: Loop until curr becomes NULL
        while (curr != NULL) {
            // STEP 1: NEXT node ko store karo (taaki link na toote)
            NEXT = curr->next;

            // STEP 2: curr ka next ab prev pe point kare (reverse link)
            curr->next = prev;

            // STEP 3: prev ko curr bana do (aage badho)
            prev = curr;

            // STEP 4: curr ko NEXT bana do (aage badho)
            curr = NEXT;
        }

        // Jab loop khatam ho jaye, prev naya head hoga
        return prev;
    }
};
