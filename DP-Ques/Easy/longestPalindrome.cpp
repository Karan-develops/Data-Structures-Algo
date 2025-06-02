// LC - 5 - Medium - Longest Palindromic Substring
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class BruteForce{
public:
    bool isPalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++,end--;
        }
        return true;
    }
    string longestPalindrome(string s){
        int l=s.length();
        string ans="";
        for(int i=0;i<l;i++){
            for(int j=i;j<l;j++){
                if(isPalindrome(s,i,j)){
                    string t=s.substr(i,j-i+1);
                    ans=t.size()>ans.size()?t:ans;
                }
            }
        }
        return ans;
    }
};
class DP{
public:
    int dp[1001][1001];
    bool solve(string &s,int i,int j){
        if(i>=j) return dp[i][j]=1;

        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s[j]){
            return dp[i][j]=solve(s,i+1,j-1);
        }
        return dp[i][j]=0;
    }
    string longestPalindrome(string s){
        int n=s.length();

        memset(dp,-1,sizeof(dp));
        int maxLen=INT_MIN;
        int start=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if((j-i+1)>maxLen){
                        maxLen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
int main(){
    // Output: "bab"
    string s="babad";
    // Output: "bb"
    string s2="cbbd";
    
    DP sol;
    cout<<sol.longestPalindrome(s)<<endl;
    cout<<sol.longestPalindrome(s2);
    return 0;
}