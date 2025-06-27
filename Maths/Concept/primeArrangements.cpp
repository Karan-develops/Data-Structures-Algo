// LC - 1175 - Easy - Prime Arrangements
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Maths{
    const int MOD=1e9+7;
    int countPrimes(int n){
        vector<bool>sieve(n+1,true);
        sieve[0]=false;
        sieve[1]=false;

        for(int i=2;i*i<=n;i++){
            if(sieve[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    sieve[j]=false;
                }
            }
        }
        return count(begin(sieve),end(sieve),true);
    }
    long long factorial(int a){
        long long ans=1;
        for(int i=2;i<=a;i++){
            ans=(ans*i)%MOD;
        }
        return ans;
    }
    public:
    int numPrimeArrangements(int n){
        int primeCount=countPrimes(n);
        long long ans=(factorial(primeCount)*factorial(n-primeCount))%MOD;
        return ans;
    }
};
int main(){
    // Output: 12
    int n=5;
    // Output: 682289015
    int n2=100;
}