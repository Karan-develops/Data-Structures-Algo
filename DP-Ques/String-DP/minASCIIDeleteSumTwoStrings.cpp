// LC - 712 - Medium - Minimum ASCII Delete Sum for Two Strings
#include<iostream>
#include<vector>
using namespace std;
class StringDP{
    int m,n;
    vector<vector<int>>dp;
    int solve(string &s1,string &s2,int i,int j){
        if(i>=m && j>=n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i>=m){
            return dp[i][j]=s2[j]+solve(s1,s2,i,j+1);
        } else if(j>=n){
            return dp[i][j]=s1[i]+solve(s1,s2,i+1,j);
        }
        
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(s1,s2,i+1,j+1);
        }
        
        int take_s1_i=s1[i]+solve(s1,s2,i+1,j);
        int take_s2_j=s2[j]+solve(s1,s2,i,j+1);
        
        return dp[i][j]=min(take_s1_i,take_s2_j);
    }
    public:
    int minimumDeleteSum(string s1, string s2){
        m=s1.length();
        n=s2.length();

        dp.assign(m+1,vector<int>(n+1,-1));

        return solve(s1,s2,0,0);
    }
};
int main(){
    // Output: 231
    string s1="sea",s2="eat";
    // Output: 403
    string s3="delete",s4="leet";

    StringDP sol;
    cout<<sol.minimumDeleteSum(s1,s2)<<endl;
    cout<<sol.minimumDeleteSum(s3,s4);
    return 0;
}