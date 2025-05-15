#include <iostream>
#include <queue>
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

    void levelOrder(Node* root) {
        if (!root) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
};

int iterate(Node* root, int &leftSum, int &rightSum){
    if(!root) return 0;

    int temp = root->data;

    root->data = iterate(root->left, leftSum, rightSum) 
               + iterate(root->right, leftSum, rightSum);
                
    
    return root->data + temp;
}

void transform(Node* root){
    int leftSum = 0;
    int rightSum = 0;
    
    iterate(root, leftSum, rightSum);
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
    root->levelOrder(root);

    cout<<endl<<endl;

    transform(root);
    root->levelOrder(root);

    cout<<endl<<endl;

    
    return 0;
}