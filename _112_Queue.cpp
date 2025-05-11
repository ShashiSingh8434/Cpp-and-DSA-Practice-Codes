#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;

    cout<<q.empty()<<endl<<endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<"Size: "<<q.size()<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl<<endl;

    q.pop();
    
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;

    return 0;
}