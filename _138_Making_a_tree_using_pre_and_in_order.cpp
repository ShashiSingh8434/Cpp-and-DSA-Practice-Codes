#include <iostream>
#include <queue>
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

    
    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << ", ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << ", ";
        inorder(root->right);
    }

    void levelOrder(Node* root) {
        if (!root) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

};

int findPosition(int arr[], int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i]==element){
            cout<<"pos:"<<i<<endl<<endl;
            return i;
        }
    }
    return -1;
}

Node* makeATree(int preorder[], int inorder[], int size, int &preIndex, int inorderStart, int inorderEnd){

    if(preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }
    
    int element = preorder[preIndex++];
    Node* root = new Node(element);
    // int len = (inorderEnd-inorderStart+1);
    int pos = findPosition(inorder, size, element);

    root->left = makeATree(preorder, inorder, size, preIndex, inorderStart, pos-1);
    root->right = makeATree(preorder, inorder, size, preIndex, pos+1, inorderEnd);

    return root;
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
     2             3
  4     5        6    7
8  9          10  11

*/
    root->preorder(root);   // DFS 
    cout<<endl;
    // root->postorder(root);   
    cout<<endl;
    root->inorder(root);   

    int preor[] = {1, 2, 4, 8, 9, 5, 3, 6, 10, 11, 7};
    int inord[] = {8, 4, 9, 2, 5, 1, 10, 6, 11, 3, 7};
    int size = sizeof(preor)/sizeof(int);

    int preIndex = 0;

    Node* alpha = makeATree(preor, inord, size, preIndex, 0 , size-1);

    cout<<endl;
    alpha->levelOrder(alpha);
    
    return 0;
}