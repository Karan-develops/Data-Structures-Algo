// Hiding all complex data
// Easier to scale the program
#include<iostream>
#include "bird.h"
using namespace std;
void birdIsDoingSomething(Bird *bird){
    bird->eat();
    bird->sleep();
}
int main(){
    Bird *b=new eagle();
    birdIsDoingSomething(b);
    return 0;
}