#include <iostream>
using namespace std;

// in this circular property of queue thing is question depended
// Doubly ended queue

class Deque{
public:
    int* arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_back(int data){
        if(rear == -1 && front == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front == 0){
            cout<<"Queue is full"<<endl;
        }
        else if(front-rear == 1){
            cout<<"Queue is full"<<endl;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }
    void push_front(int data){
        if(rear == -1 && front == -1){
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        else if(rear == size-1 && front == 0){
            cout<<"Queue is full"<<endl;
        }
        else if(front-rear == 1){
            cout<<"Queue is full"<<endl;
        }
        else if(rear != size-1 && front == 0){
            front = size-1;
            arr[front] = data;
        }
        else{
            front--;
            arr[front] = data;
        }
    }

    void pop_front(){
        if(rear == -1 && front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            arr[rear] = -2;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            arr[front] = -2;
            front = 0;
        }
        else{
            arr[front] = -2;
            front++;
        }
    }

    void pop_back(){
        if(rear == -1 && front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            arr[rear] = -2;
            front = -1;
            rear = -1;
        }
        else if(front != 0 && rear == 0){
            arr[rear] = -2;
            rear = size-1;
        }
        else{
            arr[rear] = -2;
            rear--;
        }
    }

    int getFront(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getBack(){
        if(rear == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    bool isEmpty(){
        if(front == rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        if(front == rear == -1){
            return 0;
        }
        else{        
            if(front <= rear){
                return rear-front+1;
            }
            else{
                return front-rear+1;
            }
        }
    }
};

int main(){
    Deque d(6);

    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);

    cout<<d.getFront()<<endl;
    d.pop_front();
    cout<<d.getFront()<<endl;

    cout<<d.getBack()<<endl;
    d.pop_back();
    cout<<d.getBack()<<endl;

    return 0;
}