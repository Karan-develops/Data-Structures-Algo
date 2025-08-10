// LC - 231 - Easy - Power of Two
#include<iostream>
using namespace std;
bool isPowerOfTwo(int n){
    return (n>0) && ((n&(n-1))==0);
}
int main(){
    // Output: true
    int n=1;
    // Output: true
    int n2=16;
    // Output: false
    int n3=3;
    cout<<isPowerOfTwo(n)<<endl;
    cout<<isPowerOfTwo(n2)<<endl;
    cout<<isPowerOfTwo(n3);
    return 0;
}