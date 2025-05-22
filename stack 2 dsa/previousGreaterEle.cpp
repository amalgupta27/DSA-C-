#include <bits/stdc++.h>
using namespace std;

/*
👨‍🏫================= LOGIC IN HINGLISH =================👨‍🏫

👉 Question:
   Hume har element ke liye uska **Previous Greater Element (PGE)** nikalna hai.
   Yaani:
   ➤ kisi element ke left me pehla bada number konsa hai?

🔍 Example:
    Input:   [3, 1, 2, 7, 4, 6, 2, 3]
    Output:  [-1, 3, 3, -1, 7, 7, 6, 6]

🧠 Kaise kaam karta hai?
----------------------------------
METHOD 1: Brute Force
----------------------------------
1. Har element ke left wale elements ko check karo.
2. Pehla bada element milte hi answer store karo.
3. Na mile to -1 store karo.

⏱️ Time Complexity: O(n^2)
⏳ Space Complexity: O(1)

----------------------------------
METHOD 2: Optimal using Stack (Left to Right)
----------------------------------
Idea: Stack me hamesha left side ke useful elements store karo

🔁 Steps:
1. Pehle element ka PGE -1 hota hai (kyunki left me kuch nahi)
2. Stack me pehla element ko push karo
3. Ab left se right chalo:
   - Jab tak stack top <= current element ho, pop karte raho
   - Agar stack empty ho gaya ➝ PGE = -1
   - Agar stack me koi element bacha hai ➝ wahi PGE hoga
   - Fir current element ko stack me push karo

📦 Stack ka kaam:
   - Sirf wahi elements rakhna jo future me kisi ke liye PGE ban sakte ho

⏱️ Time Complexity: O(n)
⏳ Space Complexity: O(n)

📊================= FLOWCHART (HINGLISH) =================📊

       +-------------------------+
       |       Start            |
       +-------------------------+
                  |
                  v
    +-------------------------------+
    |  First element ka PGE = -1    |
    +-------------------------------+
                  |
                  v
        ---> Loop from 1 to n-1 ---
                  |
                  v
    +-------------------------------+
    | Stack top <= current ?        |
    | Yes ➝ pop                     |
    | No ➝ move ahead               |
    +-------------------------------+
                  |
                  v
    +-------------------------------+
    | Stack empty? ➝ PGE = -1       |
    | Else ➝ PGE = stack.top()      |
    +-------------------------------+
                  |
                  v
        Push current into stack
                  |
                  v
         Repeat till end of array
                  |
                  v
              Print PGE array ✅

===============================================
*/

int main()
{
    int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Array to store result (Previous Greater Elements)
    int pge[n];

    // OPTIMAL METHOD (USING STACK) : pop ,ans ,push 
    stack<int> st;

    // Step 1: First element ka answer -1 hoga (left me kuch nahi)
    pge[0] = -1;
    st.push(arr[0]);

    // Step 2: Traverse from left to right
    for (int i = 1; i < n; i++)
    {
        // Step 3: Remove chhote ya barabar elements
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        // Step 4: PGE assign karo
        if (st.empty())
            pge[i] = -1; // Koi bada element nahi mila
        else
            pge[i] = st.top(); // Top is the previous greater

        // Step 5: Current element ko stack me daalo
        st.push(arr[i]);
    }

    // Print the result
    cout << "Original Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\nPrevious Greater Element Array:\n";
    for (int i = 0; i < n; i++)
        cout << pge[i] << " ";
    cout << endl;

    return 0;
}
 