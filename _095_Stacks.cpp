#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s ;

    // insertion
    s.push(1);
    s.push(2);
    s.push(3);

    // deletion
    // s.pop();

    // top element print
    cout<<"The head of stack is at:"<< s.top()<<endl;

    // size of stack
    cout<<"The size of stack is:"<<s.size()<<endl;

    
    // deletion
    s.pop();

    cout<<"After deletion: "<<endl;

    // top element print
    cout<<"The head of stack is at:"<< s.top()<<endl;

    // size of stack
    cout<<"The size of stack is:"<<s.size()<<endl;

    // isEmpty check
    cout<<"The stack is empty or not : "<< s.empty()<<endl;


    return 0;
}