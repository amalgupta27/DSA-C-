#include<bits/stdc++.h>     // Saari standard libraries include kar leta hai
using namespace std;        // Standard namespace use kar rahe hain

int main(){
    int count = 0;  // Count variable banaya jo batayega kitne elements 'x' se bade hain
    int x = 2;      // Reference value jiske saath comparison karna hai

    int arr[] = {3, 1, 2, 4, 5, 6};  // Ek array initialize kiya

    // Array ka size nikal rahe hain (total elements)
    int n = sizeof(arr) / sizeof(arr[0]);  // Total bytes / ek element ka size = total elements

    // Loop chalayenge array ke har element ke liye
    for(int i = 0; i < n; i++){
        if(arr[i] > x)   // Agar current element 'x' se bada hai
            count++;     // Toh count ko 1 se badha do
    }

    // Finally, count print kar rahe hain
    cout << count << endl;  // Output: x se bade elements kitne hain
}
