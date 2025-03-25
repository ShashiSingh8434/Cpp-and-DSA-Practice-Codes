#include <iostream>
using namespace std;

class Animal{
    public:
    // void speak(){
    //     cout<<"speak"<<endl;
    // }

    virtual void speak(){    
        // this makes sure that always inherited classses functions runs first and is put as high preferances
        cout<<"speak"<<endl;
    }
};

class Dog : public Animal{
    public:
    void speak(){
        cout<<"barking"<<endl;
    }
};

int main(){

    Animal* animal = new Animal();
    Dog* dog = new Dog();

    //upcasting
    Animal* animal_dog = new Dog();  //--> function is always runned of the object (i.e. dog) here

    // downcasting
    Dog* dog_animal = (Dog*) new Animal(); 

    animal->speak();
    dog->speak();

    animal_dog->speak();
    dog_animal->speak();
    
    return 0;
}