#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(){}
    Node(int data){
        this -> data = data;
        next = NULL;
        prev = NULL;
    }
    Node(int data, Node *next, Node *prev){
        this -> data = data;
        this -> next = next;
        this -> prev = prev;
    }
};
class DoubleLinkedList{
    Node *head;
    public:
    DoubleLinkedList(){head = NULL;}
    void Insertend(int);
    void InsertFront(int);
    void Insertat(int , int);
    void Removeat(int);
    int Length();
    void Display();
};
void DoubleLinkedList :: Insertend(int data){
    Node *newNode = new Node(data), *temp;
    if(head == NULL){
        head = newNode;
        newNode -> prev = NULL;
        newNode -> next = NULL;
        return;
    }
    temp = head;
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> next = newNode;
    newNode -> prev = temp;
    newNode -> next = NULL;
}
void DoubleLinkedList :: InsertFront(int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        newNode -> next = NULL;
        newNode -> prev = NULL;
        return;
    }
    Node *temp = head;
    head = newNode;
    newNode -> next = temp;
    temp -> prev = newNode;
    newNode -> prev = NULL;
}
void DoubleLinkedList::Insertat(int index, int data)
{
    int count = Length();
    Node *newNode = new Node(data);
    if(index > count){
        cout<<"Index out of Bounds";
        return;
    }
    Node *temp = head;
    //this loop start from 2 because 1st element head is already stored in temp and this will run till it reaches an element before the index element(ex if index = 5, then temp will contain 4th element)
    for(int i = 2; i < index; i++)
        temp = temp -> next;
    newNode -> prev = temp;
    newNode -> next = temp -> next;
    temp -> next -> prev = newNode;
    temp -> next = newNode;
}
void DoubleLinkedList::Removeat(int index)
{
    int count = Length();
    if(index > count){
        cout<<"Index out of Bounds";
        return;
    }
    Node *temp = head;
    for(int i = 2; i <= index; i++){
        temp = temp -> next;
    }
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    delete temp;
}
int DoubleLinkedList::Length()
{
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}
void DoubleLinkedList ::Display()
{
    Node *temp = head;
    cout<<endl;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main()
{
    DoubleLinkedList l;
    l.InsertFront(1);
    l.Insertend(2);
    l.InsertFront(-1);
    l.Insertend(3);
    l.Display();
    l.Insertat(2, 0);
    l.Display();
    l.Removeat(2);
    l.Display();
    cout<<endl;
    return 0;
}