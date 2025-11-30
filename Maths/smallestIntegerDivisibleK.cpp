// LC - 1015 - Medium - Smallest Integer Divisible by K
#include<iostream>
using namespace std;
int smallestRepunitDivByK(int k){
    if(k==1) return 1;
    
    if(k%2==0 || k%5==0) return -1;
    
    int rem=0;
    
    for(int i=1;i<=k;i++){
        // remainder will never exceed k-1, hence avoiding integer overflow
        rem=(rem*10+1)%k;

        if(rem==0) return i;
    }

    return -1;
}
int main(){
    // Output: 1
    int k=1;
    // Output: -1
    int k2=2;
    // Output: 3
    int k3=3;
    cout<<smallestRepunitDivByK(k)<<endl;
    cout<<smallestRepunitDivByK(k2)<<endl;
    cout<<smallestRepunitDivByK(k3);
    return 0;
}