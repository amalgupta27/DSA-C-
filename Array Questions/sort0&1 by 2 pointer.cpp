#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 🔄 Swap function to exchange values
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

/*
🧠 PROBLEM:
0 aur 1 ki ek vector di gayi hai. Use aise sort karna hai ki sabse pehle sare 0 ho aur phir sare 1.

🧪 Example:
Input:  [0, 1, 1, 0, 0]
Output: [0, 0, 0, 1, 1]

🛠 LOGIC (Hinglish):
1. Start pointer s = 0, end pointer e = size-1
2. Jab tak s < e:
   - Agar v[s] == 0 -> s++ (0 sahi jagah pe hai)
   - Agar v[e] == 1 -> e-- (1 bhi sahi jagah pe hai)
   - Agar v[s]==1 && v[e]==0, to swap karo aur dono pointer move karo

📊 TIME COMPLEXITY:
O(n) — kyunki har element ek baar hi dekhte hain, nested loop nahi hai

📈 FLOWCHART (Hinglish):
Start
  |
  v
Initialize s = 0, e = size-1
  |
  v
Check s < e ?
  |
  +--> No --> End
  |
  v Yes
Check v[s] == 0 ?
  |
  +--> Yes --> s++
  |
  v No
Check v[e] == 1 ?
  |
  +--> Yes --> e--
  |
  v No
Check v[s]==1 && v[e]==0 ?
  |
  +--> Yes --> Swap(v[s], v[e]), s++, e--
  |
  v
Repeat loop
*/

int main(){
    // 🧾 Step 1: Input vector with 0s and 1s
    vector<int> v = {0, 1, 1, 0, 0};

    // 🖨 Printing original array
    cout << "Original Vector: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // 🧲 Step 2: Initialize start and end pointers
    int s = 0;
    int e = v.size() - 1;

    // 🔁 Step 3: Loop to sort the array using two-pointer approach
    while(s < e){
        // Agar start pe 0 hai to pointer aage badhao
        if(v[s] == 0) s++;

        // Agar end pe 1 hai to pointer peeche le jao
        if(v[e] == 1) e--;

        // Agar start bada ho gaya end se, loop break kar do
        if(s > e) break;

        // Agar start pe 1 hai aur end pe 0 hai to swap karo
        if(v[s] == 1 && v[e] == 0){
            swap(v[s], v[e]);  // 🔁 1 aur 0 ko sahi jagah le ja rahe hain
            s++;               // 👣 Start pointer aage
            e--;               // 👣 End pointer peeche
        }
    }

    // ✅ Step 4: Sorted output
    cout << "Sorted Vector: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}
