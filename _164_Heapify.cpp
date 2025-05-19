#include <iostream>
using namespace std;

void heapify(int* &arr, int size, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void buildHeap(int* arr, int size) {
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, size, i);
    }
}

/*
In this Heap structure we are making a complete binary tree of max that ie the child of every node must be smaller than the parent node and also in this arr the arr[0] = NULL ... we are starting the arr from pos 1 to fill so that accesing the parent node is easier using formula 
    (parentIndex = index / 2) and 
    left node of parent is  (2*index)
    right node of parent is  (2*index + 1)

*/

int main(){

    int* x = new int[7];
    x[0] = 0;
    x[1] = 30;
    x[2] = 40;
    x[3] = 50;
    x[4] = 80;
    x[5] = 70;
    x[6] = 100;

    int size = 7;

    buildHeap(x, size);

    for (int i = 1; i < size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    /*
    
    Now the arr x is modified into binary tree like array following max heap rule 

    */
    return 0;
}