// GFG - Medium - Interleaved Strings
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Top Down (Rec+Memo) - TLE
class DP{
    int m,n,o;
    vector<vector<vector<int>>>dp;
    bool solve(string &s1,string &s2,string &s3,int i,int j,int k){
        if(k==o && i==m && j==n) return true;
        
        if(k>o) return false;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        bool ans=false;
        
        if(s1[i]==s3[k]){
            bool takeI=solve(s1,s2,s3,i+1,j,k+1);
            
            ans=ans || takeI;
        }
        
        if(s2[j]==s3[k]){
            bool takeJ=solve(s1,s2,s3,i,j+1,k+1);
            
            ans=ans || takeJ;
        }
        
        return dp[i][j][k]=ans;
    }
    public:
    bool isInterleave(string &s1,string &s2,string &s3){
        m=s1.length();
        n=s2.length();
        o=s3.length();

        if(m+n!=o) return false;
        
        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(o+1,-1)));
        
        return solve(s1,s2,s3,0,0,0);
    }
};
// Approach 2 - Better Version - ACCEPTED
class BetterDP{
    int m,n,o;
    vector<vector<int>>dp;
    bool solve(string &s1,string &s2,string &s3,int i,int j){
        int k=i+j;
        
        if(k==o) return (i==m && j==n);
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool ans=false;
        
        if(i<m && s1[i]==s3[k]){
            ans=ans || solve(s1,s2,s3,i+1,j);
        }
        
        if(j<n && s2[j]==s3[k]){
            ans=ans || solve(s1,s2,s3,i,j+1);
        }
        
        return dp[i][j]=ans;
    }
    public:
    bool isInterleave(string s1,string s2,string s3){
        m=s1.size();
        n=s2.size();
        o=s3.size();
        
        if(m+n!=o) return false;
        
        dp.assign(m+1,vector<int>(n+1,-1));
        
        return solve(s1,s2,s3,0,0);
    }
};
int main(){
    // Output: true
    string s1="AAB",s2="AAC",s3="AAAABC"; 
    // Output: true
    string s4="AB",s5="C",s6="ACB"; 
    // Output: false
    string s7="YX",s8="X",s9="XXY";

    BetterDP sol;
    cout<<sol.isInterleave(s1,s2,s3)<<endl;
    cout<<sol.isInterleave(s4,s5,s6)<<endl;
    cout<<sol.isInterleave(s7,s8,s9);
    return 0;
}