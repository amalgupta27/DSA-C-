#include<bits/stdc++.h>
using namespace std;
/**
 * Question: 
 * Linked list ko k parts me divide karna hai.
 * Har part ka size almost same hoga. (Max size difference 1 allowed)
 * Agar list chhoti hai to kuch parts NULL honge.
 * 
 * Example:
 * Input: 1->2->3->4->5->6->7->8->9, k=5
 * n = 9
 * Basic size = 9/5 = 1
 * Remainder = 9%5 = 4
 * 
 * Final Parts:
 * [1->2], [3->4], [5->6], [7->8], [9]
 * 
 * Flow Chart (Hinglish style):
 * --------------------------------------
 * 1. Start
 * 2. Find total nodes (n)
 * 3. size = n/k
 * 4. rem = n%k
 * 5. For each part:
 *      a. Create a dummy node
 *      b. Attach 'size' nodes
 *      c. If rem > 0, attach 1 extra node
 *      d. rem--
 *      e. Add part to answer
 * 6. If ans.size() < k
 *      Add NULL parts
 * 7. Return ans
 * 8. End
 * --------------------------------------
 * 
 * Time Complexity: O(n + k)
 * - n = number of nodes (for traversing list)
 * - k = number of parts (for splitting parts)
 * 
 * Space Complexity: O(k)
 * - Output array size = k
 */

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 class Solution {
    public:
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
            // Step 1: Find the length of the original linked list
            int n = 0;
            ListNode* temp = head;
            while (temp) {
                temp = temp->next;
                n++;
            }
    
            // Step 2: Calculate size of each part and remainder
            int size = n / k;   // minimum size of each part
            int rem = n % k;    // extra nodes to be distributed
            
            // Step 3: Start breaking the list
            vector<ListNode*> ans; // final answer
            
            temp = head;
            while (temp != NULL) {
                ListNode* dummy = new ListNode(0); // dummy node
                ListNode* current = dummy;         // pointer to create new part
                
                int currentSize = size;
                if (rem > 0) {
                    currentSize++; // add 1 extra node if remainder exists
                    rem--;
                }
                
                for (int i = 0; i < currentSize; i++) {
                    if (temp == NULL) break;
                    current->next = temp;  // link node
                    temp = temp->next;     // move temp ahead
                    current = current->next; // move current ahead
                }
                
                current->next = NULL; // important! end current part
                ans.push_back(dummy->next); // store part (skip dummy node)
            }
    
            // Step 4: If parts are less than k, add NULLs
            while (ans.size() < k) {
                ans.push_back(NULL);
            }
    
            // Step 5: Return final answer
            return ans;
        }
    };
    