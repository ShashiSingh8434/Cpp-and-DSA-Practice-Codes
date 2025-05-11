#include <iostream>
#include <stack>
using namespace std;

bool unUsedBrackets(string str){
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        char c = str[i];

        if(c == '(' || c=='{' || c=='['){
            s.push(c);
        }
        else if(c == '+' || c=='-' || c=='/' || c=='*'){
            if(s.empty()){
                return false;
            }
            s.pop();
        }
        else{
            // cout<<c<<" ";
        }
    }
    if(s.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    cout<<unUsedBrackets("(a+b)()");
    return 0;
}