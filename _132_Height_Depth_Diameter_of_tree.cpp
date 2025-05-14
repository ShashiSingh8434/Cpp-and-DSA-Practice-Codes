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

    int depth(Node* root, int val, int currDepth = 0) {
        if (!root) return -1;
        if (root->data == val) return currDepth;

        int left = depth(root->left, val, currDepth + 1);
        if (left != -1) return left;

        return depth(root->right, val, currDepth + 1);
    }

    int diameter(Node* root, int& res) {
        if (!root) return 0;

        int l = diameter(root->left, res);
        int r = diameter(root->right, res);

        res = max(res, l + r + 1); // update max path
        return 1 + max(l, r);
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
       /   \
     2      3
    / \    / \
   4   5  6   7
  / \    / \
 8   9  10  11
*/

    cout<<root->height(root)<<endl;
    cout<<root->depth(root,5)<<endl;

    int res = 0;
    res = root->diameter(root, res);
    cout << "Diameter: " << res << endl;

    return 0;
}