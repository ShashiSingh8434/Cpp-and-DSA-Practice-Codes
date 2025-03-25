#include <iostream>
using namespace std;

class Animal{
    public:
    Animal(){
        cout<<"animal constructor"<<endl;
    }
};

class Dog : public Animal{
    public:
    Dog(){
        cout<<"dog constructor"<<endl;
    }
};

int main(){

    Animal* animal = new Animal();
    cout<<endl<<endl;

    Dog* dog = new Dog();
    cout<<endl<<endl;

    //upcasting
    Animal* animal_dog = new Dog();  
    cout<<endl<<endl;

    // downcasting
    Dog* dog_animal = (Dog*) new Animal(); 
    cout<<endl;

    
    return 0;
}