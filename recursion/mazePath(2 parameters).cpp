#include <iostream>
using namespace std;

// Function to calculate the number of unique paths in a maze using recursion
// row: Current row index (starting from bottom-right corner)
// col: Current column index (starting from bottom-right corner)
// The function finds the number of paths from (row, col) to (1,1)

int maze2(int row, int col) {
    // Base case: If row or column is out of bounds, return 0 (invalid path)
    if (row < 1 || col < 1) return 0;

    // Base case: If we reach the starting point (1,1), return 1 (valid path)
    if (row == 1 && col == 1) return 1;

    // Recursive case: Move left (reduce column) and move up (reduce row)
    int rightWays = maze2(row, col - 1); // Move left
    int downWays = maze2(row - 1, col);  // Move up

    // Total number of ways to reach (1,1)
    int totalWays = rightWays + downWays;
    return totalWays;
}

int main() {
    // Example 1: Finding the number of paths in a 3x3 grid (1-based index)
    cout << "Number of ways to reach (1,1) from (3,3): " << maze2(3, 3) << endl;

    /*
    Explanation:
    - The grid size is 3x3 (indices: 1 to 3 for both rows and columns).
    - The function starts at (3,3) and moves left ('←') or up ('↑').
    - The total number of unique paths to reach (1,1) is calculated.

    Possible paths:
    1. ← ← ↑ ↑
    2. ← ↑ ← ↑
    3. ← ↑ ↑ ←
    4. ↑ ↑ ← ←
    5. ↑ ← ↑ ←
    6. ↑ ← ← ↑
    
    Output: 6
    */

    // Example 2: Finding the number of paths in a 4x4 grid (1-based index)
    cout << "Number of ways to reach (1,1) from (4,4): " << maze2(4, 4) << endl;

    /*
    Explanation:
    - The grid size is 4x4 (indices: 1 to 4 for both rows and columns).
    - The function starts at (4,4) and moves left ('←') or up ('↑').
    - The total number of unique paths to reach (1,1) is calculated.
    
    Output: 20 (same as combinatorial calculation).
    */

    return 0;
}

/*
Example outputs:

Number of ways to reach (1,1) from (3,3): 6
Number of ways to reach (1,1) from (4,4): 20
*/
