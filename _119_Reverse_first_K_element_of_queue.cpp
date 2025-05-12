#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

void reversing(queue<int> &q,int k){
    int i=0;
    stack<int> s;

    while(i<k){
        s.push(q.front());
        q.pop();
        i++;
    }

    while(i!=0){
        q.push(s.top());
        s.pop();
        i--;
    }

    i = k;
    while(i<q.size()){
        int temp = q.front();
        q.pop();
        q.push(temp);
        i++;
    }
}


int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    print(q);
    cout<<endl;

    reversing(q,6);

    print(q);

    return 0;
}