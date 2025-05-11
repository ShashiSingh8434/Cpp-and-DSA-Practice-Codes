#include <iostream>
#include <stack>
using namespace std;

void reorder(stack<int> &s, int target){
    if(s.empty()){
        cout<<"Stack end reached"<<endl;
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    reorder(s,target);
    s.push(temp);
        
}

void solve(stack<int> &s){
    if(s.empty()){
        return;
    }
    int target = s.top();
    s.pop();
    reorder(s,target);
}

int main(){
    stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    solve(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
