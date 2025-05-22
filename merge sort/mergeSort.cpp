#include <iostream>  // Header file for input/output operations
#include <vector>    // Header file for using vectors (dynamic arrays)
using namespace std; // Standard namespace to avoid using std:: before functions
// Function to merge two sorted subarrays into a single sorted array
void merge(vector<int>& a, vector<int>& b, vector<int>& res) {
    int i = 0, j = 0, k = 0;  // Pointers for arrays a, b, and res
    int n1 = a.size(), n2 = b.size();
    res.resize(n1 + n2);  // Resize the result array to hold all elements from a and b
    // Merge elements from 'a' and 'b' in sorted order
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {  // If the current element of 'a' is smaller, add it to res
            res[k++] = a[i++];
        } else {  // Otherwise, add the current element of 'b' to res
            res[k++] = b[j++];
        }
    }
    // Copy remaining elements from 'a' if there are any
    while (i < n1) {
        res[k++] = a[i++];
    }
    // Copy remaining elements from 'b' if there are any
    while (j < n2) {
        res[k++] = b[j++];
    }
    // Example:
    // a = [1, 4, 6], b = [2, 3, 5]
    // Merge step-by-step: [1] -> [1,2] -> [1,2,3] -> [1,2,3,4] -> [1,2,3,4,5] -> [1,2,3,4,5,6]
}
// Recursive function to implement Merge Sort
void mergeSort(vector<int>& v) {
    int n = v.size();  // Get the size of the input array
    // Base case: If the array has only 1 or 0 elements, it's already sorted
    if (n <= 1) return;
    int n1 = n / 2;       // Size of the first half
    int n2 = n - n / 2;   // Size of the second half
    vector<int> a(n1), b(n2); // Temporary vectors for left and right halves
    // Copy first half of 'v' into 'a'
    for (int i = 0; i < n1; i++) {
        a[i] = v[i];
    }
    // Copy second half of 'v' into 'b'
    for (int i = 0; i < n2; i++) {
        b[i] = v[i + n1];
    }
    // Recursive calls to sort both halves
    mergeSort(a);  // Sort left half
    mergeSort(b);  // Sort right half
    // Merge the two sorted halves back into 'v'
    merge(a, b, v);
     // Clear vectors 'a' and 'b' to free memory
    a.clear(); // Clears the elements of vector 'a' to free up memory after merging
    b.clear(); // Clears the elements of vector 'b' to free up memory after merging
    // Example:
    // v = [5, 1, 3, 0, 4, 9, 6]
    // Divide into: [5, 1, 3] and [0, 4, 9, 6]
    // Sort [5, 1, 3] -> becomes [1, 3, 5]
    // Sort [0, 4, 9, 6] -> becomes [0, 4, 6, 9]
    // Merge [1, 3, 5] and [0, 4, 6, 9] -> final sorted array [0, 1, 3, 4, 5, 6, 9]
}
// Main function: Entry point of the program
int main() {
    int arr[] = {5, 1, 3, 0, 4, 9, 6};  // Unsorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    vector<int> v(arr, arr + n); // Convert the array to a vector
    // Call merge sort function to sort the vector
    mergeSort(v);
    // Print the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl; // Move to the next line after printing the array
    return 0;  // Indicate successful program execution
}
