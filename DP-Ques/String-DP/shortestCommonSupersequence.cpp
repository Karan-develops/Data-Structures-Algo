// LC - 1092 - HARD - Shortest Common Supersequence
// GFG - Medium - Shortest Common Supersequence
/*
In LeetCode create that string & return
In GFG only length of that string
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
// Approach 1 - Top Down - For GFG
class DP{
    int dp[1000][1000];
    int solve(string &s1,string &s2,int m,int n){
        if(m==0 || n==0) return m+n;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(s1[m-1]==s2[n-1]) return dp[m][n]=1+solve(s1,s2,m-1,n-1);
        
        return dp[m][n]=1+min(solve(s1,s2,m-1,n),solve(s1,s2,m,n-1));
    }
    public:
    int minSuperSeq(string &s1,string &s2){
        int m=s1.length();
        int n=s2.length();
        
        memset(dp,-1,sizeof(dp));
        
        return solve(s1,s2,m,n);
    }
};
// Approach 2 - Bottom Up - LeetCode
class StringDP{
    public:
    string shortestCommonSupersequence(string str1,string str2){
        int m=str1.length();
        int n=str2.length();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=i+j;
                } else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                } else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        // Make the Shortest SubS
        string scs="";
        int i=m,j=n;
        
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                scs.push_back(str1[i-1]);
                i--,j--;
            } else{
                if(dp[i-1][j]<dp[i][j-1]){
                    scs.push_back(str1[i-1]);
                    i--;
                }
                else{
                    scs.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        // Add remaining characters from both str1 and str2
        while(i>0){
            scs.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            scs.push_back(str2[j-1]);
            j--;
        }
        
        reverse(begin(scs),end(scs));
        return scs;
    }
};
int main(){
    // Output: "cabac"
    string str1="abac",str2="cab";
    // Output: "aaaaaaaa"
    string str3="aaaaaaaa",str4="aaaaaaaa";

    StringDP sol;
    cout<<sol.shortestCommonSupersequence(str1,str2)<<endl;
    cout<<sol.shortestCommonSupersequence(str3,str4);
    return 0;
}