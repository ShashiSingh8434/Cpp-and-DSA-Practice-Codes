#include <iostream>
#include <deque>
using namespace std;

void print(deque<int> q){
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop_front();
    }
}

deque<int> slidingWindow(int arr[], int n, int k){
    deque<int> negIndex;  // stores indices of negative numbers
    deque<int> ans;

    int i = 0, j = 0;

    while (j < n){
        // If current element is negative, store its index
        if (arr[j] < 0)
            negIndex.push_back(j);

        // If we have hit window size
        if (j - i + 1 == k){
            if (!negIndex.empty())
                ans.push_back(arr[negIndex.front()]);
            else
                ans.push_back(0);

            // Remove indices which are out of this window
            if (!negIndex.empty() && negIndex.front() == i)
                negIndex.pop_front();

            i++;
        }
        j++;
    }
    return ans;
}

int main(){
    int arr[] = {1, -2, 3, 8, 3, -4, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    deque<int> res = slidingWindow(arr, n, k);
    print(res);

    return 0;
}
