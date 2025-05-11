#include <iostream>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

vector<int> prevSmallest(vector<int> &v){
    vector<int> ans(v.size());
    stack<int> s;    

    s.push(-1);

    for(int i = 0; i<v.size() ; i++){
        int curr = v[i];

        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }

        ans[i] = (s.top());
        s.push(i);        
    }

    return ans;
}

vector<int> nextSmallest(vector<int> &v){
    
    vector<int> ans(v.size());
    stack<int> s;    

    s.push(-1);

    for(int i=v.size()-1; i>=0; i--){
        int curr = v[i];

        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }

        ans[i] = (s.top());
        s.push(i);       
    }

    return ans; 
}

int getMaxArea(vector<int> &a){
     
    vector<int> prev = prevSmallest(a);
    vector<int> next = nextSmallest(a);

    int maxArea = INT_MIN;

    for(int i=0; i<a.size(); i++){
        if(next[i]==-1){
            next[i] = a.size();
        }

        int length = a[i];
        int width = next[i] - prev[i] - 1;
    
        int area = length * width;
        maxArea = max(area, maxArea); 
    }
    return maxArea;

}

int main(){
    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    
    cout<<getMaxArea(v);
    return 0; 
}