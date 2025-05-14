#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
    
    void relationSet(Node* x, Node* y) {
        left = x;
        right = y;
    }
};

void printLeftBoundary(Node* root){
    if(!root || (!root->left && !root->right))  return;

    cout<<root->data<<" ";
    if(root->left)
        printLeftBoundary(root->left);
    else 
        printLeftBoundary(root->right);
}

void printLeafBoundary(Node* root){
    if(!root)  return;

    if(!root->left && !root->right){    
        cout<<root->data<<" ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root){
    if(!root || (!root->left && !root->right))  return;
 
    if(root->right)
        printRightBoundary(root->right);
    else 
        printRightBoundary(root->left);

    cout<<root->data<<" ";
}

void boundaryTraversal(Node* root){
    if(!root){
        return;
    }

    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    printLeafBoundary(root);
    printRightBoundary(root->right);
}

int main(){
    Node* root = new Node(1);
    Node* a = new Node(2);
    Node* b =  new Node(3);
    Node* c = new Node(4);
    Node* d =  new Node(5);
    Node* e = new Node(6);
    Node* f =  new Node(7);
    Node* g = new Node(8);
    Node* h =  new Node(9);
    Node* i = new Node(10);
    Node* j =  new Node(11);

    root->relationSet(a,b);
    a->relationSet(c,d);
    b->relationSet(e,f);
    c->relationSet(g,h);
    e->relationSet(i,j);
    
/*

         1
       /   \
     2      3
    / \    / \
   4   5  6   7
  / \    / \
 8   9  10  11
 
*/

    cout<<endl;
    boundaryTraversal(root);
    cout<<endl<<endl;
    return 0;
}