#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int item){
    if(s.empty()){
        s.push(item);
        return;
    }
    int top = s.top();
    s.pop();
    insertAtBottom(s, item);
    s.push(top);
}

void reverseStack(stack<int> &s){
    if(s.empty()) return;
    int item = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, item);
}

void displayStack(stack<int> s){
    cout<<endl;
    stack<int> temp = s;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;
    for(int i = 1; i < 6; i++) s.push(i);
    cout<<"The original stack is: ";
    displayStack(s);
    reverseStack(s);
    cout<<"The reversed stack is: ";
    displayStack(s);
    return 0;
}