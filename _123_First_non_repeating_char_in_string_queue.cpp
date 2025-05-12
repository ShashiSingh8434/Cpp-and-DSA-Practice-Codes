#include <iostream>
#include <queue>
using namespace std;

string repeating(string s){
    queue<char> q;
    int freq[26] = {0}; 

    string ans = "";

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        freq[ch - 'a']++;

        q.push(ch);

        while(!q.empty()){
            if(freq[q.front() - 'a']>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    cout<<repeating("abcba");
    
    return 0;
}