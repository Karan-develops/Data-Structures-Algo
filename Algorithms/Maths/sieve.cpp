// Sieve of Eratosthenes
#include<iostream>
#include<vector>
using namespace std;
vector<bool> sieve(int n){
    vector<bool>isPrime(n+1,true);
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    return isPrime;
}
int main(){
    int n=10;
    int n2=50;
    
    vector<bool>v1=sieve(n);
    vector<bool>v2=sieve(n2);

    for(bool i:v1) cout<<i<<" ";
    cout<<endl;
    for(bool i:v2) cout<<i<<" ";
    return 0;
}