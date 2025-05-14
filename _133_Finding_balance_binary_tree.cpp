#include <iostream>
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

    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(Node* root){
        if(!root){
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool ans1 = (diff <= 1);

        bool leftans = isBalanced(root->left);
        bool rightans = isBalanced(root->right);

        if(ans1 && leftans && rightans){
            return true;
        }
        else{
            return false;
        }
    }

};


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
     2             3
  4     5        6    7
8  9          10  11

*/

    return 0;
}