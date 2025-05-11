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

bool checkSorted(stack<int> s){
    if(s.empty()){
        return true;
    }
    
    int temp = s.top();
    s.pop();    

    while(s.size()>0){
        if(temp > s.top()){
            return false;
        }
        temp = s.top();
        s.pop();
    }
    return true;
}

int falacy(stack<int> &s) {
    if (s.size() <= 1){
        return -1; 
    }
    int temp = s.top(); 
    s.pop();

    int res = falacy(s);

    if (res != -1) {
        s.push(temp);
        return res;
    }

    if (!s.empty() && temp > s.top()) {
        return temp; 
    }

    s.push(temp);
    return -1;
}


void sort(stack<int> &s){
    while(!checkSorted(s)){
        insertion(s,falacy(s));
    }
}

int main(){
    stack<int> s;

    s.push(8);
    s.push(9);
    s.push(6);
    s.push(7);
    s.push(5);
    s.push(2);

    // 2->5->7->6->9->8

    // cout<<checkSorted(s)<<endl;
    // cout<<falacy(s)<<endl;
    // insertion(s,falacy(s));
    sort(s);

    cout<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}