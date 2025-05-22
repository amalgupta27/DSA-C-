#include<iostream>          // Input-output operations ke liye header file
#include<bits/stdc++.h>     // Sabhi standard libraries include karta hai (optional)
using namespace std;        // Standard namespace use kiya

int main(){
    int n;  // Array ka size store karne ke liye variable

    cout << "Enter the size of array: ";  // User ko prompt dena for array size
    cin >> n;  // User se size input lena

    int arr[n];  // User-defined size ka array banaya

    // Array ke elements user se input lene ke liye loop
    for(int i = 0; i <= n - 1; i++){
        cin >> arr[i];  // Har element ka input le rahe hain
    }

    int x;  // Jis number ko search karna hai, uske liye variable

    cout << "Enter the no. to search for: ";  // User ko batana ki number input karo
    cin >> x;  // Search karne wala number input le rahe hain

    bool found = false;  // Initially maan ke chalte hain ki number nahi mila

    // Array ke andar number search karne ke liye loop
    for(int i = 0; i <= n - 1; i++){
        if(arr[i] == x){      // Agar current element x ke barabar hai
            found = true;     // Toh number mil gaya
            break;            // Ab aur check karne ki zarurat nahi, loop se bahar niklo
        }
    }

    // Ab check karte hain ki number mila ya nahi
    if(found == true) 
        cout << x << " found in the array." << endl;   // Agar mila toh ye message
    else 
        cout << x << " not found in the array." << endl; // Agar nahi mila toh ye message

    return 0; // Program successful run hua
}
