#include <iostream>          // Input aur Output ke liye header file include kar rahe hain
using namespace std;         // Standard namespace ka use kar rahe hain (cout, cin ke liye)

int main() {
    int num, originalNum, reversedNum = 0, digit;  // Variables declare kiye: number, original number, reversed number aur digit ke liye

    // User se number input lene ke liye prompt
    cout << "Enter a number: ";
    cin >> num;  // User se number input liya

    originalNum = num;  // Original number ko ek variable mein store kiya, taaki baad mein compare kar sakein

    // Number ko reverse karne ka process start
    while (num > 0) {
        digit = num % 10;  // Last digit nikaal rahe hain (remainder nikal ke)
        reversedNum = reversedNum * 10 + digit;  // Reversed number bana rahe hain
        num = num / 10;  // Last digit hata rahe hain (number ko chhota kar rahe hain)
    }

    // Check kar rahe hain ki original number aur reversed number same hain ya nahi
    if (originalNum == reversedNum) {
        cout << "It is a palindrome number." << endl;  // Agar same hain toh palindrome hai
    } else {
        cout << "It is not a palindrome number." << endl;  // Nahi toh palindrome nahi hai
    }

    return 0;  // Program successful end ho gaya
}
