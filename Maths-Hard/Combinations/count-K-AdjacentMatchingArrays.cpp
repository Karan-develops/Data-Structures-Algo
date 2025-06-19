// LC - 3405 - HARD - Count the Number of Arrays with K Matching Adjacent Elements
#include<iostream>
#include<vector>
using namespace std;
class Maths{
    int MOD=1e9+7;
    // Iterative Binary Exponentiation T.C : O(log(b))
    int findPower(long long a, long long b){
        long long ans=1;
        a%=MOD;

        while(b>0){
            if(b%2==1){
                ans=(ans*a)%MOD;
            }
            a=(a*a)%MOD;
            b/=2;
        }
        return ans;
    }
    // nCr using Fermat's Little Theorem
    long long nCr(int n,int r,vector<long long>&factorial){
        long long numerator=factorial[n];
        long long denom1=findPower(factorial[n-r],MOD-2); //Fermat's little theorem
        long long denom2=findPower(factorial[r],MOD-2); //Fermat's little theorem

        long long ans=(((numerator*denom1)%MOD)*denom2)%MOD;
        return ans;
    }
    public:
    int countGoodArrays(int n,int m,int k){
        vector<long long>factorial(n+1,1);
        for(int i=2;i<=n;i++){
            factorial[i]=(factorial[i-1]*i)%MOD;
        }

        long long ans=nCr(n-1,k,factorial); // n-1 C k
        ans=ans*m%MOD;
        ans=ans*findPower(m-1,n-k-1)%MOD;

        return ans;
    }
};
int main(){
    // Output: 4
    int n=3,m=2,k=1;
    // Output: 6
    int n2=4,m2=2,k2=2;
    // Output: 2
    int n3=5,m3=2,k3=0;

    Maths sol;
    cout<<sol.countGoodArrays(n,m,k)<<endl;
    cout<<sol.countGoodArrays(n2,m2,k2)<<endl;
    cout<<sol.countGoodArrays(n3,m3,k3);
    return 0;
}