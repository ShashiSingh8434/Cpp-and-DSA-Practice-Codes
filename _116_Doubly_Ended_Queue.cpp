#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> d;

    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);

    cout<<d.front()<<endl;
    d.pop_front();
    cout<<d.front()<<endl;

    cout<<d.back()<<endl;
    d.pop_back();
    cout<<d.back()<<endl;

    
    return 0;
}