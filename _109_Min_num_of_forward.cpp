#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// -------------- useless for revision -----------------

// the question here is to get the least element among the element which are in front of the element and also should be less than the num itself i.e

// 2  1  4  3
// here from 2 the least element in front from it is 1
// then from 1 there are no element which are smaller than it so -1
// from 4 the 3 is the smallest
// then from 3 there are no number to compare so -1

// hence the ans is  "1 -1  3 -1"

int main(){
    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    
    vector<int> ans;
    stack<int> s;    

    s.push(-1);

    for(int i=(4-1); i>=0; i--){
        int curr = v[i];

        while(s.top() >= curr){
            s.pop();
        }

        ans.push_back(s.top());
        s.push(curr);        
    }

    reverse(ans.begin(),ans.end()); // either reverse the ans vector or print it in reverse so that to get the desired result

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}