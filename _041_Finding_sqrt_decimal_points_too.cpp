#include <iostream>
using namespace std;

float findSqrt(int n,int p){
    int s = 0;
    int e = n;
    int mid = s + (e-s)/2;
    float ans = -1;

    float step = 0.1;

    while(s<=e){
        if(mid*mid == n){
            return mid;
        }

        if(mid*mid < n){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    float final = 0;

    for (int i = 1; i <= p; i++){
        for (int j = 1; j < 10; j++){
            if(((ans+j*step)*(ans+j*step))<n){
                final = j*step;
            }
            else{
                break;
            }
        }        
        step = (step/10);
        ans = ans+final;
    }
    return ans;
}

int main(){
    cout<<"Enter the number: ";
    int number;
    cin>>number;

    cout<<"Enter the precision point: ";
    int precision;
    cin>>precision;

    float ans = findSqrt(number,precision);

    cout<<ans;

    return 0;
}