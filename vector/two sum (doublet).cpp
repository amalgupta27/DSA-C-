#include <iostream>
#include <vector> // Vector library include kiya gaya hai
using namespace std;

int main() {
    int n;
    cout << "enter size of vector: " << endl;
    cin >> n; // User se vector ka size input liya

    int target;
    cout << "Enter Target: " << endl;
    cin >> target; // User se target sum input liya

    cout << "Enter array elements: " << endl; 
    vector<int> v; // Vector declare kiya gaya hai

    // Array ke elements user se input lena
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; // Har element input lo
        v.push_back(x); // Vector me element add karo
    }

    // Do nested loop lagaye gaye hain taaki har pair check kiya ja sake
    for (int i = 0; i <= n - 2; i++) { // First element ke liye loop
        for (int j = i + 1; j <= n - 1; j++) { // Second element ke liye loop
            if (v[i] + v[j] == target) { // Agar dono elements ka sum target ke equal ho
                // Toh pair ka index print karo
                cout << "(" << i << "," << j << ")" << endl;
            }
        }
    }

    return 0; // Program successful end
}
