#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int priority(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}
string InfixToPostfix(string equation){
    string output = "";
    stack<char> s;
    for(int i = 0; i < equation.length(); i++){
        if(isalpha(equation[i]))
            output += equation[i];
        else if(equation[i] == '(')
            s.push(equation[i]);
        else if(equation[i] == ')'){
            while(s.top() != '('){
                output += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && (priority(equation[i]) <= priority(s.top()))){
                output += s.top();
                s.pop();
            }
            s.push(equation[i]);
        }
    }
    
    while(!s.empty()){
        output += s.top();
        s.pop();
    }
    return output;
}
int main(){
    string infix;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    cout<<"The postfix expression for given infix expression is: "<<InfixToPostfix(infix);
    return 0;
}