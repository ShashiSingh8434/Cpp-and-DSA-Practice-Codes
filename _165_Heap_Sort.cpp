#include <iostream>
using namespace std;

class Heap {
public:
    int size;
    int* arr;

    Heap(int capacity) { 
        size = 0;
        arr = new int[capacity + 1];
        arr[0] = -1; // Dummy value for 1-based indexing
    }

    void insert(int data) {
        size++;
        int index = size;
        arr[index] = data;

        while(index > 1) {
            int parentIndex = index / 2;
            if(arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << i << " - " << arr[i] << endl;
        }
    }
};

// heapify for 1-based index
void heapify(int* arr, int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= size && arr[left] > arr[largest])
        largest = left;
    if(right <= size && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void HeapSort(int* arr, int size) {
    while(size != 1){
        swap(arr[1], arr[size--]);
        heapify(arr, size, 1);
    }
}

int main() {
    Heap* h = new Heap(10); // Capacity set to 10
    h->insert(50);
    h->insert(30);
    h->insert(70);
    h->insert(40);
    h->insert(80);
    h->insert(100);

    cout << "Before Sorting:" << endl;
    h->print();

    HeapSort(h->arr, h->size);

    cout << "\nAfter Heap Sort:" << endl;
    h->print(); 

    return 0;
}
