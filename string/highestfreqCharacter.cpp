
    // string s;
    // getline(cin , s);
    // int max=0;
    // int mx=max;
    // for(int i=0; i<s.length();i++){
    //     int count=1;
    //     for(int j=i+1; j<s.length();j++){
    //         if(s[i]==s[j]) count++;
    //     }
    //     if(max<count) max=count;
    // }
    // for(int i=0; i<s.length();i++){
    //     char ch= s[i];
    //     int count=1;
    //     for(int j=i+1; j<s.length();j++){
    //         if(s[i]==s[j]) count++;
    //     }
    //     if(count==max) {
    //         cout<<ch<<" "<<max<<endl;
    //     }
    // }
       //OR

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
🧠 LOGIC (Hinglish me):

👉 Problem:
Ek string diya gaya hai. Humein usme se sabse zyada baar aane wala character (small letters me) find karna hai.

👉 Simple Steps:
1. String input lo.
2. Har character ki frequency count karo (a-z).
3. Jo character sabse zyada baar aaya ho, usko print karo.

💡 Example:
Input:  "apple"
'a' - 1 baar
'p' - 2 baar
'l' - 1 baar
'e' - 1 baar
Output: 'p' 2

📈 Flowchart (Hinglish):

START
  ↓
String input lo
  ↓
Empty array banao (size 26) → arr[26] = {0}
  ↓
Har character ko loop me pakdo
  ↓
Char ka ASCII find karo → arr[ascii - 97]++
  ↓
Maximum frequency find karo
  ↓
Us frequency wale character ko print karo
  ↓
END
*/

int main() {
    string s;
    getline(cin, s); // 🔹 User se ek line ka input lena

    vector<int> arr(26, 0); // 🔹 26 size ka vector banaya, jisme sab values 0 hai (a to z)

    // 🔹 Loop through each character in the string
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i]; // 🔸 Har character ko uthao

        // 🔹 Agar character lowercase letter hai (a to z)
        if(ch >= 'a' && ch <= 'z') {
            int ascii = (int)ch; // ASCII value nikaalo
            arr[ascii - 97]++;   // 'a' ka index 0, 'b' ka 1,... so ascii - 97
            //'a' ka ASCII hota hai 97, aur hum -97 karte hain taaki 'a' ka count arr[0] me store ho.
            //Ye technique 0-based index ke through a-z ke har character ka count store karne me help karti hai.
            //Har character jab milega, to uska corresponding index pe ++ kar denge.
        }

        // 🔹 Agar uppercase letter ho to usse lowercase me convert karo
        else if(ch >= 'A' && ch <= 'Z') {
            int ascii = (int)ch + 32; // Uppercase to lowercase conversion
            arr[ascii - 97]++;
        }
    }

    // 🔹 Maximum frequency find karna
    int max = 0;
    for(int i = 0; i < 26; i++) {
        if(max < arr[i]) max = arr[i]; // Max frequency update
    }

    // 🔹 Ab us character ko dhoondo jiska freq max ho
    for(int i = 0; i < 26; i++) {
        if(arr[i] == max) {
            char ch = i + 97; // ASCII se wapas character banana
            cout << "Most frequent character is: " << ch << " → " << max << " times" << endl;
        }
    }

    return 0;
}
