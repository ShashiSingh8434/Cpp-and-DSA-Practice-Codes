// #include <iostream>
// #include <deque>
// using namespace std;


// -------------This code is written by my logic and it might be incorrect-----------------



// void print(deque<int> q){
//     while(!q.empty()){
//         cout<<q.front()<<" ";
//         q.pop_front();
//     }
// }

// void find_first_negative(deque<int> d, deque<int> &ans){
//     while (!d.empty()){
//         if(d.front()<0){
//             ans.push_back(d.front());
//             d.pop_front();

//             return;
//         }
//         else{
//             d.pop_front();
//         }
//     }
//     ans.push_back(0);
// }

// deque<int> slidingWindow(int arr[], int size, int k){
//     deque<int> d;
//     deque<int> ans;

//     for (int i = 0; i < k; i++){
//         d.push_back(arr[i]);
//     }

//     int i = k;
//     while(i <= size){
//         find_first_negative(d,ans);
//         d.pop_front();
//         d.push_back(arr[i]);

//         i++;
//     }
//     find_first_negative(d,ans);

//     return ans;    
// }

// int main(){
//     int arr[] = {1,-2,3,8,3,-4,7,2};
    
//     deque<int> res = slidingWindow(arr,7,4);
//     print(res);

//     return 0;
// }