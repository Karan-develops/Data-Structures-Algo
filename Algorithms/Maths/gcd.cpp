// Find GCD ( Greatest Common Divisor )
// Built-in - Recursive - Iterative
#include<iostream>
#include<numeric>
using namespace std;
class GCD{
    int solve(int a,int b){
        if(b==0) return a;

        return solve(b,a%b);
    }
    public:
    // Approach 1
    int findGCDRecursive(int a,int b){
        return solve(a,b);
    }
    // Approach 2
    int findGCDIterative(int a,int b){
        while(b){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    // Approach 3
    int builtinGCD(int a,int b){
        return gcd(a,b);
    }
};
int main(){
    int a=36;
    int b=60;

    GCD sol;
    cout<<sol.builtinGCD(a,b)<<endl;
    cout<<sol.findGCDRecursive(a,b)<<endl;
    cout<<sol.findGCDIterative(a,b);
    return 0;
}