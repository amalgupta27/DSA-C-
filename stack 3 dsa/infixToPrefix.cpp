#include<iostream>
#include<stack>
#include<string>
using namespace std;
int priority(char oper){
    if(oper=='+' || oper=='-') return 1;
    else if(oper=='*' || oper=='/') return 2;
    else return 0; // for invalid operator
}
string solve(string v1, string v2, char oper){
    // prefix is -> op v1 v2
    string s ="";
    s.push_back(oper); // operator
    s += v1; // first operand
    s += v2; // second operand
    return s; // return the result
}
int main(){
    string s = "1+(2+6)*4/8-3"; // Example infix expression
    // we need two stacks, 1 for operators and 1 for values
    stack<string> val; // Stack for operands
    stack<char> op; // Stack for operators
    for(int i=0;i<s.length();i++){
        // check if s[i] is a digit (0-9)
        int ascii  = (int)(s[i]);
        if(ascii>=48 && ascii<=57){
            // convert char to int and push to val stack
            val.push(to_string(ascii-48));
        }
        else{
            // s[i] it is -> *,/,+,-
            if(op.size()==0) op.push(s[i]);
            else if(s[i]=='(' || op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                // pop from both stacks and evaluate
                while(op.top()!='('){
                    char oper = op.top(); op.pop();
                    string v2 = val.top(); val.pop();
                    string v1 = val.top(); val.pop();
                    string result = solve(v1,v2,oper);
                    val.push(result);
                }
                op.pop(); // pop the '('
            }
            else if(priority(s[i])>priority(op.top())) op.push(s[i]);
            else{
                // check if the priority(s[i])<=priority(op.top())
                while(op.size()>0 && priority(s[i])<=priority(op.top())){
                    // pop from both stacks and evaluate
                    char oper = op.top(); op.pop();
                    string v2 = val.top(); val.pop();
                    string v1 = val.top(); val.pop();
                    string result = solve(v1,v2,oper);
                    val.push(result);
                }
                op.push(s[i]); // push the current operator
            }
        }
    }
   // the operator stack can have values
    while(op.size()>0){
        //work
        char oper = op.top(); op.pop();
        string v2 = val.top(); val.pop();
        string v1 = val.top(); val.pop();
        string result = solve(v1,v2,oper);
        val.push(result);
    }
    cout<<val.top()<<endl; // final result
    return 0;
} 