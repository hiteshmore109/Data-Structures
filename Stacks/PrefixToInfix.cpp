#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool isOperand(char c){
    if(isalpha(c) || isdigit(c)) return true;
    return false;
}
string prefixToInfix(string equation){
    stack<string> operands;
    for(int i = equation.length() -1; i >= 0; i--){
        if(isOperand(equation[i])){
            string s(1, equation[i]);
            operands.push(s);
        }
        else{
            string c1 = operands.top();
            operands.pop();
            string c2 = operands.top();
            operands.pop();
            operands.push(")" + c2 + equation[i] + c1 + "(");
        }
    }
    string output = operands.top();
    reverse(output.begin(), output.end());
    return output;
}
int main(){
    string s;
    cout<<"Enter the prefix string: ";
    cin>>s;
    cout<<"The entered prefix string is: "<<s<<endl;
    cout<<"the corresponding infix string is: "<<prefixToInfix(s);
    return 0;
}