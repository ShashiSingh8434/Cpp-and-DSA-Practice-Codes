#include <iostream>
#include <vector>
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

string getLongestCommonPrefix(TrieNode* root) {
    string ans = "";
    TrieNode* current = root;

    while (current && current->childCount == 1 && !current->isTerminal) {
        for (int i = 0; i < 26; i++) {
            if (current->children[i]) {
                current = current->children[i];
                ans += current->data;
                break;
            }
        }
    }

    return ans;
}

string solution(vector<string>& str) {
    TrieNode* root = new TrieNode('-');
    for (string s : str) {
        insertWord(root, s);
    }
    return getLongestCommonPrefix(root);
}

int main() {
    vector<string> v = {
        "shahsi",
        "shandk",
        "shaadsf",
        "shaefv",
        "shaewt",
        "shanm"
    };

    cout << "Longest Common Prefix: " << solution(v) << endl;
    return 0;
}
