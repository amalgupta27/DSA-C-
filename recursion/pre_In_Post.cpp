#include <iostream>
using namespace std;
// Function to demonstrate Pre-In-Post recursion sequence
// n: The input number controlling the recursive depth
void PIP(int n) {
    // Base case: If n reaches 0, stop recursion
    if (n == 0) return;
    // Pre-order step: Print before recursive calls
    cout << "Pre " << n << endl;
    // First recursive call (left branch)
    PIP(n - 1);
    // In-order step: Print between recursive calls
    cout << "In " << n << endl;
    // Second recursive call (right branch)
    PIP(n - 1);
    // Post-order step: Print after both recursive calls
    cout << "Post " << n << endl;
}
int main() {
    cout << endl;
    // Example: Calling PIP with n = 2
    PIP(2);
    cout << endl;
    return 0;
}
/*
Explanation of Output for PIP(2):

- The function follows a recursive pattern with three key steps:
  1. **Pre-order**: Print before recursion.
  2. **In-order**: Print between left and right recursion.
  3. **Post-order**: Print after recursion.

Step-by-step execution of PIP(2):

1. Call PIP(2)
   - Print **Pre 2**
   - Call PIP(1)

2. Call PIP(1)
   - Print **Pre 1**
   - Call PIP(0) (Base case, returns)
   - Print **In 1**
   - Call PIP(0) (Base case, returns)
   - Print **Post 1**
   
3. Back to PIP(2), after first recursive call:
   - Print **In 2**
   - Call PIP(1) again (for right branch)

4. Call PIP(1) (again)
   - Print **Pre 1**
   - Call PIP(0) (Base case, returns)
   - Print **In 1**
   - Call PIP(0) (Base case, returns)
   - Print **Post 1**

5. Back to PIP(2), after second recursive call:
   - Print **Post 2**

Final Output:Pre 2 Pre 1 In 1 Post 1 In 2 Pre 1 In 1 Post 1 Post 2 */

