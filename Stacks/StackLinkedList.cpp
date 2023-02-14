/*C++ program to demonstrate the implementation of Stacks using single linked list*/
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};
class Stack{
    Node *top;
    public:
    Stack(){ top = NULL; }
    void Push(int);
    int Pop();
    int isEmpty();
    int Peek();
    void print();
};
int Stack :: isEmpty(){
    if(top == NULL)
        return 1;
    return 0;
}
//insert node at front which will result the head element as the top and will result the popping of elements to easy with time Complexity O(1) if not inserted at front time complexity for pop would be O(n) as we have to iterate till the last of the list
void Stack :: Push(int data){
    Node *newNode = new Node(data);
    if(newNode == NULL){
        cout<<"Stack overflow";
        exit(1);
    }
    Node *temp = top;
    top = newNode;
    newNode -> next = temp;
}
int Stack :: Pop(){
    Node *temp = top;
    if(isEmpty()){
        cout<<"Stack Underflow";
        exit(1);
    }
    int val = temp -> data;
    top = top -> next;
    delete temp;
    temp = NULL;
    return val;
}
int Stack :: Peek(){
    if(isEmpty()){
        cout<<"Stack Underflow";
        exit(1);
    }
    return top -> data;
}
void Stack :: print(){
    Node *temp = top;
    cout<<endl;
    if(isEmpty()){
        cout<<"Stack is empty";
        exit(1);
    }
    while(temp){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main(){
    Stack s;
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
            s.Push(data);
            break;
        case 2:
            data = s.Pop();
            cout<<"The popped element is: "<<data;
            break;
        case 3:
            data = s.Peek();
            cout<<"The topmost element in the stack is: "<<data;
            break;
        case 4:
            cout<<"The stack elements are: ";
            s.print();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Invalid choice";
            break;
        }
    }
}