#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {
        data = d;
        isTerminal = false;
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
        }
        current = current->children[index];
    }
    current->isTerminal = true;
}

// Helper function to collect all words starting from a given node
void dfs(TrieNode* current, string prefix, vector<string>& suggestions) {
    if (current->isTerminal) {
        suggestions.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        if (current->children[i]) {
            char nextChar = i + 'a';
            dfs(current->children[i], prefix + nextChar, suggestions);
        }
    }
}

vector<string> getSuggestions(TrieNode* root, string prefix) {
    TrieNode* current = root;
    vector<string> suggestions;

    for (char c : prefix) {
        int index = c - 'a';
        if (current->children[index] == NULL) {
            return suggestions; // No matches
        }
        current = current->children[index];
    }

    dfs(current, prefix, suggestions);
    return suggestions;
}

int main() {
    vector<string> wordList = {
        "shashi", "sharad", "shark", "shabby", "shadow", "shape", "share", "sharp"
    };

    TrieNode* root = new TrieNode('-');

    for (string word : wordList) {
        insertWord(root, word);
    }

    string input;
    cout << "Enter prefix: ";
    cin >> input;

    vector<string> results = getSuggestions(root, input);

    if (results.empty()) {
        cout << "No suggestions found for \"" << input << "\"\n";
    } else {
        cout << "Suggestions for \"" << input << "\":\n";
        for (string s : results) {
            cout << s << endl;
        }
    }

    return 0;
}
