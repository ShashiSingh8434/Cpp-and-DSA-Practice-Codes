#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec ;
    int ans = sizeof(vec)/sizeof(bool);
    cout<<ans<<endl;

    vec.push_back(5);
    vec.push_back(6);

    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;

    vec.pop_back();
    return 0;
}