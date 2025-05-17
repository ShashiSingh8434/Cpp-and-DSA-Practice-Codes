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

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* BST_using_inorder(int* inorder, int s, int e){
    if(s>e) return nullptr;

    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = BST_using_inorder(inorder, s, mid-1);
    root->right = BST_using_inorder(inorder, mid+1, e);

    return root;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};

    Node* ans = BST_using_inorder(arr,0,(sizeof(arr)/sizeof(int))-1);
    levelOrder(ans);
    
    return 0;
}

/*

       6 
   3          9 
 1   4    7       11 
2     5     8   10  12 

*/