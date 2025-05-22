#include <iostream>
using namespace std;

// printArray function: yaha hum array ko print karenge
// Parameters:
// a[]: ye original array ka pointer hai (array name jo pointer me decay hua hai)
// size: array ka size batata hai
// NOTE: Array ko function me pass karne ka matlab hota hai reference pass karna
// Matlab function ke andar changes original array me reflect honge  
void printArray(int a[], int size) {
    // loop 0 se size-1 tak
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";  // array element print karo
    }
    cout << endl;
}

// change function: yaha hum array ke first element ko modify karte hain
// Parameters:
// b[]: ye bhi array ka pointer hai, jise hum modify kar sakte hain
// Ye bhi reference ke through pass hua hai
void change(int b[]) {
    b[0] = 100;  // array ke first element ko 100 se replace karo
}

int main() {
    // arr naam ka array declare kiya
    int arr[] = {1, 2, 3, 4, 5};
    // size calculate karne ke liye total bytes / ek element ke bytes
    int size = sizeof(arr) / sizeof(arr[0]);

    // printArray call: array ko pass kar rahe hain
    // yahan arr as a pointer function ko milta hai
    printArray(arr, size);

    // change call: array ka pointer pass hua hai
    // Array reference ke through pass hua hai, isiliye original array me change hoga
    change(arr);

    cout << endl;

    // dobara print karke dekhte hain ke change hua ya nahi
    printArray(arr, size);

    return 0;
}