/*
    -----------------------------------------------------------
    Question ka Logic (Hinglish me samjhaaya gaya):

    Problem:
    Humein ek string di gayi hai (jaise: "Amal is a simple boy").
    Humein is string ke har word ko alag-alag print karna hai.
    Yani, string ko words me todna hai aur har word ko nayi line me print karna hai.

    Example:
    Input:  "Amal is a simple boy"
    Output:
        Amal
        is
        a
        simple
        boy

    Explanation:
    - Hum stringstream ka use karte hain, jo ek aisa object hai jo string ko stream ki tarah treat karta hai.
    - Hum ss>>temp likh ke ek-ek word nikal sakte hain, jab tak words khatam nahi ho jaate.

    -----------------------------------------------------------
    Flow Chart (Hinglish me):

    [Start]
       |
       v
    Ek string declare karo (str)
       |
       v
    Stringstream object banao (ss)
       |
       v
    Jab tak ss se word milta rahe:
       |
       v
    Word ko temp me daalo aur print karo
       |
       v
    [End]

    -----------------------------------------------------------
    Time Complexity:
    - Har word ek baar process hota hai, toh O(n) (n = string ki length)
    - Space Complexity: O(1) (kyunki hum extra space nahi le rahe, sirf temp variable use ho raha hai)

    -----------------------------------------------------------
*/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string str = "Amal is a simple boy"; // Input string

    stringstream ss(str); // stringstream ek object hai jo string ko stream ki tarah treat karta hai

    string temp; // Har word ko temporarily store karne ke liye

    // Jab tak ss se word milta rahe, temp me daalte jao aur print karte jao
    while(ss >> temp){ // ss se input lekar temp mein daal do
        cout << temp<< endl ; // Har word nayi line me print karo
    }

    return 0;
}