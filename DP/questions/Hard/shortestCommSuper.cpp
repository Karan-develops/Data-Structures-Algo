#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string shortestCommonSupersequence(string str1, string str2) {
    int m=str1.length(),n=str2.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0) dp[i][j]=i+j;
            else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
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
    reverse(scs.begin(),scs.end());
    return scs;
}
int main(){
    string s1="abac";
    string s2="cab";
    cout<<shortestCommonSupersequence(s1,s2);
    return 0;
}