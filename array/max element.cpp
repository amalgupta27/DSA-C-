#include<iostream>          // Input-output operations ke liye header file
#include<climits>
#include<bits/stdc++.h>     // Sabhi standard libraries include karta hai (optional)
using namespace std;        // Standard namespace use kar rahe hain

int main(){
    int n;  // Array ka size store karne ke liye variable

    cout << "Enter the size of array: ";  // User ko bataya ja raha hai ki size enter karo
    cin >> n;  // User se array ka size liya

    int arr[n];  // Array banaya with size 'n'

    // Array ke elements input lene ke liye loop
    for(int i = 0; i <= n - 1; i++){
        cin >> arr[i];  // Har element ko user se input le rahe hain
    }

    int max = arr[0];//OR max=INT_MIN  // Sabse pehle element ko hi maximum maan lete hain

    // Loop chalayenge 1 se lekar n-1 tak to compare with max
    for(int i = 1; i <= n - 1; i++){
        if(max < arr[i]){     // Agar current element max se bada hai
            max = arr[i];     // To usse naya max bana do
        }
    }

    // Final maximum element print karenge
    cout << "Largest element in the array: " << max << endl;

}
