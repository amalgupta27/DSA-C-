#include<iostream>          // Input-output ke liye header file
#include<bits/stdc++.h>     // Sabhi standard libraries include karta hai (optional)
using namespace std;        // Standard namespace use kar rahe hain

int main(){
    int n;  // Array ka size store karne ke liye variable

    cout << "Enter the size of array: ";  // User ko prompt diya
    cin >> n;  // Array ka size input liya

    int arr[n];  // Array banaya with size 'n'
    
    int secLar = arr[0];  // Second largest ke liye ek variable banaya (lekin abhi isme garbage value hogi, kyunki input abhi nahi liya)

    // Array ke elements user se input lene ke liye loop
    for(int i = 0; i <= n - 1; i++){
        cin >> arr[i];  // Har element input kiya
    }

    int max = arr[0];  // Pehle element ko maximum maan liya

    // Sabse bada element (max) nikalne ke liye loop
    for(int i = 1; i <= n - 1; i++){
        if(max < arr[i]){     // Agar current element max se bada hai
            max = arr[i];     // To naya max ban jaata hai
        }
    }

    // Second largest nikalne ke liye loop
    for(int i = 1; i <= n - 1; i++){
        if(secLar < arr[i] && arr[i] != max){  // Agar current element max se chhota ho aur secLar se bada ho
            secLar = arr[i];                   // To second largest update ho jaata hai
        }
    }

    // Output: second largest element
    cout << "Second Largest element in the array: " << secLar << endl;
}
