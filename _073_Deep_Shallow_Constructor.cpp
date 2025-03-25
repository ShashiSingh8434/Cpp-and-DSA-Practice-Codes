#include <iostream>
using namespace std;

class A{
    public:
    int a;
    int* b;

    // Shallow default constructor

    // A(const A &obj){
    //     this->a = obj.a;
    //     this->b = obj.b;
    // }

    // Deep Copy Constructor (best method)
    A(const A &obj){
        this->a = obj.a;
        this->b = new int(*obj.b);
    }

};

int main(){
    
    return 0;
}