#include <iostream>
#include <vector>
using namespace std;

// ✅ Yeh function do numbers ko swap karta hai by reference
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

// ✅ Yeh function vector ke elements ko display karta hai
int display(vector<int> &a){
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int main(){
    // ✅ Vector banaya gaya hai jisme kuch initial values hain
    vector<int> v = {1, 2, 3, 4, 5, 6};

    /*
    ------------------------------------------
    🧠 Logic (Two Pointer Approach - Hinglish):
    ------------------------------------------
    Step 1: Do pointers lo -> i (start) and j (end)
    Step 2: Jab tak i < j ho, tab tak:
            -> v[i] aur v[j] ko swap karo
            -> i ko aage badhao, j ko peeche lao
    Step 3: Jab loop khatam ho jaye, vector reverse ho chuka hoga
    ------------------------------------------
    Example:
    v = [1, 2, 3, 4, 5, 6]
    Iteration 1: swap(1, 6) -> [6, 2, 3, 4, 5, 1]
    Iteration 2: swap(2, 5) -> [6, 5, 3, 4, 2, 1]
    Iteration 3: swap(3, 4) -> [6, 5, 4, 3, 2, 1]
    ------------------------------------------
    */

    int i = 0;
    int j = v.size() - 1;

    // ✅ Vector ko reverse karne ka loop (two pointer technique)
    while(i < j){
        swap(v[i], v[j]);
        i++;
        j--;
    }

    // ✅ Final reversed vector print karo
    display(v);
    return 0;
}
 