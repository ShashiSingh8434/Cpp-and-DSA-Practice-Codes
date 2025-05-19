#include <iostream>
using namespace std;

class Heap{
public: 
    int size;
    int* arr;

    Heap(){ 
        size = 0;
        arr = new int[100];
        arr[size] = 0;
    }

    void insert(int data){
        size = size + 1;
        int index = size;
        arr[index] = data;

        while(index > 1){
            int parentIndex = index/2;

            if(arr[index] > arr[parentIndex]){
                swap(arr[index] , arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void rearrange(int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left <= size && arr[left] > arr[largest])
            largest = left;
        if(right <= size && arr[right] > arr[largest])
            largest = right;

        if(largest != i){
            swap(arr[i], arr[largest]);
            rearrange(largest);
        }
        return;
    }

    int deletion(){
        swap(arr[size], arr[1]);
        int temp = arr[size];
        size--;

        int i = 1;
        rearrange(i);

        return temp;
    }
};

/*
In this Heap structure we are making a complete binary tree of max that ie the child of every node must be smaller than the parent node and also in this arr the arr[0] = NULL ... we are starting the arr from pos 1 to fill so that accesing the parent node is easier using formula 
    (parentIndex = index / 2) and 
    left node of parent is  (2*index)
    right node of parent is  (2*index + 1)

*/

int main(){
    Heap* h = new Heap();
    h->insert(50);
    h->insert(30);
    h->insert(70);
    h->insert(40);
    h->insert(80);
    h->insert(100);
    
    for(int i=0; i < h->size+1; i++){
        cout<<i<<" - "<<h->arr[i]<<endl;
    }
    cout<<h->deletion()<<endl;

    for(int i=0; i < h->size+1; i++){
        cout<<i<<" - "<<h->arr[i]<<endl;
    }
    return 0;
}