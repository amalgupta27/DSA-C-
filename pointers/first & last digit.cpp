#include<iostream> // Input-output ke liye header file
using namespace std; // Standard namespace use kiya jaa raha hai

// find function jo first aur last digit find karega
void find(int n, int &fir, int &las){ // n input number hai, fir and las reference variables hain

    las = n % 10; // Last digit nikalne ke liye %10 ka use kiya jaata hai

    while(n > 9){ // Jab tak n 10 se bada hai, tab tak loop chalega
        n /= 10; // Har baar number ko 10 se divide karte jao (last digit hat jaayegi)
    }

    fir = n; // Jab loop khatam hoga, n ke andar first digit bacha hoga
}
int main(){
    int n;
    cout << "Enter a number: "; // User se input maanga
    cin >> n; // User ka input store kiya 'n' mein

    int first, last; // First aur last digit store karne ke liye variables

    find(n, first, last); // Function call kiya jo first aur last digit nikaalega

    cout << "First digit: " << first << endl; // First digit print ki
    cout << "Last digit: " << last << endl; // Last digit print ki

    return 0; // Program successful run hone ke baad return 0 karta hai
}
