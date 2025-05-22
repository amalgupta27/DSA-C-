#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n), brr(n);
    
    cout << "Enter elements of brr: ";
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }
    
    // Copy brr to arr and sort arr
    arr = brr;
    sort(arr.begin(), arr.end());
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    bool flag = true;
    
    // Checking if brr elements exist in sorted array within adjacent positions
    for (int i = 0; i < n; i++) {
        if (i == 0) { // First element case
            if (brr[i] != arr[i] && brr[i] != arr[i + 1]) {
                flag = false;
                break;
            }
        } else if (i == n - 1) { // Last element case
            if (brr[i] != arr[i] && brr[i] != arr[i - 1]) {
                flag = false;
                break;
            }
        } else { // Middle elements case
            if (brr[i] != arr[i] && brr[i] != arr[i - 1] && brr[i] != arr[i + 1]) {
                flag = false;
                break;
            }
        }
    }
    
    if (flag) {
        cout << "brr elements follow the order in sorted array." << endl;
    } else {
        cout << "brr elements do not follow the order in sorted array." << endl;
    }
    
    return 0;
}
