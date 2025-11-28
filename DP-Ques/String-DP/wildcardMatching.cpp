// LC - 44 - HARD - Wildcard Matching
#include<iostream>
#include<vector>
using namespace std;
class StringDP{
    int m,n;
    vector<vector<int>>dp;
    bool solve(string &s,string &p,int i,int j){
        if(j>=n) return i==m;

        if(dp[i][j]!=-1) return dp[i][j];

        bool first_char_matched=false;
        if(i<m && (s[i]==p[j] || p[j]=='?')){
            first_char_matched=true;
        }
        
        // Best example to understand : s = "aaab", p = "a*b"
        if(p[j]=='*'){
            // * means match empty
            bool skip=solve(s,p,i,j+1);
            // or match one char, so move in s
            bool take=(i<m) && solve(s,p,i+1,j);
            
            return dp[i][j]=skip || take;
        }

        return dp[i][j]=first_char_matched && solve(s,p,i+1,j+1);
    }
    public:
    bool isMatch(string s,string p){
        m=s.length();
        n=p.length();

        dp.assign(m+1,vector<int>(n+1,-1));

        return solve(s,p,0,0);
    }
};
int main(){
    // Output: false
    string s="aa",p="a";
    // Output: true
    string s2="aa",p2="*";
    // Output: false
    string s3="cb",p3="?a";

    StringDP sol;
    cout<<sol.isMatch(s,p)<<endl;
    cout<<sol.isMatch(s2,p2)<<endl;
    cout<<sol.isMatch(s3,p3);
    return 0;
}