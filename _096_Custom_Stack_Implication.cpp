#include <iostream>
using namespace std;

class Stack{
private:

    int *arr;
    int size;
    int top;
    
public:

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }
    void push(int data){
        if(size-top>1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"Stack overflow"<<endl;    //  ⬅ Stack overflow happens here 😎
        }
    }

    void pop(){
        if(top != -1){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    int getTop(){
        if(top != -1){
            return arr[top];
        }
        else{
            cout<<"The stack is empty"<<endl;
        }
    }

    int getSize(){
        // because top is acting as a index here
        return ++top;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Stack s(5);

    s.push(1);
    s.push(2);

    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    
    // cout<<s.getTop()<<endl; 

    // s.pop();


    // while(!s.isEmpty()){
    //     cout<<s.getTop()<<endl; 
    //     s.pop();
    // }
    
    // s.pop();
    
    return 0;
}