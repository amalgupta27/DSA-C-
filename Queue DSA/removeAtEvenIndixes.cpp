/*
🔁 QUEUE SE EVEN INDEX WALE ELEMENTS KO REMOVE KARNA

📌 Objective:
Ek queue di gayi hai jisme kuch elements hain. Hume un elements ko hataana hai jo even index par hain. (0-based indexing)

📍 Example:
Input Queue:  10 20 30 40 50
Indexes:       0  1  2  3  4

Even indexes → 0, 2, 4 → remove: 10, 30, 50
Output Queue: 20 40

👣 Approach:
1. Queue me se ek-ek karke element uthao.
2. Agar index EVEN hai → us element ko discard kar do (pop karo).
3. Agar index ODD hai → us element ko pop karke wapas push kar do (queue me bacha lo).
4. Ye step queue ke size ke barabar baar repeat karo.

🧠 Dry Run:
Original Queue: 10 20 30 40 50
Step-by-step:
i = 0 ➝ even ➝ pop 10
i = 1 ➝ odd  ➝ pop 20, push 20
i = 2 ➝ even ➝ pop 30
i = 3 ➝ odd  ➝ pop 40, push 40
i = 4 ➝ even ➝ pop 50

Final Queue: 20 40 ✅

📈 Time Complexity:
→ O(n), where n is number of elements in queue

📦 Space Complexity:
→ O(1), no extra space used

🔄 FLOWCHART (ASCII Style - Hinglish)

      +---------------------+
      |  Start Program      |
      +---------------------+
                |
                v
      +---------------------+
      |  Queue Size = n     |
      +---------------------+
                |
                v
      +---------------------+
      |  Loop i = 0 to n-1  |
      +---------------------+
                |
       +--------+--------+
       |                 |
 +-----v-----+     +-----v-----+
 | i % 2 == 0|     | i % 2 == 1|
 +-----------+     +-----------+
       |                 |
 +-----v-----+     +-----v-----------+
 | Pop front |     | Pop front       |
 | (discard) |     | Push to back    |
 +-----------+     +-----------------+
                |
                v
        +-------------------+
        | Display Final Q   |
        +-------------------+
                |
                v
             +------+
             | End  |
             +------+

*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// ✅ Display function - Queue ke saare elements print karega bina structure ko todke
void display(queue<int> q){
    int n = q.size();
    for(int i=0; i<n; i++){
        cout<<q.front()<<" ";  // front element print karo
        q.pop();               // nikal do
        q.push(q.front());     // queue ke end me wapas lagao
    }
    cout<<endl;
}

// ✅ Function to remove elements at even indices
void removeAtEvenIndixes(queue<int> &q){
    int n = q.size(); // original size store karna zaroori hai
    for(int i=0; i<n; i++){
        if(i % 2 == 0){
            // 🟥 EVEN INDEX → element discard karna hai
            q.pop(); 
        }
        else{
            // 🟩 ODD INDEX → element preserve karna hai
            int x = q.front(); // front lo
            q.pop();           // nikal do
            q.push(x);         // queue ke end me wapas lagao
        }
    }
}

int main(){
    queue<int> q;

    // 🌟 Inserting elements into queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    display(q); // Expected: 10 20 30 40 50

    // 📦 Remove elements at even indexes
    removeAtEvenIndixes(q);

    cout << "After Removing Even Index Elements: ";
    display(q); // Expected: 20 40

    return 0;
}

/*
🟢 Output:
Original Queue: 10 20 30 40 50 
After Removing Even Index Elements: 20 40 
*/
