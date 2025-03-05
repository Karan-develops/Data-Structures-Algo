// No constructor can't be virtual but destructor can be virtual
// Tip :- Making a Base destructor virtual is good practice because if didn't it can cause memory leaks
#include<iostream>
using namespace std;
class Base{
    public:
    Base(){
        cout<<"Base ctor"<<endl;
    }
    virtual ~Base(){
        cout<<"Base dtor"<<endl;
    }
};
class Derived:public Base{
    public:
    Derived(){
        cout<<"Derived ctor"<<endl;
    }
    ~Derived(){
        cout<<"Derived dtor"<<endl;
    }
};
int main(){
    Base *b=new Derived();
    delete b;
    return 0;
}