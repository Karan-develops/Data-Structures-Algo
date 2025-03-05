#include<iostream>
using namespace std;
class ABC{
    int x;
    int *y;
    // Bad practice, mutable is mostly used in debugging in projects
    mutable int z;
    ABC(){
        x=0;
        *y=0;
        z=0;
    }
    public:
    // Const Functions
    int getX() const{
        // x=4; -> You can assign value to data members
        return x;
    }
    // Don't make setters const because setters are used to assign values to data members
    void setX(int _val){
        x=_val;
    }
    int getY() const{
        return *y;
    }
    void setY(int _val){
        *y=_val;
    }
    // To break promise of const we can use mutable to reassign the value to z
    int getZ() const{
        z=10;
        return z;
    }
};

int main(){
    // Compiler maintains seperate member for constants to increase the efficiency
    const int x=2;
    // x=5;
    int *p=new int(2);
    cout<<*p<<endl;
    // Const data, But Non-const pointer - pointer can be reassigned
    const int *p2=new int(3);
    // Const pointer, But Non-const data
    int *const p3=new int(4);
    // Const pointer,Const Data
    const int *const p4=new int(5);
    return 0;
}