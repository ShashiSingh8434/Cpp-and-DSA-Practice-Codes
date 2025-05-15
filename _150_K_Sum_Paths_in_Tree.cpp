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

void pathFromOneRoot(Node* root, int sum, int &ans){
    if(!root) return;

    if(sum == root->data) ++ans;

    pathFromOneRoot(root->left, sum - root->data, ans);
    pathFromOneRoot(root->right, sum - root->data, ans);
}

int pathSum(Node* root, int targetSum, int &ans){
    if(root){
        pathFromOneRoot(root, targetSum, ans);
        pathSum(root->left, targetSum, ans);
        pathSum(root->right, targetSum, ans);
    }
    return ans;
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

    int ans = 0;
    ans  = pathSum(root, 9, ans);
    cout<<ans<<endl;  

    return 0;
}