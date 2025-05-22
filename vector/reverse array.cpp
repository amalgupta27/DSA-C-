#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Step 1: Original vector banate hain
    vector<int> v = {1, 2, 3, 4, 5, 6};

    // Step 2: Reverse vector ka size v ke barabar lete hain
    vector<int> rv(v.size());

    // Step 3: Reverse logic lagate hain
    // Loop j 0 se v.size()-1 tak chalayenge
    for (int j = 0; j <= v.size() - 1; j++) {

        // Formula: j + k = size - 1
        // To k = size - 1 - j
        int k = v.size() - 1 - j;

        // rv ke j-th position par v ke k-th value assign karte hain
        rv[j] = v[k];

        // Step 4: Output print karte hain
        cout << rv[j] << " ";
    }

    return 0;
}
 