#include<iostream>
using namespace std;
//Tree node structure
class Tree{
    public:
    int value;
    Tree* left;
    Tree* right;
    Tree(int value){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//to insert a node in a binary search tree
Tree* insertChild(Tree* parent, int value){
    //if the branch is empty add new node in the branch
    if(parent == nullptr)
        parent = new Tree(value); 
    //if the value is less than parent add it to left of the parent node using recursion
    else if(value <= parent->value)
        parent->left = insertChild(parent->left, value);
    //if the value is greater than parent add it to right of the parent node using recursion
    else if(value > parent->value)
        parent->right = insertChild(parent->right, value);
    return parent;
}

//print the tree using Inorder traversal(left, root, right) to ensure that the binary tree is created successfully
void printInorder(Tree* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout<<root->value<<" ";
    printInorder(root->right);
}

//testing using user input
int main(){
    Tree* root = NULL;
    int n, element;
    cout<<"Enter the number of elments you want to insert in tree: ";
    cin>>n;
    for(int i = 1; i <= n; i++){
        cout<<"Enter the element "<<i<<":";
        cin>>element;
        root = insertChild(root, element);
    }
    printInorder(root);
    return 0;
}