#include <iostream>
#include <stack>
using namespace std;
// in this the time complexity of :

// push is O(n)
// pop is O(1)
// front is O(1)

class Queue1{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int data){               
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop(){
        if(!s1.empty()){
            int temp = front();
            s1.pop();
            return temp;
        }
        else{
            cout<<"The queue is empty"<<endl;
        }
    }

    int front(){
        if(!s1.empty())
            return s1.top();
        else
            return -1;
    }

    void print(){
        while(!s1.empty()){
            cout<<s1.top()<<" ";
            s2.push(s1.top());
            s1.pop();
        }
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
};

// in this the time complexity of :

// push is O(1)
// pop is O(n)
// front is O(n)

class Queue2{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int data){               
        s1.push(data);
    }

    void pop(){
        if(!s2.empty()){
            s2.pop();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    int front(){
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    void print(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        while(!s2.empty()){
            cout<<s2.top()<<" ";
            s1.push(s2.top());
            s2.pop();
        }

    }
};


int main(){
    Queue2 q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.print();

    q.pop();

    cout<<endl;

    cout<<q.front()<<endl;
    q.print();
    
    return 0;
}