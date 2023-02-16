#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool isOperand(char c){
    if(isalpha(c) || isdigit(c))
        return true;
    return false;
}
string postfixToInfix(string equation){
    stack<string> operands;
    for(int i = 0; i < equation.length(); i++){
        if(isOperand(equation[i])){
            string s(1, equation[i]);
            operands.push(s);
        }
        else{
            string o1 = operands.top();
            operands.pop();
            string o2 = operands.top();
            operands.pop();
            operands.push("(" + o2 + equation[i] + o1 + ")");
        }
    }
    return operands.top();
}
int main(){
    cout<<"Enter the postfix expression: "<<endl;
    string s;
    cin>>s;
    cout<<"The infix of the given postfix equation is: " <<postfixToInfix(s);
    return 0;
}