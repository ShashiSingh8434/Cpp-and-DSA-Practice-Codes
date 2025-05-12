#include <iostream>
#include <queue>
using namespace std;

class Stack{
public:
    queue<int> q;

    void push(int data){
        q.push(data);

        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();            
        }
    }

    void pop(){
        int temp = top();
        q.pop();
    }

    int top(){
        if(!q.empty()){
            return q.front();
        }
        else{
            return -1;
        }
    }

    void print(){
        for(int i=0; i<q.size(); i++){
            cout<<q.front()<<" ";
            q.push(q.front());
            q.pop();            
        }
    }
};

int main(){
    Stack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.print();

    q.pop();

    cout<<endl;

    cout<<q.top()<<endl;
    q.print();
    return 0;
}