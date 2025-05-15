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

int maxVal(Node* root){
    Node* temp = root;

    if(!temp) return -1;

    if(temp){
        while(temp->right){
            temp = temp->right;
        }
        return temp->data;
    }
}

int minVal(Node* root){
    Node* temp = root;

    if(!temp) return -1;

    if(temp){
        while(temp->left){
            temp = temp->left;
        }
        return temp->data;
    }
}

Node* deleteNode(Node* root, int target){
    if(!root) return NULL;

    if(root->data == target){
        
        if(!root->left && !root->right){
            return NULL;
        }
        else if(!root->left && root->right){
            Node* child = root->right;
            return child;
        }
        else if(root->left && !root->right){
            Node* child = root->left;
            return child;
        }
        else{
            int inorderPredecessor = maxVal(root->left);
            root->data = inorderPredecessor;
            root->left = deleteNode(root->left,inorderPredecessor);
            return root;
        }
    }
    else if(root->data > target){ 
        root->left = deleteNode(root->left, target);
    }
    else if(root->data < target){ 
        root->right = deleteNode(root->right, target);
    }
    return root;
}



int main(){
    vector<int> arr = {5,4,8,7,1,6,9,11,2,3};
    Node* root = makeBST(arr);

    vector<int> arr2 = {100,50,150,40,60,110,175};
    Node* rootnew = makeBST(arr2);

    levelOrder(rootnew);
    cout<<endl;
    deleteNode(rootnew, 100);
    levelOrder(rootnew);
    return 0;
}
