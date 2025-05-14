#include <iostream>
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

void iterate(Node* root, vector<int> &path, vector<vector<int>> &ans, int pathSum){
    if(!root){
        return;
    }
    
    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){
        int currSum = 0;
        for(int i=0; i<path.size(); i++){
            currSum += path[i];
        }
        if(currSum == pathSum){
            ans.push_back(path);
        }
        path.pop_back();
        return;
    }


    iterate(root->left, path, ans, pathSum); // left part
    iterate(root->right, path, ans, pathSum); // right part
    path.pop_back();

}

vector<vector<int>> solution(Node* root, int pathSum){
    vector<vector<int>> ans;
    vector<int> temp;
    

    iterate(root, temp, ans, pathSum);
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
     2             3
  4     5        6    7
8  9          10  11

*/

    vector<vector<int>> ans = solution(root, 8);
    for(int i=0; i<ans.size(); i++){
        for(int j =0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}