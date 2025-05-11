#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str){
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        else{
            if(s.empty()){
                return false;
            }
            else{
                char topCh = s.top();

                if(ch == ')' && topCh == '('){
                    s.pop();
                }
                else if(ch == ']' && topCh == '['){
                    s.pop();
                }
                else if(ch == '}' && topCh == '{'){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        } 
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cout<<endl;
    cout<<isValid("()")<<endl;
    cout<<endl;
    return 0;
}