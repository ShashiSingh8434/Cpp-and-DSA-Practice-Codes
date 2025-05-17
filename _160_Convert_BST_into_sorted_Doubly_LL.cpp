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

void convertIntoDLL(Node* root, Node* &head){
    if(!root) return;

    convertIntoDLL(root->right, head);

    root->right = head;

    if(head) head->left = root;

    head = root;

    convertIntoDLL(root->left, head);
}

void printDLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {5,4,8,7,1,6,9,11,2,3};
    Node* root = makeBST(arr);

    // levelOrder(root);
    // inorder(root); // inorder of BST is always sorted *** very very important
    
    cout<<"Conversion:"<<endl;
    Node* head = NULL;
    convertIntoDLL(root, head);
    printDLL(head);
    return 0;
}
