#include<iostream> // input-output stream header include kiya
#include<vector>   // vector header include kiya
using namespace std;

int main(){
    vector<int> v; // ek vector v declare kiya

    // vector me kuch values insert kiya using push_back()
    v.push_back(9);
    v.push_back(10);
    v.push_back(6);
    v.push_back(12);
    v.push_back(11);
    v.push_back(6);
    v.push_back(0);

    int x = 11; // jis value ko dhoondhna hai, usko x me store kiya
    int idx = -1; // agar x nahi mila to default index -1 rahega

    // forward loop (commented hai, isliye ye run nahi hoga)
    // for(int i=0;i<v.size(); i++){
    //     if(v[i] == x) idx = i;
    // }

    // backward loop se search kar rahe hain
    for(int i=v.size()-1;i>=0; i--){ // loop last element se start hoga
        if(v[i] == x) {              // agar current element x ke barabar hai
            idx = i;                // to uska index idx me store kar lo
            break;                  // aur loop se bahar aa jao (pehla match piche se mila)
        }
    }

    cout << idx; // index print karo jahan x mila, agar nahi mila to -1 print hoga
}
