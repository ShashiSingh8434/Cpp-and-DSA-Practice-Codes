#include <iostream>
using namespace std;

class abc{
    public:
    static int x;

    static void print(){
        cout<<x<<endl;
    }
};

int abc::x;  // compulsory to initialise the static variable outside the class since it doesn't belong to a class object.

int main(){
    abc a;

    a.x = 10;
    abc::x = 123;

    a.print();
    abc::print();

    return 0;
}