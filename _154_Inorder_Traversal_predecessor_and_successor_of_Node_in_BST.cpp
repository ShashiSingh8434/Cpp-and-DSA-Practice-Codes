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

Node* find(Node* root, int key){
    if(!root) return nullptr;
    if(root->data == key) return root;
    else if(root->data < key) return find(root->right, key);
    else return find(root->left, key);
}

int predecessor(Node* root, int num){
    Node* curr = root;
    int pred = -1;

    while(curr){
        if(num > curr->data){
            pred = curr->data; // possible predecessor
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }

    Node* node = find(root, num);
    if(node && node->left){
        pred = maxVal(node->left);
    }

    return pred;
}

int successor(Node* root, int num){
    Node* curr = root;
    int succ = -1;

    while(curr){
        if(num < curr->data){
            succ = curr->data; // possible successor
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }

    Node* node = find(root, num);
    if(node && node->right){
        succ = minVal(node->right);
    }

    return succ;
}

int main(){
    vector<int> arr = {5,4,8,7,1,6,9,11,2,3};
    Node* root = makeBST(arr);

    levelOrder(root);
    cout<<endl;
    inorder(root); // inorder of BST is always sorted *** very very important
    
// Level Order
//      5 
//   4     8
//  1     7 9
//   2   6  11
//    3

// Inorder
// 1 2 3 4 5 6 7 8 9 11 


// to find predecessor we need to get to the node and then reach the max of the left subtree

// to find successor we need to get to the node and then reach the min of the right subtree

    cout<<endl<<predecessor(root,9);
    cout<<endl<<successor(root,9);
    return 0;
}
