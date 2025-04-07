// LC - 50 - Medium - Pow(x, n)
#include<iostream>
using namespace std;
class Solution{
    double solve(double x,long n){
        if(n==0) return 1;
        if(n<0) return solve(1/x,-n);
        if(n%2==0) return solve(x*x,n/2);
        else return x*solve(x*x,(n-1)/2);
    }
    public:
    double myPow(double x,int n){
        // Converting into long bcoz int can't handle large values
        return solve(x,(long)n);
    }
};
int main(){
    // Output: 1024.00000
    double x=2.00000;
    int n=10;
    // Output: 9.26100
    double x2=2.10000;
    int n2=3;
    // Output: 0.25000
    double x3=2.00000;
    int n3=-2;
    Solution sol;
    cout<<sol.myPow(x,n)<<endl;
    cout<<sol.myPow(x2,n2)<<endl;
    cout<<sol.myPow(x3,n3);
    return 0;
}