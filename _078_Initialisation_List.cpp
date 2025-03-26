#include <iostream>
using namespace std;

class A{
    int a;
    const int b;

    public:

    //-------------OLD METHOD CONSTRUCTOR--------------------------------
    // A(int _a, int _b){
    //     a = _a;
    //     //b = _b; // here error gives since it is const in initialisation at the top and in this constructor here it is being reassigned not intialising the b variable
    // }

    //------------NEW METHOD---------------------------------------------

    A(int _a, int _b) : a(_a), b(_b) {}  
    // this method intialised the value of b even though it was const 

};


int main(){
    
    return 0;
}