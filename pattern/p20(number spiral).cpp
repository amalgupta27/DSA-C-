#include<iostream>
using namespace std;

/*
===========================
🧠 LOGIC IN HINGLISH:

- 2n-1 rows aur columns ka pattern hai.
- Har cell par:
    - a = row number (i)
    - b = column number (j)
    - Agar a>n toh a=2n-i (mirror effect)
    - Agar b>n toh b=2n-j (mirror effect)
    - x = min(a,b) (nearest distance)
    - Print n-x+1 (value based on closeness to center)
    
Example for n=4:

4444444
4333334
4322234
4321234
4322234
4333334
4444444

===========================
*/
int main(){
    int n;
    cout<<"Enter a positive integer: ";  // User se ek positive number le lo
    cin>>n; // Input lena

    // Outer loop (rows ke liye) → 1 se 2n-1 tak chalega
    for(int i=1; i<=2*n-1; i++){  

        // Inner loop (columns ke liye) → 1 se 2n-1 tak chalega
        for(int j=1; j<=2*n-1; j++){

            // 'a' mein row number store kar rahe hain
            int a = i;  
            // 'b' mein column number store kar rahe hain
            int b = j;  

            // Agar row number n se bada hai, toh mirror kar dena
            // Jaise 5th row actually 3rd row ke mirror jaisa hogi agar n=4
            if(a > n) a = 2*n - i;  

            // Agar column number n se bada hai, toh mirror kar dena
            // Jaise 6th column ko hum 2nd column jaise treat karenge
            if(b > n) b = 2*n - j;  

            // 'x' mein minimum value store karte hain (row aur column ka)
            // Yeh minimum distance bataata hai center se
            int x = min(a, b);  

            // Ab hum value print karte hain
            // Formula: jitna door center se utna chhota number
            // n-x+1 ka matlab: 
            //   - jab x=1 ho (sabse pass), toh print n
            //   - jab x=2 ho, print n-1
            //   - aur aise hi kam hota jayega
            cout << (n - x + 1); 
        }

        cout << endl; // Jab ek poori row print ho jaaye, toh newline de do
    }

    return 0; // Program successful khatam
}
