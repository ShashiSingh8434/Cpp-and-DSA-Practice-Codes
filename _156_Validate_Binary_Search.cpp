#include <iostream>
#include <queue>
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

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        if(curr == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }        
    }
}

void insertIntoBST(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }

    if(root->data > data){
        insertIntoBST(root->left, data);
    }
    else{
        insertIntoBST(root->right, data);
    }
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* makeBST(vector<int> arr){
    Node* root = nullptr;

    for(int i=0; i<arr.size(); i++){
        int data = arr[i];
        insertIntoBST(root, data);
    }
    return root;
}
/*

#### One more way to validate BST is to find its inorderTraversal and then check whether it is sorted or not if not then the BST is invalid as simple as that ####

*/

// this method stricty prohibit same data entries so be careful   -----------------------------------
bool validation(Node* root, long long int lb, long long int ub){  
    if(!root) return true;

    if(root->data > lb 
        && root->data < ub       // to allow duplicates entry here change the condition to "&& root->data <= ub" 
        && validation(root->left, lb, root->data) 
        && validation(root->right, root->data, ub)){

        return true;
    }   
    else{
        return false;
    }  
}

bool validateBST(Node* root){
    long long int lb = INT64_MIN;        // INT64_MIN is used to initialise min for very very small no. ie -(2 raise to 63)
    long long int up = INT64_MAX;

    return validation(root, lb, up);
}

int main(){
    vector<int> arr = {5,4,8,7,1,6,9,11,2,3};
    Node* root = makeBST(arr);

    levelOrder(root);
    inorder(root); // inorder of BST is always sorted *** very very important

    cout<<endl;
    cout<<validateBST(root);     
    
    return 0;
}
