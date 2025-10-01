// Run Time Polymorphism
#include<iostream>
using namespace std;
class Animal{
    public:
    // virtual fn
    virtual void sound(){
        cout<<"Animal ko bhuk lagi h"<<endl;
    }
};
class Dog:public Animal{
    public:
    void sound() override{
        cout<<"Doggi ko bhul lagi h"<<endl;
    }
};
class Cat:public Animal{
    public:
    void sound() override{
        cout<<"Idk what she wants"<<endl;
    }
};
// Real Advantage
/*
We can generic fns
void makeSound(Animal* a) {
    a->sound();   // will call Dog::sound, Cat::sound, etc.
}
*/
int main(){
    Animal *a; // base class ptr
    /*
    a->sound();
    This crashes program for now its only pointing to a class not a valid object
    */ 

    Dog d;
    Cat c;
    
    a=&d;
    a->sound();

    a=&c;
    c.sound();

    return 0;
}