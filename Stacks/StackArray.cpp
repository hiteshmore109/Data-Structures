/*C++ program to demonstrate the implementation of stacks using arrays*/
#include<iostream>
//to give a constant size to the array
#define Max 4
using namespace std;
//since stack and top are the variables to be accessed in every function hence declared globally and top is having an invalid array index indicating stack is empty
int stack[Max], top = -1;
//to check whether the stack is full
int isFull(){
    if(top == Max - 1)
        return 1;
    return 0;
}
//to check if the stack is empty
int isEmpty(){
    if(top == -1)
        return 1;
    return 0;
}
//to find out the topmost element in the stack
int peek(){
    if(isEmpty()){
        cout<<"\nStack Underflow";
        exit(1);
    }
    return stack[top];
}
//to insert a data in stack
void push(int data){
    if(isFull()){
        cout<<"Stack Overflow";
        return;
    }
    top++;
    stack[top] = data;
}
//to remove the peek element from the stack
int pop(){
    int value;
    if(isEmpty()){
        cout<<"Stack Underflow";
        exit(1);
    }
    value = stack[top];
    top--;
    return value;
}
//to print the stack
void print(){
    cout<<"\n";
    if(top == -1){
        cout<<"Stack underflow";
        return;
    }
    for(int i = top; i >= 0; i--)
        cout<<stack[i]<<" ";
    cout<<"\n";
}
int main(){
    int data, choice;
    while(1){
        cout<<"\nEnter the choice to perform the stack operations:\n\
                \t1.Push\n\
                \t2.Pop\n\
                \t3.Peek\n\
                \t4.print\n\
                \t5.Exit\n";
        cin>>choice;
        switch (choice){
        case 1:
            cout<<"Enter the element to be pushed";
            cin>>data;
            push(data);
            break;
        case 2:
            data = pop();
            cout<<"The popped element is: "<<data;
            break;
        case 3:
            data = peek();
            cout<<"The topmost element in the stack is: "<<data;
            break;
        case 4:
            cout<<"The stack elements are: ";
            print();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Invalid choice";
            break;
        }
    }
    return 0;
}