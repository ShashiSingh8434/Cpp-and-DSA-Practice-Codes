#include <iostream>
using namespace std;

class A{
    private:
    int x;

    public:
    void setx(int a){
        this->x = a;
    }

    friend class B;

};

class B{
    public:
    void print(A a){
        cout<<a.x<<endl;
    }

    
};

int main(){
    A a;
    a.setx(10);

    B b;
    b.print(a);

    return 0;
}