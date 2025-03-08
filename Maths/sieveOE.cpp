// Sieve of Eratosthenes
#include<iostream>
#include<vector>
using namespace std;
void sieveOfEratosthenes(int n){
    vector<int>isPrime(n+1,true);
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]==true){
            for(int j=i;i*j<=n;j++){
                isPrime[i*j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]==true) cout<<i<<" ";
    }
}
int main(){
    int n=11;
    sieveOfEratosthenes(n);
    return 0;
}