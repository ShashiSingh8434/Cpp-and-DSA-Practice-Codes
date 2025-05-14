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

    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
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

bool KthAncestor(Node* root, Node* p, int &k){
    if(!root){
        return false;
    }

    if(root->data == p->data){
        return true;
    }

    bool leftans = KthAncestor(root->left, p, k); 
    bool rightans = KthAncestor(root->right, p,k); 

    if(leftans || rightans ){
        k--;
    }
    
    if(k==0){
        cout<<root->data<<endl;
        k = -1;
    }
    
    return leftans || rightans;

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
     2             3
  4     5        6    7
8  9          10  11

*/

    // root->levelOrder(root);

    Node* test = new Node(4);
    int x = 1;
    bool z = KthAncestor(root, test, x);

    return 0;
}