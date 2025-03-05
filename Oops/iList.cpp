// Initialiser List
#include<iostream>
using namespace std;
class ABC{
    int x;
    int *y;
    const int z;
    public:
    // Old Constructor
    // ABC(int _x,int _y,int _z=0){
    //     x=_x;
    //     y=new int(_y);
    //     z=_z; //-> z is const in old style constructor you can't re-assign the const data
    // }
    // New Style
    // 1)
    // ABC(int _x,int _y,int _z):x(_x),y(new int(_y)),z(_z) {}
    // 2)
    ABC(int _x,int _y,int _z):x(_x),y(new int(_y)),z(_z) {
        cout<<"Initialised the data members.";
        // z=5; -> Although here also you can't re-assign the const data it's only done one time
    }
};
int main(){
    ABC a(1,2,3);
    return 0;
}