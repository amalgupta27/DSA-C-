/*
    -----------------------------------------------------------
    Question: "First Negative Number in Every Window of Size K"
    -----------------------------------------------------------

    Hinglish Explanation:
    ---------------------
    - Hume ek array diya hai, jaise: [3, -4, -7, 30, 7, -9, 2, 1, 6, -1]
    - Aur ek window size 'k' diya hai, maan lo k = 3.
    - Har window (yaani har lagatar k elements ka group) ke liye, 
      hume us window ka pehla negative number print karna hai.
    - Agar window me koi negative nahi hai, toh 0 print karna hai.

    Example:
    --------
    Array:  [3, -4, -7, 30, 7, -9, 2, 1, 6, -1]
    Window size (k): 3

    Windows aur unka pehla negative:
    [3, -4, -7]   => -4
    [-4, -7, 30]  => -4
    [-7, 30, 7]   => -7
    [30, 7, -9]   => -9
    [7, -9, 2]    => -9
    [-9, 2, 1]    => -9
    [2, 1, 6]     => 0   (no negative)
    [1, 6, -1]    => -1

    Output: -4 -4 -7 -9 -9 -9 0 -1

    -----------------------------------------------------------
    Flow Chart (Hinglish):
    -----------------------------------------------------------
    1. Array aur window size lo
    2. Sabhi negative elements ke index queue me daalo
    3. Har window ke liye:
        a. Queue se purane index hatao (jo window ke bahar hai)
        b. Agar queue empty hai ya front index window ke bahar hai, toh 0 daalo
        c. Warna, queue ka front index ka element answer me daalo
    4. Sabhi answers print karo

    Flow Chart (ASCII Art):
    -----------------------
    [Start]
       |
       v
    Array aur k lo
       |
       v
    Negative index queue me daalo
       |
       v
    Har window ke liye:
       |
       v
    [Queue se purane index hatao]
       |
       v
    [Queue empty?]---Yes---> [0 daalo]
       | No
       v
    [Queue front ka element daalo]
       |
       v
    Next window
       |
       v
    [Sabhi answers print karo]
       |
       v
    [End]

    -----------------------------------------------------------
    Time Complexity:
    ----------------
    - Har element sirf ek baar queue me aata hai aur ek baar nikalta hai.
    - Isliye overall time complexity: O(n)
    - Space complexity: O(k) (queue me max k elements ho sakte hain)

    -----------------------------------------------------------
    Code Explanation (with Example):
    --------------------------------
    - arr = [3, -4, -7, 30, 7, -9, 2, 1, 6, -1], k = 3
    - Pehle, sabhi negative elements ke index queue me daal diye.
      Queue: [1, 2, 5, 9]  (kyunki arr[1]=-4, arr[2]=-7, arr[5]=-9, arr[9]=-1)
    - Ab, har window ke liye:
      - Window [i, i+k-1] check karo
      - Queue ka front agar window ke bahar hai toh pop karo
      - Agar queue empty hai ya front index window ke bahar hai toh 0 daalo
      - Warna, arr[queue.front()] answer me daalo

    -----------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    int arr[]={3,-4,-7,30,7,-9,2,1,6,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int> ans;
    // Array print kar rahe hain
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Sabhi negative elements ke index queue me daal rahe hain
    for(int i=0; i<n; i++){
        if(arr[i]<0) q.push(i);
    }
    int i=0;
    // Har window ke liye process kar rahe hain
    while(i+k<=n){
        // Queue se purane index hata rahe hain (jo window ke bahar hain)
        while(q.size()>0 && q.front()<i) q.pop();
        // Agar queue empty hai ya front index window ke bahar hai toh 0 daal rahe hain
        if(q.size()==0||q.front()>=i+k) ans.push_back(0);
        // Warna, queue ka front index ka element answer me daal rahe hain
        else ans.push_back(arr[q.front()]);
        i++;
    }
    // Answers print kar rahe hain
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}