#include <iostream>
#include <queue>
using namespace std;

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

void interleaf(queue<int> &q){
    int i = 0;
    int k = q.size()/2;

    queue<int> temp;

    while(i<k){
        temp.push(q.front());
        q.pop();
        i++;
    }

    while(i!=0){
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();

        i--;
    }

    if(q.size()%2 != 0){
        q.push(q.front());
        q.pop();
    }
}


int main(){
    queue<int> q;

    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // q.push(6);
    // q.push(7);

    print(q);
    cout<<endl;

    interleaf(q);

    print(q);

    cout<<"Hello";

    return 0;
}