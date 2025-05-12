#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> dist, vector<int> cost){
    int start = 0;
    int balance = 0;
    int deficit = 0;

    for(int i = 0; i<dist.size(); i++){
        balance += dist[i]-cost[i];

        if(balance < 0){
            deficit += balance; 
            balance = 0;
            start = i+1;            
        }
    }

    if(deficit + balance > 0){
        return start;
    }else{
        return -1;
    }
}

int main(){
     
    return 0;
}