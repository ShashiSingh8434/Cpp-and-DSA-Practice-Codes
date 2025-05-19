#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d) {
        data = d;
        isTerminal = false;
        childCount = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

void insertWord(TrieNode* root, string s) {
    TrieNode* current = root;
    for (char c : s) {
        int index = c - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = new TrieNode(c);
            current->childCount++;
        }
        current = current->children[index];
    }
    current->isTerminal = true;
}

bool searchWord(TrieNode* root, string s){
    if(s.length() == 0){
        return root->isTerminal;
    }

    char c = s[0];
    int index = c - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return false;
    }

    return searchWord(child, s.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');
    insertWord(root, "coding");
    cout<<endl<<searchWord(root, "coding");
      
    return 0;
}