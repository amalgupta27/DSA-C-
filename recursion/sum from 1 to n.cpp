#include<iostream>
using namespace std;
//[Return Type Method]
// Function to calculate the sum of first 'n' natural numbers using recursion 
int sum(int n) {  
    if (n == 0) return 0; // Base case: If 'n' is 0, return 0 (stopping condition)
    
    return n + sum(n - 1); // Recursive case: Add 'n' to the sum of (n-1)
}  

// Main function where execution starts
int main() {  
    int n; // Variable to store user input  

    cout << "Enter a number: "; // Ask the user to enter a number  
    cin >> n; // Read user input and store it in 'n'  

    cout << sum(n); // Call the recursive function and print the sum  

    return 0;   
}


//OR
//[Parameterised Method]
// void sum1toN(int sum, int n){
//     if(n==0) {
//         cout<<"Sum of 1 to "<<n<<" is: "<<sum<<endl;
//         return ;  // base case 1 to n = n  (n=0)  or 1 to 0 = 0  (n=1)  or 1 to 1 = 1  (n=2)  or 1 to 2 = 3  (n=3)  or 1 to 3 = 6  (n=4)  or 1 to 4 = 10  (n=5)  and so on...  or 1 to n = n*(n+1)/2  (n=10)  or 1 to n = n*(n+1)*(2n+1)/6  (n=20)  or 1 to n = n*(n+1)*(n+2)/6  (n=30)  or 1 to
//     }
//     sum1toN(sum+n,n-1);
     
// }
// int main(){
//     int n;
//     cout<<"Enter a number: ";
//     cin >> n;
//     sum1toN(0,n);
//     return 0; 
// }