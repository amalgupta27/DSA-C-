#include <iostream>
using namespace std;

// Function to print all possible paths from (sr,sc) to (er,ec)
// sr: Starting row index
// sc: Starting column index
// er: Ending row index (destination row)
// ec: Ending column index (destination column)
// s: String to store the current path (R for right, D for down)

void printPath(int sr, int sc, int er, int ec, string s) {
    // Base case: If the position goes out of bounds, return
    if (sr > er || sc > ec) return;

    // Base case: If the destination is reached, print the path
    if (sr == er && sc == ec) {
        cout << s << endl;
        return;
    }

    // Move right (increment column index)
    printPath(sr, sc + 1, er, ec, s + 'R');

    // Move down (increment row index)
    printPath(sr + 1, sc, er, ec, s + 'D');
}

int main() {
    // Example 1: Finding all paths in a 4x4 grid from (1,1) to (4,4)
    cout << "All possible paths from (1,1) to (4,4): " << endl;
    printPath(1, 1, 4, 4, "");

    /*
    Explanation:
    The grid size is 4x4 (indices: 1 to 4 for both rows and columns).
    The function starts at (1,1) and can move right ('R') or down ('D').
    The function recursively generates all possible paths to reach (4,4).
    
    Example outputs (some possible paths):
    RRRDDDD
    RRDRDDD
    RRDDDRD
    RRDDDDR
    RDRDDDD
    ...
    Total number of paths: 20 (similar to combinatorial calculation).
    */

    return 0;
}
