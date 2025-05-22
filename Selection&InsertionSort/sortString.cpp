#include <iostream>  // For input-output operations
#include <string>    // For using string datatype
#include <algorithm> // For sort function

using namespace std;

int main() {
    // Declaring an array of strings (names)
    string arr[] = {"urvi", "harsh", "hyder", "vikash", "amal", "raghav"};
    
    // Calculating the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Printing the original array before sorting
    cout << "Original Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    cout << endl;

    // Sorting the array in lexicographical (dictionary) order
    sort(arr, arr + n);

    // Printing the sorted array
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
