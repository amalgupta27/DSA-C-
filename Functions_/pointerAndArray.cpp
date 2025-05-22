#include <bits/stdc++.h>
using namespace std;

int main() {
    // arr naam ka array declare kiya
    int arr[] = {4, 2, 6, 1, 7};

    // Pointer assignment examples:
    // int* ptr = arr;          // correct - array name is base address (decays to pointer)
    // int* ptr = &arr;         // wrong - &arr ka type hai int(*)[5], not int*
    // int* ptr = x;            // wrong - x declare hi nahi hua
    // int* ptr = &x;           // correct sirf tab hota jab x int hota (lekin yaha x nahi hai)
    // int* ptr = &arr[0];      // correct - first element ka address milta hai
    // int* ptr = arr[0];       // wrong - arr[0] ek int hai, pointer nahi

    // correct way to assign pointer to first element
    int* ptr = &arr[0];

    // pointer ka address print karenge (base address of array)
    cout << ptr << endl;

    // ptr ke through first element ko modify kar rahe hain
    ptr[0] = 8; // OR *ptr = 8; dono same kaam karte hain

    // loop se saare elements print karenge using pointer notation (indexing)
    for (int i = 0; i <= 4; i++) {
        cout << ptr[i] << " ";  // pointer arithmetic + indexing
    }

    cout << endl; // ek new line ke liye

    // OR - alternative method using pointer increment
    int* ptr2 = arr; // yaani ptr2 bhi base address ko point karta hai
    for (int i = 0; i <= 4; i++) {
        cout << *ptr2 << " ";  // current element ko print karo
        ptr2++;                // pointer ko next element pe badhao
    }

    return 0;
}
