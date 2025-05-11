#include <iostream>
#include <vector>
using namespace std;

class Stack{
    vector<pair<int, int>> vec;

    Stack(){}

    void push(int data){
        if(vec.empty()){
            pair<int,int> p = make_pair(data,data);
            vec.push_back(p);
        }
        else{
            pair<int,int> p;

            p.first = data;
            p.second = min(vec.back().second,data);

            vec.push_back(p);
        }
    }

    void pop(){
        vec.pop_back();
    }

    int top(){
        return vec.back().first;
    }

    int getMin(){
        return vec.back().second;
    }
};

int main(){
    
    return 0;
}