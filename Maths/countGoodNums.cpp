// LC - 1922 - Medium - Count Good Numbers
// Involves concept of LC 50 - Pow(x,n)
// Tips :- No of even indices -> (n+1)/2
// No of odd indices -> n/2
#include<iostream>
using namespace std;
const int M=1e9+7;
// Fast Exponentiation
long long findPower(long long a,long long b){
    if(b==0) return 1;

    long long half=findPower(a,b/2);
    long long ans=(half*half)%M;

    if(b & 1) ans=(ans*a)%M;
    return ans;
}
int countGoodNumbers(long long n){
    return (long long)findPower(5,(n+1)/2)*findPower(4,n/2)%M;
}
int main(){
    // Output: 5
    int n=1;
    // Output: 400
    int n2=4;
    // Output: 564908303
    int n3=50;
    cout<<countGoodNumbers(n)<<endl;
    cout<<countGoodNumbers(n2)<<endl;
    cout<<countGoodNumbers(n3);
    return 0;
}