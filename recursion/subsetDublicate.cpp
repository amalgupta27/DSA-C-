#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Function to store subsets while avoiding duplicate subsets
void storeSubset(string ans, string original, vector<string>& v, bool flag) {
    // Base case: If the original string is empty, store the subset and return
    if (original == "") {
        v.push_back(ans);  // Store the generated subset in the vector
        return;
    }
    // Extract the first character from the original string
    char ch = original[0];
    // Recursive call: Exclude the current character
    if (flag == true) 
        storeSubset(ans, original.substr(1), v, true);
    // Recursive call: Include the current character
    storeSubset(ans + ch, original.substr(1), v, true);
    // Check if there is a next character and if it's the same as the current one
    if (original.length() > 1) {
        char dh = original[1];  // Second character in the original string
        if (ch == dh) {
            // If the current character is the same as the next, restrict the flag to avoid duplicate subsets
            if (flag == true) 
                storeSubset(ans, original.substr(1), v, true);
            storeSubset(ans + ch, original.substr(1), v, false);
        }
    } 
}
int main() {
    string str = "aab";  // Input string
    vector<string> v;  // Vector to store subsets
    storeSubset("", str, v, true);  // Generate subsets
    // Print all the generated subsets
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    return 0;
}

/*
==========================================
Example Walkthrough for "aab":
==========================================
1. Initial Call: storeSubset("", "aab", v, true)

2. Recursive Expansion:
    - Exclude 'a': storeSubset("", "ab", v, true)
    - Include 'a': storeSubset("a", "ab", v, true)

3. Expanding "ab":
    - Exclude 'a': storeSubset("", "b", v, true)
    - Include 'a': storeSubset("a", "b", v, true)

4. Expanding "b":
    - Exclude 'b': storeSubset("", "", v, true) → ""
    - Include 'b': storeSubset("b", "", v, true) → "b"

5. Expanding "aa" case:
    - Exclude first 'a': storeSubset("", "ab", v, true)
    - Include first 'a': storeSubset("a", "ab", v, false)  // `false` prevents duplicate handling

==========================================
Expected Output:
==========================================
(empty)
b
a
ab
a
ab
aa
aab
*/
