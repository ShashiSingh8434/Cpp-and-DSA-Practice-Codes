#include <iostream>
#include <queue>
using namespace std;

int main(){
    // This is max heap creation STL
    priority_queue<int> pq;
    pq.push(3);
    pq.push(4);
    pq.push(7);
    pq.push(8);
    pq.push(10);
    pq.push(1);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    // cout<<endl<<endl;
    // cout<<pq.top()<<" ";
    // pq.pop();
    // cout<<pq.top()<<" ";
    // cout<<pq.empty()<<" ";
    // cout<<pq.size()<<" ";
    // cout<<endl<<endl;

    // This is min heap creation STL
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(3);
    pq_min.push(4);
    pq_min.push(7);
    pq_min.push(8);
    pq_min.push(10);
    pq_min.push(1);

    // cout<<pq_min.top()<<" ";
    // pq_min.pop();
    // cout<<pq_min.top()<<" ";
    // cout<<pq_min.empty()<<" ";
    // cout<<pq_min.size()<<" ";
    // cout<<endl<<endl;

    return 0;
}