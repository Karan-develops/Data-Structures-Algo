#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

// This is like interface
// abstract class
class Bird{
    public:
    virtual void eat()=0;
    virtual void sleep()=0;
};

class sparrow:public Bird{
    private:
    void eat(){
        std::cout<<"Sparrow is eating"<<std::endl;
    }
    void sleep(){
        std::cout<<"Sparrow is sleeping"<<std::endl;
    }
};
class eagle:public Bird{
    private:
    void eat(){
        std::cout<<"Eagle is eating"<<std::endl;
    }
    void sleep(){
        std::cout<<"Eagle is sleeping"<<std::endl;
    }
};

#endif // BIRD_H
