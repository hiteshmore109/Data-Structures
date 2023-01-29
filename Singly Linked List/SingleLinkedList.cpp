/*C++ program to demonstrate the operations that can be performed on a singly linked list*/
#include<iostream>
using namespace std;
//creating Node
class Node{
    public:
    //data in the node
    int data;
    //next pointer of the node
    Node *next;
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};
//class where functions of single linked list are declared
class SingleLinkedList{
    //pointer pointing to the first element of the node
    Node *head;
    public:
    //initialize with head pointer pointing to null.. If not initialized to NULL then first element will be stores 0 at object instantiation
    SingleLinkedList(){head = NULL;}
    //to insert element at end
    void insert(int);
    //to insert element at front
    void insertfront(int);
    //to insert element at specific index
    void insertat(int, int);
    //to remove an element at a specific index
    void RemoveAt(int);
    //to display the elements of the linked list
    void display();
    //to count the number of elements in the list
    int length();
    //to reverse the list
    SingleLinkedList reverse();
};
int SingleLinkedList :: length(){
    Node *temp = head;
    int count = 0;
    //counting the number of nodes in the list
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}
SingleLinkedList SingleLinkedList::reverse()
{
    //creates a new list
    SingleLinkedList newlist;
    Node *temp = head;
    while (temp != NULL) {
        //will insert the data in the front of newlist ie., starting from the first element the it will keep adding the data to the front resulting the last element of the original list to be the first in newlist
        newlist.insertfront(temp->data);
        temp = temp->next;
    }
    return newlist;
}
void SingleLinkedList ::insert(int data)
{
    //create a new node with the element as data
    Node *newNode = new Node(data);
    //check if the linked list is empty or not... if empty then change the head pointer to new node
    if(head == NULL){
        head = newNode;
        return;
    }
    //temporary pointer to traverse throughout the list as head being storing the value of first node cant' be use directly
    Node *temp = head;
    //traversing till the last element to add element at last position of the list and storing the last element address in temp
    while(temp -> next != NULL)
        temp = temp -> next;
    //last element of list will now point to new node created
    temp -> next = newNode;
    //setting next pointer of new node to null
    newNode -> next = NULL;
}
void SingleLinkedList :: insertfront(int data){
    //create a new node with the element as data
    Node *newNode = new Node(data);
    Node *temp = head;//used to store the first element of the node
    //check if the linked list is empty or not... if empty then change the head pointer to new node
    if(temp == NULL){
        head = newNode;
        head -> next = NULL;
        return;
    }
    //if linked list is not empty then change the head pointer to new node and new node next to previous first node of the list which is store in temp variable
    head = newNode;
    newNode -> next = temp;
}
void SingleLinkedList :: insertat(int index, int data){
    //create a new node with the element as data, "temp" to store the node at given index and "temp1" to store address of previous node
    Node *newNode = new Node(data), *temp = head, *temp1;
    //if the index given by user is larger than the length of list then stop further steps
    if(length() <= index){
        cout<<"\n Index out of range";
        return;
    }
    //if index is one then use insertfront method
    if(index == 0){
        insertfront(data);
        return;
    }
    //find the node at given index and store it in temp and its previous node in temp1
    for(int i = 0; i < index; i++){
        temp1 = temp;
        temp = temp -> next;
    }
    //link the index-1 node to new node
    temp1 -> next = newNode;
    //link the previous index node to current index node
    newNode -> next = temp;
}
void SingleLinkedList :: RemoveAt(int index){
    Node *temp = head, *temp1;
    //if the index given by user is larger than the length of list then stop further steps
    if(length() <= index){
        cout<<"\n Index out of range";
        return;
    }
    //find the node at given index and store it in temp and its previous node in temp1
    for(int i = 0; i < index; i++){
        temp1 = temp;
        temp = temp -> next;
    }
    //link the previous node with the next node of "index" node
    temp1 -> next = temp -> next;
    //delete the index node of unupdated list
    delete temp;
}
void SingleLinkedList :: display(){
    cout<<endl;
    Node *temp = head;
    //traversing through the list and displaying the data present in each node
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main(){
    SingleLinkedList l;
    //l = [0]
    l.insertfront(0);
    //l = [0, 1]
    l.insert(1);
    //l =[0, 1, 3]
    l.insert(3);
    // l = [-1, 0, 1, 3]
    l.insertfront(-1);
    // l = [-1, 0, 1, 2, 3]
    l.insertat(3, 2);
    cout<<"\n The length of the list is: "<<l.length();
    l.display();
    //l = [-1, 0, 2, 3]
    l.RemoveAt(3);
    cout<<"\n The length of the list is: "<<l.length();
    l.display();
    SingleLinkedList reverse;
    reverse = l.reverse();
    reverse.display();
    return 0;
}