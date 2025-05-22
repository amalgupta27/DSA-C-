#include<iostream> // Input Output stream ke liye
using namespace std;

// 🔹 Ek function define kar rahe hain jiska naam 'fun' hai
// Ye function do integers leta hai (x aur y) as parameters
void fun(int x, int y) {
    // Function ke andar x aur y ke addresses print kar rahe hain
    cout << &x << " " << &y << endl;
}

int main() {
    // 🔹 Main function start
    
    int x = 3; // Ek integer variable x banaya aur usme 3 store kiya
    int y = 5; // Ek integer variable y banaya aur usme 5 store kiya

    // 🔹 Pehle main function ke andar x aur y ke addresses print karenge
    cout << &x << " " << &y << endl;

    // 🔹 Ab fun(x, y) call karenge
    fun(x, y);

    // 🔹 Program end
}
