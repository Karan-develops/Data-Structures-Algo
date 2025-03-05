// Macros are used by compiler tool called pre-processor
// The preprocessor 
#include<iostream>
using namespace std;
// Pre-Processor will replace all the places where PI is written with it's value
#define PI 3.14
#define MAXX x>y?x:y
float circleArea(int r){
    return PI*r*r;
}
float circlePerimeter(int r){
    return 2*PI*r;
}
int f1(int x,int y){
    return MAXX;
}
int main(){
    cout<<circleArea(2)<<endl;
    cout<<circlePerimeter(2)<<endl;
    cout<<f1(2,3)<<endl;
    cout<<f1(5,3)<<endl;
    return 0;
}