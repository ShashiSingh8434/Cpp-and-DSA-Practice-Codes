#include <iostream>
using namespace std;

class Employee{
    public:
    int a;

    void operator << (Employee& x){
        int p = this->a;
        int q = x.a;

        cout<< p+q << endl;

    }
};

int main(){
    Employee emp1;
    Employee emp2;

    emp1.a = 10;
    emp2.a = 20;

    emp1 << emp2;

    return 0;
}