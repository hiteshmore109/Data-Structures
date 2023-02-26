/*C++ program to demonstrate the implementation of stacks using arrays*/
#include<iostream>
using namespace std;
class Stack{
    int size, n = -1, *stackarr;
    public:
    Stack(){}
    Stack(int size){
        this -> size = size;
        stackarr = new int[size];
    }
    //to check whether the stack is full
    bool isFull(){
        return (n == size - 1);
    }
    //to check if the stack is empty
    bool isEmpty(){
        return (n == -1);
    }
    //to find out the topmost element in the stack
    int top(){
        return stackarr[n];
    }
    //to insert a data in stack
    void push(int data){
        if(isFull()){
            cout<<"Stack Overflow \nCannot Push element "<<data<<"\n";
            return;
        }
        n++;
        stackarr[n] = data;
    }
    //to remove the top element from the stack
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow";
            return;
        } 
        n--;
    }
    //to print the stack
    void display(){
        cout<<endl;
        for(int i = n; i >= 0; i--) cout<<stackarr[i]<<" ";
        cout<<endl;
    }
};
int main(){
    int data, choice, size;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    Stack s(size);
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
            s.push(data);
            break;
        case 2:
            cout<<"The popped element is: "<<s.top();
            s.pop();
            break;
        case 3:
            data = s.top();
            cout<<"The topmost element in the stack is: "<<data;
            break;
        case 4:
            cout<<"The stack elements are: ";
            s.display();
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