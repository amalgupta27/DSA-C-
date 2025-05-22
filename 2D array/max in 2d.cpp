/*
📌 PROBLEM STATEMENT (Hinglish me samjho):
User se ek 2D array ka size (row × column) input lena hai, phir us array ke andar sabse bada element (maximum) find karna hai.

🧠 LOGIC (Step-by-Step):
1️⃣ User se row aur column input lo (m, n).
2️⃣ Ek 2D array declare karo with size m×n.
3️⃣ User se har element input lo aur array me store karo.
4️⃣ INT_MIN (int ka minimum possible value) se `max` variable initialize karo.
5️⃣ Array ke har element ko check karo:
      Agar current element `max` se bada hai to `max` ko update karo.
6️⃣ Loop khatam hone ke baad `max` variable me sabse bada element hoga.
7️⃣ Us `max` ko output karo.

🧾 EXAMPLE:
Input:
Enter the row: 2
Enter the column: 3
Enter elements:  10 20 15  30 25 35

2D Array:
10 20 15
30 25 35

Output:
Max element is:
35

🧮 TIME COMPLEXITY:
- Input: O(m × n)
- Max Search: O(m × n)
- Total: O(m × n)

📊 FLOWCHART (Hinglish):
START
  |
  |---> m, n input lo
  |
  |---> 2D array arr[m][n] banao
  |
  |---> User se m×n elements input lo aur array me store karo
  |
  |---> max = INT_MIN set karo
  |
  |---> Har element check karo:
  |        agar arr[i][j] > max
  |        ---> max = arr[i][j]
  |
  |---> Loop ke baad max print karo
  |
  ---> END

✅ Simple, efficient aur beginner-friendly!

---------------------------------------------------------
👇👇👇 Actual Working Code (Do not change this)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cout<<"Enter the row: ";
    cin>>m;
    int n;
    cout<<"Enter the column: ";
    cin>>n;

    int arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    //maximum 
    cout<<"Max element is: "<<endl;
    int max= INT_MIN;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(max<arr[i][j]){
                max = arr[i][j];
            }
        }
    }
    cout<<max<<endl;
}
