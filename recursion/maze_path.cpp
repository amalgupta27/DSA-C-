#include<iostream>  
using namespace std;  

// Function to calculate the number of unique paths in a maze using recursion
// The function takes four parameters:
// sr: Starting row index
// sc: Starting column index
// er: Ending row index (destination)
// ec: Ending column index (destination)

int maze(int sr, int sc, int er, int ec) {
    // Base case: If the current position is the destination, return 1 (valid path found)
    if (sr == er && sc == ec) return 1;
    
    // Base case: If the current position goes out of bounds, return 0 (invalid path)
    if (sr > er || sc > ec) return 0;

    // Recursive case: Move right (increase column index) and move down (increase row index)
    int rightWays = maze(sr, sc + 1, er, ec);
    int downWays = maze(sr + 1, sc, er, ec);

    // Total number of ways to reach the destination
    int totalWays = rightWays + downWays;
    
    return totalWays;
}

int main() {
    // Example 1: Finding number of paths in a 3x3 grid (0-based index)
    cout << "Number of ways to reach (2,2) from (0,0): " << maze(0, 0, 2, 2) << endl;

    /*
    Explanation:
    The grid size is 3x3 (indices: 0 to 2 for both rows and columns).
    The function starts at (0,0) and can move only right or down.
    The total number of unique ways to reach (2,2) is calculated.
    Possible paths:
    1. Right → Right → Down → Down
    2. Right → Down → Right → Down
    3. Right → Down → Down → Right
    4. Down → Down → Right → Right
    5. Down → Right → Down → Right
    6. Down → Right → Right → Down
    Output: 6
    */

    // Example 2: Finding number of paths in a 4x4 grid (0-based index)
    cout << "Number of ways to reach (3,3) from (0,0): " << maze(0, 0, 3, 3) << endl;

    /*
    Explanation:
    The grid size is 4x4 (indices: 0 to 3 for both rows and columns).
    The function starts at (0,0) and can move right or down.
    The total number of unique paths to reach (3,3) is calculated.
    Output: 20 (paths counted recursively)
    */

    return 0;  
}

/*
Example outputs:
Number of ways to reach (2,2) from (0,0): 6
Number of ways to reach (3,3) from (0,0): 20
*/
