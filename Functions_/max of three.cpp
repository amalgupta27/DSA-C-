#include <iostream> // Input-Output stream ke liye
using namespace std;

/*
-------------------------------------------------------
🔵 PROBLEM LOGIC (Hinglish + Simple):

🔹 Hume 3 numbers ka maximum (sabse bada number) nikalna hai.

🔹 Approach:
- Compare karenge teeno numbers ko.
- Jo sabse bada hoga, usko return karenge.

🔹 Important Correction:
    Tumhare original condition thodi galat thi:
    - if(x > y && y > z) → ye sirf tab sahi hai jab teeno descending ho (jo zaruri nahi).
    - Sahi comparison hona chahiye:
      - if(x >= y && x >= z) return x;
      - else if(y >= x && y >= z) return y;
      - else return z;

-------------------------------------------------------
🔵 FLOWCHART (ASCII Hinglish):

[Start]
   |
   v
[Input x, y, z]
   |
   v
[Check: x >= y && x >= z]
   |         \
(Yes)         (No)
   |            \
[Return x]    [Check: y >= x && y >= z]
                  |         \
               (Yes)         (No)
                  |            \
             [Return y]      [Return z]
   |
   v
[End]

-------------------------------------------------------
🔵 FULL DETAILED CODE BELOW:
*/

int maxthree(int x, int y, int z) {
    // 🔹 Check if x is greatest or equal to both y and z
    if (x >= y && x >= z) 
        return x;
    // 🔹 Else check if y is greatest or equal to both x and z
    else if (y >= x && y >= z) 
        return y;
    // 🔹 Otherwise z will be the greatest
    else 
        return z;
}

int main() {
    int x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z; // 🔹 Take 3 number input from user

    int maxNum = maxthree(x, y, z); // 🔹 Find the maximum using function

    cout << "The largest number is: " << maxNum << endl; // 🔹 Output the maximum

    return 0;
}

/*
-------------------------------------------------------
🔵 Example Dry Run:

Input:
x = 7
y = 5
z = 9

Check:
Is x >= y and x >= z? (7 >= 5 && 7 >= 9) → False
Is y >= x and y >= z? (5 >= 7 && 5 >= 9) → False
Else z is max → z = 9

Output:
The largest number is: 9

-------------------------------------------------------
*/

