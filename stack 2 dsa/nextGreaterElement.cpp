#include <bits/stdc++.h>
using namespace std;

/*
👨‍🏫================= LOGIC IN HINGLISH =================👨‍🏫

👉 Question:
   Hume har element ke liye uska **Next Greater Element (NGE)** nikalna hai.
   Yaani:
   ➤ kisi element ke right me pehla bada number konsa hai?

🔍 Example:
    Input:   [3, 1, 2, 7, 4, 6, 2, 3]
    Output:  [7, 2, 7, -1, 6, -1, 3, -1]

🧠 Kaise kaam karta hai?
----------------------------------
METHOD 1: Brute Force
----------------------------------
1. Har element ke right wale elements ko check karo.
2. Pehla bada element milte hi answer store karo.
3. Na mile to -1 store karo.

⏱️ Time Complexity: O(n^2) --> Slow for large inputs
⏳ Space Complexity: O(1) (no extra space used)

----------------------------------
METHOD 2: Optimal using Stack (Right to Left)
----------------------------------
Idea: Stack me hamesha right side ke useful elements store karo

🔁 Steps:
1. Last element ka NGE -1 hota hai (kyunki right me kuch nahi)
2. Stack me last element ko push karo
3. Ab right se left chalo:
   - Jab tak stack top <= current element ho, pop karte raho
   - Agar stack empty ho gaya ➝ NGE = -1
   - Agar stack me koi element bacha hai ➝ wahi NGE hoga
   - Fir current element ko stack me push karo

📦 Stack ka kaam:
   - Sirf wahi elements rakhna jo future me kisi ke liye NGE ban sakte ho

⏱️ Time Complexity: O(n)
⏳ Space Complexity: O(n) (stack use ho raha hai)

📊================= FLOWCHART (HINGLISH) =================📊

       +-------------------------+
       |       Start            |
       +-------------------------+
                  |
                  v
    +-------------------------------+
    |  Last element ka NGE = -1     |
    +-------------------------------+
                  |
                  v
        <--- Loop from n-2 to 0 ---
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
    | Stack empty? ➝ NGE = -1       |
    | Else ➝ NGE = stack.top()      |
    +-------------------------------+
                  |
                  v
        Push current into stack
                  |
                  v
         Repeat till start of array
                  |
                  v
              Print NGE array ✅

===============================================
*/

int main()
{
    int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Array to store result (Next Greater Elements)
    int nge[n];

    // ---------------------- BRUTE FORCE ----------------------
    // Uncomment if you want to try this as well
    /*
    for (int i = 0; i < n; i++)
    {
        nge[i] = -1; // Default = -1
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                nge[i] = arr[j]; // Pehla bada element mila
                break;
            }
        }
    }
    */

    //  OPTIMAL METHOD (USING STACK) : pop ,ans ,push 
    stack<int> st;

    // Step 1: Last element ka answer -1 hoga (right me kuch nahi)
    nge[n - 1] = -1;
    st.push(arr[n - 1]);

    // Step 2: Traverse from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        // Step 3: Remove chhote ya barabar elements
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        // Step 4: NGE assign karo
        if (st.empty())
            nge[i] = -1; // Koi bada element nahi mila
        else
            nge[i] = st.top(); // Top is the next greater

        // Step 5: Current element ko stack me daalo
        st.push(arr[i]);
    }

    // Print the result
    cout << "Original Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\nNext Greater Element Array:\n";
    for (int i = 0; i < n; i++)
        cout << nge[i] << " ";
    cout << endl;

    return 0;
}
