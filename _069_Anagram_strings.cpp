#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram1(string s, string t){
    if(s.length() !=  t.length()){
        return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

bool isAnagram2(string s, string t){
    int count[256] = {0};

    for(int i=0; i<s.size(); i++){
        count[s[i]]++;
    }
    for(int i=0; i<t.size(); i++){
        count[t[i]]--;
    }
    for(int i=0; i<256; i++){
        if(count[i] != 0) return false;
    }
    return true;
}

int main(){
    bool result = isAnagram2("hello","ehllo");
    cout<<result;
    
    return 0;
}