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
string infixToPrefix(string equation){
    string output = "";
    stack<char> s;
    for (int i = equation.length()- 1; i >= 0; i--){
        if(isalpha(equation[i]) || isdigit(equation[i])) 
            output = equation[i] + output;
        else if (equation[i] == ')') 
            s.push(equation[i]);
        else if(equation[i] == '('){
            while(s.top() != ')'){
                output = s.top() + output;
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && (priority(equation[i]) <= priority(s.top()))){
                output = s.top() + output;
                s.pop();
            }
            s.push(equation[i]);
        }
    }
    while(!s.empty()){
        output = s.top() + output;
        s.pop();
    }
    return output;
}
int main(){
    cout<<infixToPrefix("((a+b+c)*d*(e/f)-g)");
    return 0;
}