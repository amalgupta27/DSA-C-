/*
    -----------------------------------------------------------
    Question ka Logic (Hinglish me samjhaaya gaya):

    Problem:
    Humein ek string di gayi hai (jaise: "Amal is very very good boy").
    Humein pata lagana hai ki kaunsa word sabse zyada baar aaya hai (most occurring word).
    Aur us word ko kitni baar aaya hai, woh bhi print karna hai.

    Example:
    Input:  "Amal is very very good boy"
    Output:
        very 2

    Explanation:
    - Hum string ko words me todte hain (split karte hain).
    - Fir har word ko ek vector me daal dete hain.
    - Vector ko sort karte hain, taki same words ek saath aa jaayein.
    - Fir ek loop chala ke, consecutive same words ko count karte hain.
    - Jiska count sabse zyada hai, woh answer hai.

    -----------------------------------------------------------
    Flow Chart (Hinglish me):

    [Start]
       |
       v
    String declare karo (str)
       |
       v
    Stringstream object banao (ss)
       |
       v
    Jab tak ss se word milta rahe:
       |
       v
    Word ko vector me daalo
       |
       v
    Vector ko sort karo
       |
       v
    Loop chalao vector par, consecutive same words ka count nikaalo
       |
       v
    Max count aur uska word print karo
       |
       v
    [End]

    -----------------------------------------------------------
    Time Complexity:
    - String ko split karna: O(n) (n = string ki length)
    - Vector ko sort karna: O(k log k) (k = total words)
    - Loop se count nikalna: O(k)
    - Overall Time Complexity: O(n + k log k)
    - Space Complexity: O(k) (vector me words store ho rahe hain)

    -----------------------------------------------------------
*/

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string str = "Amal is very very good boy"; // Input string

    stringstream ss(str); // stringstream object banaya, jo string ko stream ki tarah treat karta hai
    string temp; // Har word ko temporarily store karne ke liye
    vector<string> v; // Sare words ko store karne ke liye vector

    // String ko words me tod ke vector me daal rahe hain
    while(ss >> temp){
        v.push_back(temp);
    }

    // Vector ke elements print kar rahe hain (original order)
    cout << "Words in string:" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    cout << endl;

    // Vector ko sort kar rahe hain taki same words ek saath aa jaayein
    sort(v.begin(), v.end());

    // Sorted vector print kar rahe hain
    cout << "Sorted words:" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    // Maximum occurring word nikalne ka logic
    int max_count = 1; // Sabse zyada baar aane wale word ka count
    int count = 1;     // Current word ka count
    string most_word = v[0]; // Sabse zyada baar aane wala word

    // Sorted vector me consecutive words compare karte hain
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]){
            count++;
        } else {
            count = 1;
        }
        if(count > max_count){
            max_count = count;
            most_word = v[i];
        }
    }

    cout << endl;
    cout << "Most occurring word: " << most_word << " " << max_count << endl;

    return 0;
}