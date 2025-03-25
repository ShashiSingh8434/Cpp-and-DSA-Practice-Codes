#include <iostream>
using namespace std;

int x = 10; // global variable 

// it can be accesses anywhere in the program using :: scope operator
// ex:-  cout << ::x << endl;

int main(){
    int x = 1;
    cout << x << endl;
    cout << ::x << endl;
    return 0;
}