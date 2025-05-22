#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x, next(next) {}
 * };
 */

/*
🔵 PROBLEM EXPLANATION:

Hume ek linked list diya gaya hai aur ek matrix of size m x n.
Linked list ke elements ko spiral (gol gol) way mein matrix mein fill karna hai.

Example:

Input:
m = 3, n = 3
List: 3 -> 0 -> 2 -> 6 -> 8 -> 1 -> 7 -> 9 -> 4

Output:
[
 [3, 0, 2],
 [9, 4, 6],
 [7, 1, 8]
]

🌀 Fill karne ka order:
Right ➔ Down ➔ Left ➔ Up ➔ (repeat until complete)

---

🔵 FLOWCHART (ASCII Hinglish):

Start
 |
 v
[Matrix v[m][n] banaye aur -1 se bhar do]
 |
 v
[minr, minc, maxr, maxc set karo]
 |
 v
[Linked list traverse karte hue spiral order mein values fill karo]
 |
 v
[Agar temp == NULL (linked list khatam) ho gaya -> return v]
 |
 v
[Har direction ke baad boundaries update karo]
 |
 v
[Repeat until minr <= maxr and minc <= maxc]
 |
 v
Done ✅

---

🔵 Important Concepts:

- -1: Matrix mein default value. Matlab "yeh cell abhi tak khali hai".
- NULL: Jab linked list ka temp pointer NULL ho jaata hai, iska matlab list khatam ho gayi.

---

🔵 Special Explaination of (temp == NULL) return v:

Example:

Suppose,
m = 3, n = 4
Linked list = 1 -> 2 -> 3 -> 4 -> 5

Matrix size = 3x4 = 12 spaces available, lekin list ke paas sirf 5 nodes hain.

Filling order:

- Right fill:
  [1, 2, 3, 4]
- Down fill:
  [ , , , 5]

Ab linked list ka temp NULL ho gaya (koi next node nahi), isiliye `if(temp == NULL) return v;` hum call karte hain,
taaki matrix ka jitna fill hua, utna return kar dein. Baaki jagah par -1 hi reh jaayega.

Matrix:

[
 [1, 2, 3, 4],
 [-1, -1, -1, 5],
 [-1, -1, -1, -1]
]

---

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        // 🔹 Step 1: Initialize matrix with -1
        vector<vector<int>> v(m, vector<int>(n, -1));
        
        // 🔹 Step 2: Set initial boundaries
        int minr = 0;    // Minimum row
        int minc = 0;    // Minimum column
        int maxr = m-1;  // Maximum row
        int maxc = n-1;  // Maximum column
        
        // 🔹 Step 3: Start traversing from head of linked list
        ListNode* temp = head;
        
        // 🔹 Step 4: Spiral traversal
        while(minr <= maxr && minc <= maxc) {
            
            // 🔸 RIGHT move (left to right on top row)
            for(int j = minc; j <= maxc; j++) {
                if(temp == NULL) return v;
                /*
                📢 Explaination of this line:

                - Jab linked list khatam ho jaati hai (temp == NULL),
                  toh hum jitna matrix fill ho chuka hai, usko return karte hain.
                - Example ke liye agar list chhoti hai aur matrix bada,
                  toh extra matrix cells mein kuch nahi daalna (woh -1 hi rahenge).

                Real Life Example:
                Input: m=3, n=4
                Linked list: 1 -> 2 -> 3 -> 4 -> 5
                Matrix after temp==NULL:
                [
                  [1,2,3,4],
                  [-1,-1,-1,5],
                  [-1,-1,-1,-1]
                ]
                */
                v[minr][j] = temp->val;
                temp = temp->next; // Move to next node
            }
            minr++; // Top row fill ho gaya, ab next row se kaam karenge

            if(minr > maxr || minc > maxc) break;

            // 🔸 DOWN move (top to bottom on rightmost column)
            for(int i = minr; i <= maxr; i++) {
                if(temp == NULL) return v;
                v[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--; // Rightmost column fill ho gaya, ab ek column left se kaam karenge

            if(minr > maxr || minc > maxc) break;

            // 🔸 LEFT move (right to left on bottom row)
            for(int j = maxc; j >= minc; j--) {
                if(temp == NULL) return v;
                v[maxr][j] = temp->val;
                temp = temp->next;
            }
            maxr--; // Bottom row fill ho gaya, ab ek row upar se kaam karenge

            if(minr > maxr || minc > maxc) break;

            // 🔸 UP move (bottom to top on leftmost column)
            for(int i = maxr; i >= minr; i--) {
                if(temp == NULL) return v;
                v[i][minc] = temp->val;
                temp = temp->next;
            }
            minc++; // Leftmost column fill ho gaya, ab ek column right se kaam karenge

            if(minr > maxr || minc > maxc) break;
        }
        
        // 🔹 Finally fully filled ya partially filled matrix return
        return v;
    }
};
