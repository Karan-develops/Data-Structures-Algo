// LC - 342 - Easy - Power of Four
// Topics --> Math, Bit Manipulation, Recursion
#include<iostream>
#include<math.h>
using namespace std;
class PowerFour{
    public:
    bool bitMagic(int n){
        return n>0 && (n&(n-1))==0 && (n-1)%3==0;
    }
    bool isPowerOfFour(int n){
        if(n<=0) return false;
        
        /*
        4^a = n
        a = log(n) to base 4
        a = log(n) to base e / log(4) to base e
        */
        int a=(log(n)/log(4)); 
        
        if(n==pow(4,a)) return true;
        
        return false;
    }
    bool recursion(int n){
        if(n==0) return false;
        if(n==1) return true;

        if(n%4!=0) return false;

        return recursion(n/4);
    }
};
int main(){
    // Output: true
    int n=16;
    // Output: false
    int n2=5;
    // Output: true
    int n3=1;

    PowerFour sol;
    cout<<sol.bitMagic(n)<<endl;
    cout<<sol.bitMagic(n2)<<endl;
    cout<<sol.bitMagic(n3);
    return 0;
}