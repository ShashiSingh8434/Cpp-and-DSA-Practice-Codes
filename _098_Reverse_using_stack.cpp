#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> s;

    string str;
    cout<<"Enter a string:";
    cin>>str;

    for(auto i : str){
        s.push(i);
    }

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

    return 0;
}