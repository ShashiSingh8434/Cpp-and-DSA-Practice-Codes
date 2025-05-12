#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> solution(vector<int> &nums, int k){
    deque<int> d;
    vector<int> ans;

    //first window
    for(int i=0; i<k; i++){
        while(!d.empty() && nums[i]>nums[d.back()]){
            d.pop_back();
        }
        d.push_back(i);
    }

    // pushing first ans
    ans.push_back(nums[d.front()]);

    //remaining elements
    for(int i=k; i<nums.size(); i++){
        //removing outside of windown elements
        if(!d.empty() && i-d.front() >= k){
            d.pop_front();
        }

        // again same process
        while(!d.empty() && nums[i]>nums[d.back()]){
            d.pop_back();
        }
        d.push_back(i);

        //pushing value in ans
        ans.push_back(nums[d.front()]);
    }
    return ans;
}


int main(){
    vector<int> a;
    a.push_back(2);
    a.push_back(6);
    a.push_back(4);
    a.push_back(2);
    a.push_back(-1);
    a.push_back(17);
    vector<int> ans = solution(a,3);

    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    
    return 0;
}