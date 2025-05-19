#include <iostream>
#include <queue>
using namespace std;

/*
Here we are trying to solve the probelm in less space complexity by making a max heap using priority queue then making it only of size to store k elements using logic to get the kth smallest element by accesing the top of the max heap which will be the kth smallest automatically by logic if you understand 😉

TC : O(n)
SC : O(k)
*/


int KthSmallestElement(int arr[], int n, int k){
    priority_queue<int> pq;

    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    return pq.top();
}

int main(){
    int arr[] = {10,5,20,4,15};
    cout<<KthSmallestElement(arr, 5, 2);
    return 0;
}