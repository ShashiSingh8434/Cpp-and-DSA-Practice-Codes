#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target){
    if(s.empty()){
        cout<<"Stack end reached"<<endl;
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    insertAtBottom(s,target);
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

    int target = s.top();

    insertAtBottom(s,target);
    while(s.size()!=0){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
