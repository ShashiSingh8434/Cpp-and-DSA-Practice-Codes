#include <iostream>
using namespace std;

class TrieNode{
public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        this->data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
            this->isTerminal = false;
        }
    }
};

void insertWord(TrieNode* root, string s){
    cout<<"inserting "<<s<<endl;
    if(s.length() == 0){
        root->isTerminal = true;
        return;
    }

    char c = s[0];
    int index = c - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNode(c);
        root->children[index] = child;
    }

    insertWord(child, s.substr(1));
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