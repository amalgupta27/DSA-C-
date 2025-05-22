/*
------------------------------------------------------
💡 LOGIC IN HINGLISH WITH FLOWCHART AND DRY RUN
------------------------------------------------------

🧠 PROBLEM: 
Hume ek square matrix (same rows & columns) ka TRANSPOSE nikalna hai.

📘 Transpose ka matlab: matrix ke rows ko columns bana dena.
i.e., element at (i,j) ko (j,i) bana dena.

🧾 INPUT: 
- Pehle ek number 'n' (matrix size) lena hai
- Fir n x n elements input karne hain

🔁 PROCESS:
- Matrix input lo
- Transpose ke liye har (i,j) ko (j,i) se swap karo jaha j > i
- Transposed matrix print karo

🔍 EXAMPLE:
Input:
n = 3
Matrix:
1 2 3
4 5 6
7 8 9

Transpose:
1 4 7
2 5 8
3 6 9

------------------------------------------------------
📊 FLOWCHART (Hinglish Main)
------------------------------------------------------

             +--------------------------+
             |  User se 'n' input lo    |
             +-----------+--------------+
                         |
                         v
             +--------------------------+
             |  n x n matrix fill karo  |
             +-----------+--------------+
                         |
                         v
             +--------------------------+
             | Matrix print karo        |
             +-----------+--------------+
                         |
                         v
             +------------------------------+
             | Transpose ke liye swap karo  |
             | arr[i][j] <--> arr[j][i]     |
             | (jab j > i ho)               |
             +-----------+------------------+
                         |
                         v
             +--------------------------+
             | Transposed matrix print  |
             +--------------------------+

------------------------------------------------------
📈 TIME COMPLEXITY:
------------------------------------------------------
- Matrix input & print = O(n^2)
- Transpose swapping   = O(n^2)
- Final print          = O(n^2)
✅ Total Time: O(n^2)
------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main() {
  
    int n;
    cout << "Enter the number of rows and columns: "; // square matrix ke liye
    cin >> n;

    int arr[n][n]; // static 2D array of size n x n

    // ----------------------------
    // Step 1: Input lena matrix ka
    // ----------------------------
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {          // row ke liye loop
        for (int j = 0; j < n; j++) {      // column ke liye loop
            cin >> arr[i][j];             // element input
        }
    }

    // ----------------------------
    // Step 2: Original matrix print
    // ----------------------------
    cout << "\nOriginal Matrix:" << endl;
    for (int i = 0; i < n; i++) {         // row
        for (int j = 0; j < n; j++) {     // column
            cout << arr[i][j] << " ";     // print element
        }
        cout << endl;
    }

    // ----------------------------
    // Step 3: Transpose logic
    // ----------------------------
    // Sirf upper triangle (j > i) wale elements ko swap karo
    for (int i = 0; i < n; i++) {           // i row
        for (int j = i + 1; j < n; j++) {   // j column, starting from i+1
            // element (i,j) <--> (j,i)
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // ----------------------------
    // Step 4: Transposed matrix print karo
    // ----------------------------
    cout << "\nTranspose of the given array: " << endl;
    for (int i = 0; i < n; i++) {         // row
        for (int j = 0; j < n; j++) {     // column
            cout << arr[i][j] << " ";     // print transpose element
        }
        cout << endl;
    }

    return 0;
}
