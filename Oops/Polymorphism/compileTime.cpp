// Compile Time Polymorphism
#include<iostream>
using namespace std;
// Function Overloading
class Dog{
    public:
    void show(int x){
        cout<<"Doggo has "<<x<<" Friends"<<endl;
    }
    void show(double y){
        cout<<"Doggo has $"<<y<<endl;
    }
    void show(string s){
        cout<<"Doggo's friend is "<<s<<endl;
    }
};
// Operator Overloading
class Complex{
    public:
    int real,imag;

    Complex(int r,int i): real(r),imag(i){}

    // OO
    Complex operator+(const Complex &c){
        return Complex(real+c.real,imag+c.imag);
    }
};
int main(){
    // FO
    Dog d;
    d.show(0);
    d.show(9999.99);
    d.show("No one :(");

    // OO
    Complex c1(2,3),c2(5,6);
    Complex c3=c1+c2; // uses overloaded +
    // OP - 7 9
    cout<<c3.real<<" "<<c3.imag;

    return 0;
}