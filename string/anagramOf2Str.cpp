/*
    -----------------------------------------------------------
    Question ka Logic (Hinglish me samjhaaya gaya):

    Problem:
    Humein do strings di gayi hain. Humein check karna hai ki kya dono strings anagram hain ya nahi.
    (Anagram ka matlab: dono strings ke characters same hone chahiye, bas order alag ho sakta hai.)

    Example:
    Input:
        s = "listen"
        t = "silent"
    Output:
        Strings are Anagram

    Explanation:
    - "listen" ke characters: l, i, s, t, e, n
    - "silent" ke characters: s, i, l, e, n, t
    - Dono me same characters hain, bas order alag hai, toh ye anagram hain.

    -----------------------------------------------------------
    Flow Chart (Hinglish me):

    [Start]
       |
       v
    Pehli string input lo (s)
       |
       v
    Dusri string input lo (t)
       |
       v
    Dono strings ko sort karo
       |
       v
    Agar sorted s == sorted t?
       |---[Yes]---> "Strings are Anagram" print karo
       |---[No]----> "Strings are not Anagram" print karo
       |
       v
    [End]

    -----------------------------------------------------------
    Time Complexity:
    - Sorting dono strings ka time: O(n log n), jaha n = string ki length
    - Comparison: O(n)
    - Overall Time Complexity: O(n log n)
    - Space Complexity: O(1) (in-place sorting ho rahi hai)

    -----------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <algorithm> // sort ke liye
using namespace std;

int main(){
    string s; 
    cout << "Enter first String: " << endl;
    getline(cin, s); // Pehli string input lo

    string t;
    cout << "Enter second String: " << endl;
    getline(cin, t); // Dusri string input lo

    // Dono strings ko sort karo taki characters ka order same ho jaye
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    // Agar dono sorted strings same hain toh anagram hain
    if(s == t) 
        cout << "Strings are Anagram" << endl;
    else 
        cout << "Strings are not Anagram" << endl;

    return 0;  
}