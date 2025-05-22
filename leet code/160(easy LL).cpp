#include<bits/stdc++.h>
using namespace std;
/**
✅ Question: Find the intersection point of two linked lists. (Leetcode - 160)

🔵 Hinglish Simple Explanation:

- Tumhe 2 linked lists diye gaye hain: headA aur headB.
- Dono lists kahi pe intersect ho sakte hain ya nahi bhi.
- Tumhe wo **node return karni hai jahan dono lists intersect karte hain**.
- Agar intersection nahi hota toh NULL return karna hai.

🔵 Approach (Length Difference Method):

1. Pehle dono linked lists ki **length** find karo.
2. Jisme jyada length hai, usko difference ke hisaab se aage badha do.
   (Taaki dono pointers same distance pe ho intersection se.)
3. Fir dono pointers ko ek saath move karo jab tak wo equal na ho jaayein.
4. Jab tak wo node same nahi hoti, dono ko ek-ek step badhate raho.
5. Jab equal node mil jaaye (tempA == tempB), wahi intersection point hai!

✅ Real Example:
List A:    4 → 1 → 8 → 4 → 5
List B:    5 → 6 → 1 → 8 → 4 → 5

- Intersection node = 8

✅ Diagram:

       4 → 1
             ↘
               8 → 4 → 5
             ↗
       5 → 6 → 1

✅ Flow Chart (Hinglish mein):

    Start
      ↓
    Find length of list A
      ↓
    Find length of list B
      ↓
    Find length difference (diff)
      ↓
    Jo lambi list hai uske pointer ko diff steps aage le jao
      ↓
    Move both pointers together
      ↓
    Jab tak tempA != tempB
      ↓
    Jab mil jaaye, return tempA
      ↓
    If no intersection, return NULL
      ↓
    End

🧠 Important:
- Time Complexity ➔ O(N+M) (N = length of list A, M = length of list B)
- Space Complexity ➔ O(1)

---------------------------------------------------
**/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        // Step 1: Find length of list A
        int lenA = 0;
        while (tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }
        
        // Step 2: Find length of list B
        int lenB = 0;
        while (tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }
        
        // Step 3: Reset pointers
        tempA = headA;
        tempB = headB;
        
        // Step 4: Adjust starting point of longer list
        if (lenA > lenB) {
            int diff = lenA - lenB;
            for (int i = 1; i <= diff; i++) {
                tempA = tempA->next;
            }
        } else {
            int diff = lenB - lenA;
            for (int i = 1; i <= diff; i++) {
                tempB = tempB->next;
            }
        }
        
        // Step 5: Move both pointers together
        while (tempA != NULL && tempB != NULL) {
            if (tempA == tempB) {
                return tempA;  // Intersection point found
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        // Step 6: If no intersection
        return NULL;

        /*
        ✅ Example Dry Run:

        List A: 4 → 1 → 8 → 4 → 5
        List B: 5 → 6 → 1 → 8 → 4 → 5

        Step 1: Length A = 5, Length B = 6
        Step 2: Difference = 1
        Step 3: Move tempB one step ahead ➔ at node 6
        Step 4: Start moving tempA and tempB together
        Step 5: When tempA at 8 and tempB at 8 ➔ SAME node!

        Hence, return node 8 (intersection point).
        */
    }
};
