#include <iostream>
#include <algorithm>
using namespace std;

class Stack{
public:

    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }
    void push1(int data){
        if(top2-top1 != 1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout<<"Stack overflow"<<endl;    //  ⬅ Stack overflow happens here 😎
        }
    }

    void pop1(){
        if(top1 != -1){
            arr[top1] = 0;
            top1--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    int getTop1(){
        if(top1 != -1){
            return arr[top1];
        }
        else{
            cout<<"The stack is empty"<<endl;
        }
    }
    
    void push2(int data){
        if(top2-top1 != 1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout<<"Stack overflow"<<endl;    //  ⬅ Stack overflow happens here 😎
        }
    }

    void pop2(){
        if(top2 != size){
            arr[top2] = 0;
            top2++;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    int getTop2(){
        if(top2 != size){
            return arr[top2];
        }
        else{
            cout<<"The stack is empty"<<endl;
        }
    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<endl;
        }
        cout<<endl;
    }

};

int main(){
    Stack s(5);

    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push2(2);

    s.print();

    
    // cout<<s.getTop()<<endl; 

    s.pop1();
    s.print();
    
    return 0;
}