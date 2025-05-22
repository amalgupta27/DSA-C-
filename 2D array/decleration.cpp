/*
🧠 LOGIC: 2D ARRAY INPUT & OUTPUT PROGRAM (Hinglish Explanation)
=================================================================================
🔶 Objective:
    ➤ User se row (m) aur column (n) ka size lena hai
    ➤ Ek 2D array arr[m][n] banana hai
    ➤ User se array ke elements input lena hai
    ➤ Fir unko wapas print karna hai (as a matrix/table)

🔶 Real Life Example:
    - Maal lo tumhare paas ek classroom ka seating chart hai
    - Row = 3 (rows of benches), Column = 4 (students per bench)
    - Tum input doge: 12 names/roll numbers/matrix numbers
    - Program us seating layout ko wapas print karega

🔶 Example Input:
    Enter the row: 2
    Enter the column: 3
    Inputs: 1 2 3 4 5 6

🔶 Output:
    1 2 3
    4 5 6

📊 FLOWCHART (ASCII) – Hinglish Style:
=================================================================================

                +--------------------------+
                |     Start Program        |
                +--------------------------+
                          |
                          V
            +----------------------------+
            |  User se rows aur columns  |
            +----------------------------+
                          |
                          V
            +----------------------------+
            |   Create 2D array arr[m][n]|
            +----------------------------+
                          |
                          V
            +----------------------------+
            |  Loop for input elements   |
            |   ➤ row-wise fill karo     |
            +----------------------------+
                          |
                          V
            +----------------------------+
            |  Loop to print elements    |
            |   ➤ row-wise print karo    |
            +----------------------------+
                          |
                          V
                  +---------------+
                  |    Program End|
                  +---------------+

⏱️ TIME COMPLEXITY:
=================================================================================
➤ Input: O(m*n)  → kyunki har cell me value input karni hai
➤ Output: O(m*n) → kyunki har cell print karna hai
➤ Total: O(m*n)

📌 NOTE:
➤ Ye code sirf fixed-size matrix ke liye hai (int arr[m][n]) – 
   C++ VLA (Variable Length Array) g++ compiler pe kaam karta hai.
➤ Better version ke liye dynamically allocate karna hota hai (advanced topic)
*/

#include<iostream>
using namespace std;

int main() {
    int m; // rows
    cout<<"Enter the row: ";
    cin>>m; // user se row input lo

    int n; // columns
    cout<<"Enter the column: ";
    cin>>n; // user se column input lo

    int arr[m][n]; // 📦 2D array of size m x n

    // 🔁 INPUT: Har row aur column par loop lagake value input karo
    for(int i=0; i<m; i++){ // row-wise
        for(int j=0; j<n; j++){ // column-wise
            cin>>arr[i][j]; // user input
        }
    }

    cout<<"Done"<<endl; // input done

    // 🔁 OUTPUT: Har element ko row-wise print karo
    for(int i=0; i<m; i++){ // row-wise
        for(int j=0; j<n; j++){ // column-wise
            cout<<arr[i][j]<<" "; // space ke sath print
        }
        cout<<endl; // new line for each row
    }
}

/*
📚 INITIALISATION OF A 2-DIMENSIONAL ARRAY IN C++

✅ Correct Ways:

✔ int arr[4][2] = { 
    {1234, 56}, 
    {1256, 43}, 
    {1434, 32}, 
    {1312, 96} 
  };

✔ int arr[4][2] = {
    1234, 56, 
    1256, 43, 
    1434, 32, 
    1312, 96 
  };

✔ int arr[2][3] = { 
    12, 34, 56, 
    78, 91, 23 
  };

✔ int arr[][3] = {
    12, 34, 56, 
    78, 91, 23 
  };
  // Note: Rows will be inferred by compiler = 2 rows (since 6 elements and 3 columns)

❌ Incorrect Way:

✘ int arr[2][][] = {
    12, 34, 56, 
    78, 91, 23 
  };
  // Error: You must specify column size in declaration; can't leave both dimensions empty.

🎯 Summary:
- Column size is **mandatory** in 2D array declaration in C++
- You can **omit row size**, compiler calculates it based on total elements
- Grouped `{}` or flat list of values both work as long as column count matches
*/
