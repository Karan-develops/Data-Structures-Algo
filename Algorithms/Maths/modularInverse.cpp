// Modular Inverse - Fermat's Little Theorm
// b^p-2 % p, where p is modulus
#include<iostream>
#include<vector>
using namespace std;
class FermatLittle{
    const int M=1e9+7;
    // Pre-Computing Factorial
    void factorial(vector<long long>&fact){
        int n=fact.size();

        for(int i=2;i<n;i++){
            fact[i]=(fact[i-1]*i)%M;
        }
    }
    int findPower(long long a,long long b){
        if(b==0) return 1;

        long long half=findPower(a,b/2);
        long long ans=(half*half)%M;

        if(b&1) ans=(ans*a)%M;
        return ans;
    }
    public:
    int modularNCR(int n,int r){
        if(r<0 || r>n) return 0;

        // Pre-Computing Factorial
        vector<long long>fact(n+1,1);
        factorial(fact);

        long long a=fact[n]; // Numerator
        long long b=(fact[r]*fact[n-r])%M;
        
        return (a*findPower(b,M-2))%M;
    }
};
int main(){
    // OP - 10
    int n=5,r=2;
    // OP - 252
    int n2=10,r2=5;

    FermatLittle sol;
    cout<<sol.modularNCR(n,r)<<endl;
    cout<<sol.modularNCR(n2,r2);
    return 0;
}