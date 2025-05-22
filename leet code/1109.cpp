#include<bits/stdc++.h>
using namespace std;
// 📌 Samasya Ka Bayaan (Hindi)
// Tumhe ek bookings array diya gaya hai jisme har entry [first, last, seats] hai.
// Har entry ka matlab hai ki first se last tak ke flights me seats passengers book kiye gaye hain.
// Tumhe ek n diya gaya hai jo total flights ki sankhya batata hai.
// Tumhe ek aisa array return karna hai jo har flight me booked passengers dikhaye.
//
// 🔹 Samasya ko aur ache se samjhein:
// Har booking ek range [first, last] ke beech hoti hai.
// Hume har flight me passengers ka count efficiently calculate karna hai.
//
// 📌 Udaaharan:
// Input: bookings = [[1,2,10], [2,3,20], [2,5,25]], n = 5
// Output: [10, 55, 45, 25, 25]
//
// 🛠 Tarkika (Difference Array Technique)
// 1️⃣ Ek res array initialize karenge jo har flight ka passengers store karega.
// 2️⃣ Har booking ke liye first-1 index par seats add karenge aur last index par seats subtract karenge.
// 3️⃣ Phir prefix sum lenge taki har flight ka exact passenger count mile.
//
// 📊 Flowchart (Hinglish ASCII Representation)
//
// Start
//   |
//   v
// [Initialize res array with 0]
//   |
//   v
// [Loop over bookings]
//   |
//   |---> res[first-1] += seats (Add passengers at start)
//   |---> res[last] -= seats (Remove passengers after end)
//   |
//   v
// [Calculate Prefix Sum]
//   |
//   v
// [Final passengers count in each flight]
//   |
//   v
// End

class Solution {
    public:
        vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            // 1️⃣ Sabhi flights ke liye ek result array initialize karenge jisme sabhi values 0 hongi.
            vector<int> res(n, 0);
            // Extract booking details: `first`, `last`, `seats`
            //first = bookings[i][0];  // Starting flight
            //last = bookings[i][1];   // Ending flight
            //seats = bookings[i][2];  // Number of seats booked
            // 2️⃣ Har booking ko process karna hai.
            for(int i = 0; i < bookings.size(); i++) {
                // Booking ka start point par passengers add karna hai.
                // bookings[i][0]-1 isliye kiya kyunki indexing 0-based hai.
                res[bookings[i][0] - 1] += bookings[i][2];
                
                // Agar last flight index n se chhota hai to, uske agle index par passengers minus karenge.
                if(bookings[i][1] < n) 
                    res[bookings[i][1]] -= bookings[i][2];
            }
            
            // 3️⃣ Prefix sum calculate karna taki har flight ka exact passengers count mile.
            for(int i = 1; i < n; i++) {
                // Har flight ka passengers count previous flights ka sum lekar update hoga.
                res[i] = res[i] + res[i - 1];
            }
            
            // 4️⃣ Final result return karenge jo har flight ke passengers dikhayega.
            return res;
        }
    };