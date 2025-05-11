#include <iostream>
#include <stack>
using namespace std;

int noOfBrackets(string str){
    stack<int> s;
    s.push(-1);
    int maxLen = 0;

    for(int i=0; i<str.length(); i++){
        if(str[i] == '('){
            s.push(i);
        }
        else{
            s.pop();
            if(!s.empty()){
                int len = i - s.top();
                maxLen = max(len, maxLen);
            }
            else{
                s.push(i);
            }
            
        }
    }
    return maxLen;
}

int main(){
    cout<<noOfBrackets("()(()");
    return 0;
}