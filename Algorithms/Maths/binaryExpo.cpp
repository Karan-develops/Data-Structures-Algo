// Binary Exponentiation - Log(n)
#include<iostream>
using namespace std;
class BinaryExponentiation{
    int solve(int n,int power){
        if(power==0) return 1;
        
        long long half=solve(n,power/2);
        if(power%2==0) return half*half;
        return n*half*half; 
    }
    double solve2(double x,long n){
        if(n==0) return 1;
        if(n<0) return solve(1/x,-n);
        if(n%2==0) return solve(x*x,n/2);
        else return x*solve(x*x,(n-1)/2);
    }
    public:
    int binaryExpoRecursive(int n,int p){
        return solve(n,p);
    }
    double binaryExpoRecursiveLong(double x,int n){
        // Converting into long bcoz int can't handle large values
        return solve(x,(long)n);
    }
    long long binaryExpoIterative(int n,int p){
        long long ans=1;
        while(p>0){
            if(p&1) ans*=n;
            n*=n;
            p>>=1; // Divide by 2
        }
        return ans;
    }
};
int main(){
    int n=5;
    int p=3;
    BinaryExponentiation be;
    cout<<be.binaryExpoRecursive(n,p)<<endl;
    cout<<be.binaryExpoIterative(n,p);
    return 0;
}