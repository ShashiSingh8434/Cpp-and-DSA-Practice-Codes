#include <iostream>
#include <vector>
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
};

vector<vector<int>> zigzagLevelOrder(Node* root){
    vector<vector<int>> ans;
    if(!root) return ans;

    bool left_to_right = true;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int width = q.size();
        vector<int> oneLevel(width);

        for(int i=0; i<width; i++){
            Node* front = q.front();
            q.pop();

            int index = left_to_right ? i : width-i-1;
            oneLevel[index] = front->data;

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        left_to_right = !left_to_right;
        ans.push_back(oneLevel);
    }
    return ans;
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
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}