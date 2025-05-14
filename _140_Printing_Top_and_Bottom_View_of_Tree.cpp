#include <iostream>
#include <queue>
#include <map>
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

void printTopView(Node* root){
    if(root == NULL){
        return;
    }

    map<int, int> topNode;
    queue<pair<Node* , int>> q;

    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;  // hd means horizontal distance

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }

    }

    cout<<"Printing the top view: "<<endl;
    for(auto i: topNode){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

void printBottomView(Node* root) {
    if(root == NULL){
        return;
    }

    map<int, int> bottomNode;
    queue<pair<Node* , int>> q;

    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* node = temp.first;
        int hd = temp.second;  // hd means horizontal distance

        bottomNode[hd] = node->data;  // here we are always updating unlike in top view case
        
        if(node->left){
            q.push(make_pair(node->left,hd-1));
        }
        if(node->right){
            q.push(make_pair(node->right,hd+1));
        }

    }

    cout << "Printing the bottom view: " << endl;
    for(auto i : bottomNode){
        cout << i.first << " " << i.second << endl;
    }
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

   8 - 4 - 2 - 1 - 3 - 7
       |   |       |
       9   5    10-6-11 
*/
    printTopView(root);
    cout<<endl;
    printBottomView(root);
    return 0;
}