/*
→ A pure virtual function is a virtual function with = 0.
→ A class that has at least one pure virtual function becomes an abstract 
  class → it cannot be instantiated, only inherited.

→ This enforces polymorphism, because every derived class must override the function.
*/
#include<iostream>
using namespace std;
class Animal{
    public:
    virtual void sound()=0;
};
// Dog class must override sound()
class Dog:public Animal{
    public:
    void sound() override{
        cout<<"Doggi ko bhul lagi h"<<endl;
    }
};
// Cat class must override sound()
class Cat:public Animal{
    public:
    void sound() override{
        cout<<"Idk what she wants"<<endl;
    }
};
int main(){
    // Animal a; Not allowed (abstract class)
    Animal* a;

    Dog d;
    Cat c;

    a=&d;
    a->sound();

    a=&c;
    a->sound();

    return 0;
}