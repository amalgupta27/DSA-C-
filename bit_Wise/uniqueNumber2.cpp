/*
--------------------------------------------
LOGIC OF THE QUESTION (HINGLISH MEIN SAMAJHIYE)
--------------------------------------------
Ek array diya gaya hai jismein har number 2 baar repeat hota hai,
bas sirf 2 numbers aise hain jo repeat nahi ho rahe.
Humein wahi do numbers find karne hain jo unique hain.

Example:
----------
Input: {4, 5, 6, 7, 4, 5}
Output: 6, 7

Logic:
---------
1. Saare numbers ko XOR karenge. Jo numbers repeat ho rahe hain wo cancel ho jaayenge,
   aur sirf wahi 2 unique numbers ka XOR bachega.

2. XOR ka result humein ek number dega jo dono unique numbers ka XOR hoga.
   Uska rightmost set bit find karenge.

3. Us bit ke basis pe saare numbers do groups mein divide karenge:
   - Jismein wo bit 1 hai.
   - Jismein wo bit 0 hai.

4. Har group ka alag-alag XOR karenge jo humein dono unique numbers dega.

--------------------------------------------
FLOWCHART (HINGLISH MEIN)
--------------------------------------------

1. START
2. Saare numbers ka XOR lo
3. XOR ka rightmost 1-bit find karo
4. Array ko 2 groups mein baanto
5. Har group ka XOR lo
6. Output do (Dono unique numbers)
7. END

--------------------------------------------
*/

#include <iostream>
using namespace std;

void findUniqueNumbers(int arr[], int n) {
    int xor_sum = 0;

    // Step 1: Saare numbers ka XOR lo, taaki duplicate numbers cancel ho jaayein
    for (int i = 0; i < n; i++) {
        xor_sum ^= arr[i];
    }
    
    // Example: {4, 5, 6, 7, 4, 5}
    // XOR Calculation:
    // (4 ^ 4) ^ (5 ^ 5) ^ 6 ^ 7 = 0 ^ 0 ^ 6 ^ 7 = 6 ^ 7 (Ye dono unique numbers ka XOR hai)
    
    // Step 2: XOR ka rightmost set bit find karo (jo bit dono numbers mein different hai)
    int rightmost_set_bit = xor_sum & -xor_sum;
    
    // Example: Agar xor_sum = 6 ^ 7 = 1
    // Binary: 0001
    // Rightmost set bit = 0001 (Last 1-bit jo differ kar rahi hai)
    
    int num1 = 0, num2 = 0;

    // Step 3: Array ko 2 groups mein divide karo
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmost_set_bit) {
            num1 ^= arr[i]; // Group 1 jisme bit 1 hai
        } else {
            num2 ^= arr[i]; // Group 2 jisme bit 0 hai
        }
    }
    
    // Example:
    // Group 1 (bit 1 hai): {7}
    // Group 2 (bit 0 hai): {6}
    // Ab dono groups ka XOR karne par unique numbers mil jaayenge

    // Step 4: Output do dono unique numbers
    cout << "Dono unique numbers hain: " << num1 << " aur " << num2 << endl;
}

int main() {
    int arr[] = {4, 5, 6, 7, 4, 5}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]);

    findUniqueNumbers(arr, n);

    return 0;
}

// this is not done by course, done by another method so read it 
// other easy method will be hash map 
