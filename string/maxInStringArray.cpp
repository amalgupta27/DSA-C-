#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Initialize the array of strings
    vector<string> arr = {"0123", "0023", "456", "0024", "0029"};
    int n = arr.size(); // Determine the size of the array

    int max = INT_MIN; // Use a very small initial value for max

    for (int i = 0; i < n; i++) {
        
            // Convert the string to an integer
            int num = stoi(arr[i]);
            // Update max if the current number is greater
            if (num > max) {
                max = num;
            }
        
    }

    cout << "Max is " << max << endl;
    return 0;
}
