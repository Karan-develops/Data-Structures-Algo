// LC - 2894 - Easy - Divisible and Non-divisible Sums Difference
#include<iostream>
using namespace std;
int differenceOfSums(int n,int m){
    int k=n/m;
    return n*(n+1)/2-m*(k)*(k+1);
}
int main(){
    // Output: 19
    int n=10,m=3;
    // Output: 15
    int n2=5,m2=6;
    // Output: -15
    int n3=5,m3=1;
    cout<<differenceOfSums(n,m)<<endl;
    cout<<differenceOfSums(n2,m2)<<endl;
    cout<<differenceOfSums(n3,m3);
    return 0;
}