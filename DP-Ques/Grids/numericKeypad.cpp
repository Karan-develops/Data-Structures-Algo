// GFG - Mobile numeric keypad
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class DP{
    int dp[4][3][16];
    int solve(int i,int j,int n){
        if(i<0 || i>=4 || j<0 || j>=3 || (i==3 && (j==0 || j==2))){
            return 0;
        }
        
        if(n==1) return dp[i][j][n]=1;
        
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        
        int ans=0;
        ans+=solve(i,j,n-1)+
             solve(i-1,j,n-1)+
             solve(i,j-1,n-1)+
             solve(i+1,j,n-1)+
             solve(i,j+1,n-1);
             
        return dp[i][j][n]=ans;
    }
    public:
    int getCount(int n){
        int ans=0;
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans+=solve(i,j,n);
            }
        }
        return ans;
    }
};
int main(){
    // Output: 10
    int n=1;
    // Output: 36
    int n2=2;

    DP sol;
    cout<<sol.getCount(n)<<endl;
    cout<<sol.getCount(n2);
    return 0;
}