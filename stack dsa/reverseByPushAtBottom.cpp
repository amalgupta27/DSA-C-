#include<iostream>
#include<stack>
using namespace std;
void displayRevRec(stack<int>&st ){
    if(st.size()==0) return;
    int x =st.top();
    cout<<x<<" ";
    st.pop(); 
    displayRevRec(st);
    st.push(x);
}

void pushatbottomRec(stack<int>&st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x =st.top();
    st.pop();   
    pushatbottomRec(st,val);
    st.push(x);
}
void reverse(stack<int> &st){
    if(st.size()==1) return;
    int x= st.top();
    st.pop();
    reverse(st);
    pushatbottomRec(st,x);
    
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30); 
    st.push(40);
    st.push(50);
    displayRevRec(st);
    cout<<endl;
    reverse(st);
    displayRevRec(st);
}
