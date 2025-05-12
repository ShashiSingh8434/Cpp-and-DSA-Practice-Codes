#include <iostream>
using namespace std;

// very very important question

class Kqueue{
public:
    int n, k, freespot;
    int *arr, *next, *rear, *front;

    Kqueue(int _n,int _k): n(_n), k(_k), freespot(0){
        arr = new int[n];
        next = new int[n];
        front = new int[n];
        rear = new int[n];

        for(int i=0; i<n; i++)
            front[i] = rear[i] = -1;
        
        for(int i=0; i<n; i++)
            next[i] = i+1;
        
        next[n-1] = -1;
    }   

    bool push(int data, int qi){
        if(freespot == -1){
            return false;
        }

        int index = freespot;
        freespot = next[index];

        if(front[qi] == -1){
            front[qi] = index;
        }
        else{
            next[rear[qi]] = index;
        } 

        next[index] = -1;
        rear[qi] = index; 

        arr[index] = data;
        return true;
    }

    int pop(int qi){
        if(front[qi] == -1){
            return -1;
        }

        int index = front[qi];
        front[qi] = next[index];

        next[index] = freespot;
        freespot = index;

        return arr[index];
    }

    ~Kqueue(){
        delete []arr;
        delete []next;
        delete []front;
        delete []rear;
    }

};

int main(){
    
    return 0;
}