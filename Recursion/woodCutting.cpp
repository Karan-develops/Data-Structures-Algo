#include<iostream>
using namespace std;
int solve(int n,int x,int y,int z){
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    int maxi=INT_MIN;
    int a=solve(n-x,x,y,z)+1;
    int b=solve(n-y,x,y,z)+1;
    int c=solve(n-z,x,y,z)+1;
    maxi=max(a,max(b,c));
    return maxi;
}
int main(){
    int n=7;
    int x=3;
    int y=3;
    int z=2;
    int ans=solve(n,x,y,z);
    if(ans<0) ans=0;
    cout<<"Answer is:"<<ans;
    return 0;
}