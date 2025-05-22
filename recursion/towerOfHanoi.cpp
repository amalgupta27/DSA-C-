#include <iostream>  // Include the iostream library for input and output operations
using namespace std;  

// Function to solve the Tower of Hanoi problem recursively
// n -> Number of disks
// s -> Source rod
// h -> Helper rod
// d -> Destination rod
void hanoi(int n, char s, char h, char d) {
    if (n == 0) return; // Base case: if no disks, return

    hanoi(n - 1, s, d, h); // Move (n-1) disks from source to helper using destination as auxiliary
    cout << "Move disk " << n << " from rod " << s << " to rod " << d << endl; // Move nth disk to destination
    hanoi(n - 1, h, s, d); // Move (n-1) disks from helper to destination using source as auxiliary
}

int main() {
    int n = 3; // Define the number of disks
    hanoi(n, 'A', 'B', 'C'); // Call the Tower of Hanoi function with rods A, B, and C
    
    return 0; // Indicate successful program execution
}

/*
Example Output for n = 3:
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C

Example 2 (for n = 2):
Move disk 1 from rod A to rod B
Move disk 2 from rod A to rod C
Move disk 1 from rod B to rod C
*/
