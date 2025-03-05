// Top-Down
/*#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&dp,int n){
    if(n==0 || n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(dp,n-1)+solve(dp,n-2);
}
int main(){
    int n=10;
    vector<int>dp(n+1,-1);
    cout<<solve(dp,n);
    return 0;
}*/
// Bottom-Up
#include<iostream>
using namespace std;
int main(){
    int n=10;
    int a=1,b=1,c=a+b;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    cout<<c;
    return 0;
}