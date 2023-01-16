#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void display(ListNode *head){
    cout<<endl;
    ListNode *temp = head;
    while(temp != NULL){
        cout<<temp -> val<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head = NULL, *temp1 = list1, *temp2 = list2;
    if(list1== NULL && list2 == NULL)
        return head;
    if(temp1 == NULL)
        return temp2;
    else if(temp2 == NULL)
        return temp1;
    if(temp1 -> val <= temp2 ->val ){
        head = temp1;
        temp1 = temp1 -> next;
    }
    else{
        head = temp2;
        temp2 = temp2 -> next;
    }
    ListNode *temp = head;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> val < temp2 -> val){
            temp -> next = temp1;
            temp1 = temp1 -> next;
        }
        else{
                temp -> next = temp2;
                temp2 = temp2 -> next;
        }
        temp = temp -> next;
    }
    if( temp1 != NULL){
        temp -> next = temp1;
    }
    else if( temp2 != NULL){
        temp -> next = temp2;
    }
    return head;
}
int main(){
    ListNode *list1one = new ListNode(1) ;
    ListNode *list1two= new ListNode(2) ;
    ListNode *list1three = new ListNode(4) ;
    list1one -> next = list1two;
    list1two -> next = list1three;
    list1three -> next = NULL;
    ListNode *list2one = new ListNode(1) ;
    ListNode *list2two= new ListNode(3) ;
    ListNode *list2three = new ListNode(4) ;
    list2one -> next = list2two;
    list2two -> next = list2three;
    list2three -> next = NULL;
    ListNode* list1head = list1one;
    ListNode* list2head = list2one;
    display(mergeTwoLists(list1head, list2head));
    return 0;
}