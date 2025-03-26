#include <iostream>
using namespace std;

class Lol{
    private:

    int x;
    mutable int y; // if we want the variable to change even inside const func we use mutable keyword

    public:

    int getx() const{   // const function
        // x = 12;  gives error
        return x;
    }

    int gety() const{
        y = 10;
        return y;
    }
};

void display(const Lol &lol){
    // this function can only call const function since the argument is taken as const
}

int main(){
// @ Const DATA---------------------------------------------------------

    const int a = 1;
    // a = 1;  // cannot be reassigned

// @ Const DATA, Non-Const POINTER-------------------------------------

    // The thing after star (*) becomes immutable i.e const int *b  

    const int *b = new int(2);  // first way
    int const *_b = new int(2); // second way 

    // *b = 4;  cannot be assigned since the data is const
    int _b_var = 22;
    b = &_b_var;     // pointer can be modified

// @ Non-Const DATA, Const POINTER ------------------------------------

    int *const c = new int(3);

    *c = 33; // can be modified 
    int _c_var = 333;
    // c = &_c_var;  cannot be assigned

// @ Const DATA, Const POINTER ----------------------------------------

    const int *const d = new int (4);

    // *d = 44; cannot do
     
    int _d = 444;
    // d = &_d; cannot do 

    return 0;
}