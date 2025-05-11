#include <iostream>
#include <stack>
using namespace std;

void insertAt(stack<int> &s, int target, int index){
    if(s.size()==index){
        // cout<<"Stack end reached"<<endl;
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    insertAt(s,target,index);
    s.push(temp);
        
}

void reverse(stack<int> &s){
    if(s.empty()){
        cout<<"hello";
        return;
    }
    int i = 0;
    int totalSize = s.size();



    while(i<totalSize){
        int target = s.top();
        s.pop();
        insertAt(s,target,i);

        i++;
    }
}

int main(){
    stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
