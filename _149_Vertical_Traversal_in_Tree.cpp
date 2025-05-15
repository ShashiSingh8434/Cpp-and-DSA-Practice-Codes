#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

vector<vector<int>> verticalTraversal(Node* root){
    vector<vector<int>> ans;
    queue<pair<Node*, pair<int,int>>> q;

    q.push({root, {0,0}});

    map<int, map<int, multiset<int>>> map;  // {col : {row : {x,y,z....}}}

    while(!q.empty()){
        auto front = q.front();
        q.pop();

        Node* &node = front.first;
        auto coordinate = front.second;

        int &row = coordinate.first;
        int &col = coordinate.second;

        map[col][row].insert(node->data);

        if(node->left)
            q.push({node->left, {row+1 , col-1}});
        
        if(node->right)
            q.push({node->right, {row+1 , col+1}});
        
    }

    for(auto iterator : map){
        auto &colMap = iterator.second;

        vector<int> vLine;
        for(auto colmapIt : colMap){
            auto &mset = colmapIt.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }
        ans.push_back(vLine);
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
    root->levelOrder(root);

    cout<<endl<<endl;

    vector<vector<int>> ans = verticalTraversal(root);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}