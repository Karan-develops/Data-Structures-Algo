// Yes we can make a constructor private
// It can be accessed by friend of that class
#include<iostream>
using namespace std;
class Box{
    Box(){
        cout<<"Inside the Box"<<endl;
    }
    friend class BoxFactory;
};
class BoxFactory{
    public:
    BoxFactory(){
        cout<<"This is Box-Factory"<<endl;
        Box b;
    }
};
int main(){
    BoxFactory b;
    return 0; 
}