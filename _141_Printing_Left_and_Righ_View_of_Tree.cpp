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

void printLeftView(Node* root, vector<int> &ans, int level){
    if(!root) return;

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    printLeftView(root->left, ans, level+1);
    printLeftView(root->right, ans, level+1);
}

void printRightView(Node* root, vector<int> &ans, int level){
    if(!root) return;

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    printRightView(root->right, ans, level+1);
    printRightView(root->left, ans, level+1);
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

    vector<int> ans;
    int level = 0;
    printRightView(root, ans, level);

    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}