// LC - 3516 - Easy - Find Closest Person
#include<iostream>
using namespace std;
int findClosest(int x,int y,int z){
    int A=abs(x-z);
    int B=abs(y-z);

    if(A==B) return 0;
    else if(A<B) return 1;
    return 2;
}
int main(){
    // Output: 1
    int x=2,y=7,z=4;
    // Output: 2
    int x2=2,y2=5,z2=6;
    // Output: 0
    int x3=1,y3=5,z3=3;
    cout<<findClosest(x,y,z);
    cout<<findClosest(x2,y2,z2);
    cout<<findClosest(x3,y3,z3);
    return 0;
}