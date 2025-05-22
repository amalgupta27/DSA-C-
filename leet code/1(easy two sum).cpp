#include<bits/stdc++.h>
using namespace std;
/**
 * Problem: Two Sum
 * ----------------
 * Tumhe ek array of integers diya gaya hai: nums[]
 * Aur ek number diya gaya hai: target
 * Tumhe aise 2 numbers ke indices return karne hain jinhe add karne pe target mile.
 * 
 * Example:
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1]  // kyunki nums[0]+nums[1] = 2+7 = 9
 * 
 * -------------------------------
 * Flow Chart (Hinglish Style)
 * -------------------------------
 * 1. Start
 * 2. Loop i from 0 to n-2
 * 3. Loop j from i+1 to n-1
 * 4. Check: nums[i] + nums[j] == target?
 *      Yes → return [i, j]
 *      No → Continue
 * 5. End of loops
 * 6. Return empty vector (if no match)
 * 7. End
 *
 * -------------------------------
 * Time Complexity:
 * -------------------------------
 * Worst Case: O(n^2)
 * - 2 nested loops: i & j
 * - Good for small inputs, not scalable for large arrays.
 * 
 * Space Complexity: O(1)
 * - No extra space used apart from result vector.
 */

 class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result; // Answer vector to store indices
    
            // Step 1: Traverse each pair of elements
            for (int i = 0; i < nums.size() - 1; i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    // Step 2: Check if their sum matches target
                    if (nums[i] + nums[j] == target) {
                        // If yes, return their indices
                        result.push_back(i); // index of first number
                        result.push_back(j); // index of second number
                        return result; // early return
                    }
                }
            }
    
            // Step 3: If no pair found, return empty vector
            return result;
        }
    };
    