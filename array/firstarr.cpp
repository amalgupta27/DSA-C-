#include<iostream>  // Input-Output stream ka header file include kiya gaya hai
using namespace std; // Standard namespace use kar rahe hain

int main() {
    int marks[5] = {2, 3, 4, 5, 6}; // Ek array declare kiya gaya hai jisme 5 students ke marks hain

    // User se 5 students ke marks input lene ke liye loop
    for(int i = 0; i < 5; i++) {
        cin >> marks[i]; // Har student ke marks input kar rahe hain
    }

    // Ab un students ke index print karenge jinke marks 35 se kam hain
    for(int i = 0; i < 5; i++) {
        if(marks[i] < 35) {  // Agar marks 35 se kam hain
           cout << i << " "; // To us student ka index print karo
        }
    }
}
