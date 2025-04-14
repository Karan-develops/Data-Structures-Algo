// LC - 461 - Easy - Hamming Distance
#include<iostream>
using namespace std;
int hammingDistance(int x, int y) {
    return __builtin_popcount(x^y);
}
int main(){
    // Output: 2
    int x=1,y=4;
    // Output: 1
    int x2=3,y2=1;
    cout<<hammingDistance(x,y)<<endl;
    cout<<hammingDistance(x2,y2);
    return 0;
}