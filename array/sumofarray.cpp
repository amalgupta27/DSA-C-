#include<iostream>          // Input-output ke liye header file include ki gayi hai
#include<bits/stdc++.h>     // Saari standard libraries include kar leta hai (optional but commonly used)
using namespace std;        // Standard namespace use kar rahe hain

int main(){
    int n;  // Array ka size store karne ke liye variable declare kiya

    cout << "Enter the size of array: "; // User se array ka size lene ka prompt
    cin >> n;  // User se size input liya

    int arr[n];  // Itna size ka array banaya
    int sum = 0; // Sum calculate karne ke liye variable 0 se initialize kiya

    // User se array ke elements input lene ke liye loop
    for(int i = 0; i <= n - 1; i++){
        cin >> arr[i];  // Array ke har element ka input le rahe hain
    }

    // Array ke elements ka sum nikalne ke liye loop
    for(int i = 0; i <= n - 1; i++){
        sum = sum + arr[i];  // Har element ko sum me jodte ja rahe hain
    }

    // Final sum print kar rahe hain
    cout << "sum of elements of given array: " << sum << endl;
}
