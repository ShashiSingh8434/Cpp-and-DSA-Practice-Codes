#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> mapping(string s){
    unordered_map<char, int> m;
    for(int i=0; i<s.length(); i++){
        m[s[i]] += 1; 
    }
    return m;
}

int main(){
    string s = "Hello";
    unordered_map<char, int> m = mapping(s);
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}