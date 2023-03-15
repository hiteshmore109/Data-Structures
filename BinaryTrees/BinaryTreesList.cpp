#include<iostream>
using namespace std;

// creating node structure for tree
class Node{
    public:
    int value;
    Node *left;
    Node *right;
    Node(int value){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//printing the created tree using inorder(left root right) traversal
void printTreeInorder(Node* root) {
    if (root == nullptr) return;
    //traverse to the left node of the current root node and applying it for every parent node
    printTreeInorder(root->left);
    //printing the node to the left of the root node
    cout << root->value << " ";
    //traversing from root node to the right of the node for each parent node
    printTreeInorder(root->right);
}

//printing created tree using preorder(root left right) traversal
void printTreePreorder(Node* root){
    if(root == nullptr) return;
    //printing the root node
    cout<<root->value<<" ";
    //traverse to the left node of the current root node and applying it for every parent node
    printTreePreorder(root->left);
    //traversing from left node to the right of the root node for each parent node
    printTreePreorder(root->right);
}

//printing created tree using postorder(left right root) traversal
void printTreePostorder(Node *root){
    if(root == nullptr) return;
    printTreePostorder(root->left);
    printTreePostorder(root->right);
    cout<<root->value<<" ";
}

int main(){
    //creating a root node
    Node* root = new Node(4);
    //creating a left node l1 for root node
    Node* l1 = new Node(2);
    //creating a right node r1 for root node
    Node* r1 = new Node(6);
    //creating a left node l2 for l1 node
    Node* l2 = new Node(1);
    //creating a right node r2 for l1 node
    Node* r2 = new Node(3);
    //creating a left node l3 for r1 node
    Node* l3 = new Node(5);
    //creating a right node r3 for r1 node
    Node* r3 = new Node(7);
    //linking root node to the left node l1
    root->left = l1;
    //linking root node to the right node r1
    root->right = r1;
    //linking l1 node to the left node l2
    l1->left = l2;
    //linking l1 node to the right node r2
    l1->right = r2;
    //linking r1 node to the left node l3
    r1->left = l3;
    //linking r1 node to the right node r3
    r1->right = r3;
    printTreeInorder(root);
    cout<<endl;
    printTreePreorder(root);
    cout<<endl;
    printTreePostorder(root);
    return 0;
}