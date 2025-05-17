#include <iostream>
#include <algorithm>
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

class NodeData{
public:
    int size;
    int maxVal;
    int minVal;
    bool validBST;

    NodeData(){}

    NodeData(int n, int maxval, int minval, bool valid){
        this->size = n;
        this->maxVal = maxval;
        this->minVal = minval;
        this->validBST = valid;
    }
};

NodeData findLargestBST(Node* root, int &ans){
    if(root == NULL){
        return NodeData(0, INT32_MIN, INT32_MAX, true);
    }

    NodeData leftans = findLargestBST(root->left, ans);
    NodeData rightans = findLargestBST(root->right, ans);

    NodeData currans;

    currans.size = leftans.size + rightans.size +1;
    currans.maxVal = max(root->data, rightans.maxVal);
    currans.minVal = min(root->data, leftans.minVal);
    
    if(leftans.validBST && rightans.validBST && root->data > leftans.maxVal && root->data < rightans.minVal){
        currans.validBST = true;
    }
    else{
        currans.validBST = false;
    }

    if(currans.validBST){
        ans = max(ans, currans.size);
    }

    return currans;

}

int main(){
    Node* root = new Node(50);
    Node* a = new Node(30);
    Node* b =  new Node(60);
    Node* c = new Node(5);
    Node* d =  new Node(20);
    Node* e = new Node(45);
    Node* f =  new Node(70);
    Node* i = new Node(65);
    Node* j =  new Node(80);

    root->relationSet(a,b);
    a->relationSet(c,d);
    b->relationSet(e,f);
    f->relationSet(i,j);
    
/*

          50
        /    \
     30       60
    / \       / \
   5   20   45   70
                 / \
                65  80
 
*/
    int size = 0;
    findLargestBST(root, size);
    cout<<size;
    return 0;
}