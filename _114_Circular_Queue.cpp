#include <iostream>
using namespace std;

class CircularQueue{
public:
    int* arr;
    int size;
    int front;
    int rear;

    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
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

    void pop(){
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

    int getFront(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
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
    CircularQueue q(6);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    // cout<<q.isEmpty()<<endl;
    
    q.pop();
    q.pop();
    q.pop();

    cout<<q.getFront()<<endl;
    cout<<q.getSize()<<endl;

    cout<<q.front;
    cout<<q.rear;

    q.push(9);

    cout<<q.getFront()<<endl;
    cout<<q.getSize()<<endl;

    cout<<q.front;
    cout<<q.rear;




    return 0;
}