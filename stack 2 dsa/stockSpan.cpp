#include <bits/stdc++.h>
using namespace std;

/*
👨‍🏫==================== STOCK SPAN PROBLEM ====================👨‍🏫

🔎 Question:
Hume har din ke stock price ke liye "stock span" nikalna hai.
Yaani: Pichle kin continuous dino tak price chhota ya barabar tha?
(Stop jab bada price mil jaye ya array ka start aa jaye)

📦 Input:  [100, 80, 60, 81, 70, 60, 75, 85]
🎯 Output: [1,   1,  1,   3,  1,  1,  3,  7]

Span ka matlab:
→ "Kitne dino tak lagataar price chhota ya barabar tha current se?"

🌉 Logic:
- Previous Greater Element (PGE) nikalte hain.
- Fir Span = Current_Index - PGE_Index
- Agar PGE nahi mila (stack empty) toh Span = i + 1

🧠 Logic Summary:
1. Stack me indices store karo
2. Stack top ke index pe jo value hai agar wo chhoti ya barabar ho → pop karo
3. Jab tak bada element na mil jaye ya stack empty na ho jaye, pop karte raho
4. Stack me bacha top → usi index pe bada element hai (PGE)
5. Span = i - PGE_Index
   Agar PGE nahi mila (empty stack) → Span = i + 1

📊================ FLOWCHART (HINGLISH) =================

       +------------------------+
       |        Start           |
       +------------------------+
                 |
                 v
+----------------------------------------+
|  First element ka span = 1 (no left)   |
+----------------------------------------+
                 |
                 v
      ---> Loop i = 1 to n-1 --->
                 |
                 v
+--------------------------------------------+
| Stack top ke index ka value <= arr[i] ?    |
| Yes → pop()                                |
| No → break                                 |
+--------------------------------------------+
                 |
                 v
+---------------------------------------------+
| Stack empty?                                |
| Yes → span = i + 1                          |
| No → span = i - stack.top() (index diff)    |
+---------------------------------------------+
                 |
                 v
      stack.push(i)
                 |
                 v
        Loop repeat till end
                 |
                 v
        Print spans ✅

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n) (stack used)

===================================================================
*/

int main()
{
    int arr[] = {100, 80, 60, 81, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Span result store karne ke liye array
    int pgi[n];

    // Stack me hum index store karte hain
    stack<int> st;

    // Pehle element ka span hamesha 1 hota hai
    pgi[0] = 1;
    st.push(0); // Index 0 push

    // Traverse from left to right
    for (int i = 1; i < n; i++)
    {
        // Jab tak stack empty nahi hota aur current price se chhota ya barabar ho
        while (st.size() > 0 && arr[st.top()] <= arr[i])
        {
            st.pop(); // Chhote values hatao
        }

        // Agar stack empty hai → koi bada element nahi mila
        if (st.size() == 0)
            pgi[i] = -1; // Toh span = i - (-1) = i + 1
        else
            pgi[i] = st.top(); // Top index pe bada element mila

        // Final span nikaal lo
        pgi[i] = i - pgi[i];

        // Current index ko stack me daal do future ke use ke liye
        st.push(i);
    }

    // Original array print karo
    cout << "Original Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\nPrevious Greater Element (Span) Array:\n";
    for (int i = 0; i < n; i++)
        cout << pgi[i] << " ";
    cout << endl;

    return 0;
}
