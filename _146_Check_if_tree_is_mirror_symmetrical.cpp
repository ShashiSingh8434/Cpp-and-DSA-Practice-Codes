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
};

bool isMirror(Node* p, Node* q){
    if(!p && !q)
        return true;

    if(p && q)
        return ((p->data == q->data)
            && isMirror(p->left,q->right) 
            && isMirror(p->right, q->left));
    
    return false;    
}

bool solution(Node* root){
    return isMirror(root->left, root->right);
}

int main(){
    Node* root = new Node(1);
    Node* a = new Node(2);
    Node* b =  new Node(2);
    Node* c = new Node(4);
    Node* d =  new Node(5);
    Node* e = new Node(4);
    Node* f =  new Node(5);
    Node* g = new Node(8);
    Node* h =  new Node(9);
    Node* i = new Node(9);
    Node* j =  new Node(8);

    root->relationSet(a,b);
    a->relationSet(c,d);
    b->relationSet(f,e);
    c->relationSet(g,h);
    e->relationSet(i,j);
    
/*

         1
       /   \
     2      2
    / \    / \
   4   5  5   4  
  / \        / \
 8   9      9   8
 
*/
    bool ans = solution(root);
    cout<<ans;
    return 0;
}