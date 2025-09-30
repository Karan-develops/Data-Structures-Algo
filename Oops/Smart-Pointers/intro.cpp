// Intro
#include<iostream>
#include<memory>
using namespace std;
int main(){
    unique_ptr<int[]>nums=make_unique<int[]>(100);

    // use nums..
    return 0;
} // Automatically freed, no leaks