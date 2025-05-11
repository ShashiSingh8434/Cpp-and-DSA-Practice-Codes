#include <iostream>
#include <stack>
using namespace std;

void insertion(stack<int> &s, int num){
    if(s.empty()){
        s.push(num);
        return;
    }
    if(num < s.top()){
        s.push(num);
        return;
    }
    
    int temp = s.top();
    s.pop(); 

    insertion(s,num);
    
    s.push(temp);  
    return;  
}

void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();

    sort(s);
    insertion(s,temp);

}

int main(){
    stack<int> s;

    s.push(8);
    s.push(9);
    s.push(6);
    s.push(7);
    s.push(5);
    s.push(2);

    sort(s);

    cout<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}