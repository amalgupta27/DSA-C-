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
🔵 LOGIC + FLOW (Hinglish + Diagram idea):

🔹 Problem:
- Hume linked list ko `k` steps right rotate karna hai.
- Example: List = [1,2,3,4,5], k = 2
  After rotation → [4,5,1,2,3]

🔹 High Level Approach:
1. List ki total length (n) find karo.
2. k ko n se modulo karo (k = k % n), kyunki full rotation ka koi matlab nahi.
3. n-k steps aage jao, wahan se list ko tod do aur aage ka part ko head bana do.

🔹 Visual Example:
Input: 1 -> 2 -> 3 -> 4 -> 5, k = 2

Length n = 5

k = 2 % 5 = 2

n-k = 3

Jaise hi 3rd node (value 3) pe pahunchte hain:
- temp = 3
- temp->next = 4 ko nayi head banana hai
- 3 ka next NULL kar dena hai
- purani tail 5 ko 1 se connect karna hai

Result:
4 -> 5 -> 1 -> 2 -> 3

🔹 Flowchart (ASCII Hinglish):

Start
  |
  v
[Check head NULL or single node]
  |
  v
[Length n find karo aur tail identify karo]
  |
  v
[k = k % n]
  |
  v
[Agar k == 0 -> return head]
  |
  v
[n-k steps move karo aur wahan tod do]
  |
  v
[tail->next = head se connect karo]
  |
  v
[naya head set karo]
  |
  v
[temp->next = NULL]
  |
  v
[Return new head]

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
        ListNode* rotateRight(ListNode* head, int k) {
            // 🔸 Agar list empty hai ya sirf ek node hai, toh rotation ka koi matlab nahi
            if(head == NULL || head->next == NULL) return head;
    
            int n = 0; // 🔹 List ka size nikalne ke liye
            ListNode* temp = head; // 🔹 Ek temp pointer banaya jo head pe set hai
            ListNode* tail = NULL; // 🔹 Tail node ko store karne ke liye
    
            // 🔹 List ko traverse karenge aur n aur tail dono nikalenge
            while(temp != NULL){
                if(temp->next == NULL) tail = temp; // agar temp->next NULL hai, toh woh last node hai
                temp = temp->next; // temp ko aage badhao
                n++; // ek node mila, isliye n++
            }
    
            // 🔸 k ko optimize karenge kyunki agar k > n ho toh pura ghoom chuke honge
            k = k % n;
    
            // 🔸 Agar k 0 ho gaya toh list waise ki waise rahegi
            if(k == 0) return head;
    
            // 🔹 Ab hume n-k steps chalna hai
            temp = head;
            for(int i = 1; i < n-k; i++){
                temp = temp->next; // temp ko ek-ek step aage badhao
            }
    
            // 🔹 Ab temp ke aage wala node (temp->next) naya head banega
            // 🔹 Tail node (jo last me hai) ka next ko head pe point kara denge to temporarily circular list banegi
            tail->next = head;
    
            // 🔹 Naya head banega temp->next
            head = temp->next;
    
            // 🔹 temp->next ko NULL set kar dena hoga kyunki yahi new list ka last node hoga
            temp->next = NULL;
    
            // 🔸 Finally naya head return karenge
            return head;
        }
    };
    