#include <iostream>
using namespace std;
// Function to print numbers in a zigzag pattern using recursion
// n: The input number controlling the recursive depth
void zigzag(int n) {
    // Base case: If n reaches 0, stop recursion
    if (n == 0) return;
    // Pre-order step: Print before first recursive call
    cout << n << " ";
    // First recursive call (left branch)
    zigzag(n - 1);
    // In-order step: Print between recursive calls
    cout << n << " ";
    // Second recursive call (right branch)
    zigzag(n - 1);
    // Post-order step: Print after both recursive calls
    cout << n << " ";
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;
    // Call zigzag function
    zigzag(n);
    cout << endl;
    return 0;
}
/*
Explanation of Output for zigzag(3):

- The function follows a **zigzag recursive pattern**, where:
  1. Print **before** first recursive call.
  2. Call recursion with **n-1** (left branch).
  3. Print **between** recursive calls.
  4. Call recursion with **n-1** (right branch).
  5. Print **after** both recursive calls.

Step-by-step execution of `zigzag(3)`:

1. Call zigzag(3)
   - Print **3**
   - Call zigzag(2)

2. Call zigzag(2)
   - Print **2**
   - Call zigzag(1)

3. Call zigzag(1)
   - Print **1**
   - Call zigzag(0) (Base case, returns)
   - Print **1**
   - Call zigzag(0) (Base case, returns)
   - Print **1** (Returns to previous call)

4. Back to zigzag(2), after first recursive call:
   - Print **2**
   - Call zigzag(1) again (for right branch)

5. Call zigzag(1) (again)
   - Print **1**
   - Call zigzag(0) (Base case, returns)
   - Print **1**
   - Call zigzag(0) (Base case, returns)
   - Print **1** (Returns to previous call)

6. Back to zigzag(2), after second recursive call:
   - Print **2** (Returns to previous call)

7. Back to zigzag(3), after first recursive call:
   - Print **3**
   - Call zigzag(2) again (for right branch)

8. Call zigzag(2) (again)
   - Print **2**
   - Call zigzag(1)

9. Call zigzag(1)
   - Print **1**
   - Call zigzag(0) (Base case, returns)
   - Print **1**
   - Call zigzag(0) (Base case, returns)
   - Print **1** (Returns to previous call)

10. Back to zigzag(2), after first recursive call:
    - Print **2**
    - Call zigzag(1) again (for right branch)

11. Call zigzag(1) (again)
    - Print **1**
    - Call zigzag(0) (Base case, returns)
    - Print **1**
    - Call zigzag(0) (Base case, returns)
    - Print **1** (Returns to previous call)

12. Back to zigzag(2), after second recursive call:
    - Print **2** (Returns to previous call)

13. Back to zigzag(3), after second recursive call:
    - Print **3**

Final Output for `zigzag(3)`:3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3 */

