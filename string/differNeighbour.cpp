/*
    -----------------------------------------------------------
    Question ka Logic (Hinglish me samjhaaya gaya):

    Problem: 
    Humein ek string di gayi hai. Humein count karna hai kitne aise characters hain 
    jo apne dono neighbours (left aur right) se alag hain.
    (Agar character first ya last hai toh sirf ek neighbour hoga.)

    Example:
    Input:  "ababa"
    Index:   0 1 2 3 4
             a b a b a

    - i=0: 'a' (sirf right neighbour 'b'), 'a' != 'b' => count++
    - i=1: 'b' (left 'a', right 'a'), 'b' != 'a' && 'b' != 'a' => count++
    - i=2: 'a' (left 'b', right 'b'), 'a' != 'b' && 'a' != 'b' => count++
    - i=3: 'b' (left 'a', right 'a'), 'b' != 'a' && 'b' != 'a' => count++
    - i=4: 'a' (sirf left neighbour 'b'), 'a' != 'b' => count++

    Output: 5

    -----------------------------------------------------------
    Flow Chart (Hinglish me):

    [Start]
       |
       v
    String input lo
       |
       v
    Agar string ki length 1 hai?
       |---[Yes]---> [Break]
       |
      [No]
       |
       v
    Loop chalao har character par (i = 0 to n-1)
       |
       v
    Agar string ki length 2 hai aur dono char alag hain?
       |---[Yes]---> count = 1, [Break]
       |
      [No]
       |
       v
    Agar i == 0 (pehla char)?
       |---[Yes]---> Agar s[0] != s[1] toh count++
       |
      [No]
       |
       v
    Agar i == n-1 (last char)?
       |---[Yes]---> Agar s[n-1] != s[n-2] toh count++
       |
      [No]
       |
       v
    Agar s[i] != s[i-1] && s[i] != s[i+1] toh count++
       |
       v
    [Loop End]
       |
       v
    count print karo
       |
       v
    [End]

    -----------------------------------------------------------
    Time Complexity:
    - Hum ek hi baar string par loop chala rahe hain (O(n)), 
      toh overall time complexity O(n) hai.
    - Space Complexity: O(1) (kyunki sirf ek count variable use ho raha hai)

    -----------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; 
    getline(cin, s); // User se string input le rahe hain

    int count = 0; // Answer store karne ke liye variable

    for(int i=0; i < s.length(); i++){
        // Agar string ki length 1 hai toh kuch compare nahi kar sakte, break kar do
        if(s.size() == 1) break;

        // Agar string ki length 2 hai aur dono character alag hain toh count 1 set karo aur break karo
        if(s.size() == 2 && s[0] != s[1]){
            count = 1;
            break;
        }

        // Pehla character hai toh sirf agle se compare karo
        if(i == 0) {
            if(s[i] != s[i+1]) count++;
        }
        // Last character hai toh sirf pichle se compare karo
        else if(i == s.length()-1){
            if(s[i] != s[i-1]) count++;
        }
        // Beech ke character hain toh dono neighbours se compare karo
        else if(s[i] != s[i-1] && s[i] != s[i+1]){
            count++;
        }
    }

    cout << count << endl; // Final answer print karo

    return 0;
}