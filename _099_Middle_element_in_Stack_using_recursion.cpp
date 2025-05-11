#include <iostream>
#include <stack>
using namespace std;

void middle(stack<int> &s, int &target){
    if(s.size()==0){
        cout<<"Empty Stack";
        return;
    }
    if(s.size()==target){
        cout<<"Middle element of stack is: "<<s.top();
        return;
    }

    int temp = s.top();
    s.pop();

    middle(s,target);
    s.push(temp);
        
}

int main(){
    stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    int target = s.size()/2;
    middle(s,target);

    return 0;
}