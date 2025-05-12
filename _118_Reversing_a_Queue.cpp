#include <iostream>
#include <queue>
using namespace std;

// this thing can also be done using stack like we push the element from the queue to stack and pop them from queue and when queue is empty we can now start pushing element from stack into queue to reverse the queue but this method will have time complexity of O(n) and space complexity of O(n) ... therefore i did it using recursion which is better method of doing it 😉

void reverse(queue<int> &q){
    if(q.empty()){
        return;
    }

    // cout<<"hello"<<endl;

    int temp = q.front();
    q.pop();
    
    reverse(q);

    q.push(temp);
}

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    print(q);

    reverse(q);

    print(q);
    
    return 0;
}