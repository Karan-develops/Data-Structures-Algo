// LC - 10 - HARD - Regular Expression Matching
#include<iostream>
#include<vector>
using namespace std;
class StringDP{
    int m,n;
    vector<vector<int>>dp;
    bool solve(string s,string p,int i,int j){
        if(j==n){
            return i==m;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        bool first_char_matched=false;
        if(i<m && (s[i]==p[j] || p[j]=='.')){
            first_char_matched=true;
        }
        
        // Best eg to understand : s = "aaab", p = "a*b"
        if(j+1<n && p[j+1]=='*'){
            // pattern ab second index se jaega -> p = "b"
            bool skip=solve(s,p,i,j+2);
            // ab maine asterisk le liya mtlb s ek aage bhad jaega
            bool take=first_char_matched && solve(s,p,i+1,j);

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
    string s2="aa",p2="a*";
    // Output: true
    string s3="ab",p3=".*";

    StringDP sol;
    cout<<sol.isMatch(s,p)<<endl;
    cout<<sol.isMatch(s2,p2)<<endl;
    cout<<sol.isMatch(s3,p3);
    return 0;
}