// LC - 10 - HARD - Regular Expression Matching
// 2 Approaches - Without Memo - With Memo
#include<iostream>
#include<cstring>
using namespace std;
class WithoutMemo{
    bool solve(string s,string p){
        if(p.length()==0){
            return s.length()==0;
        }
        bool first_char_matched=false;
        if(s.length()>0 && (s[0]==p[0] || p[0]=='.')){
            first_char_matched=true;
        }

        //Best example to understand : s = "aaab", p = "a*b"
        if(p.length()>=2 && p[1]=='*'){
            // pattern ab second index se jaega -> p = "b"
            bool not_take_asterisk=solve(s,p.substr(2));
            // ab maine asterisk le liya mtlb s ek aage bhad jaega
            bool take_asterisk=first_char_matched && solve(s.substr(1),p);
            
            return take_asterisk || not_take_asterisk;
        }
        return first_char_matched && solve(s.substr(1),p.substr(1));
    }
    public:
    bool isMatch(string s,string p){
        return solve(s,p);
    }
};
class WithMemo{
    int dp[21][21];
    bool solve(string s,string p,int i,int j){
        if(j==p.length()){
            return i==s.length();
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        bool first_char_matched=false;
        if(i<s.length() && (s[i]==p[j] || p[j]=='.')){
            first_char_matched=true;
        }
        
        //Best example to understand : s = "aaab", p = "a*b"
        if(j+1<p.length() && p[j+1]=='*'){
            // pattern ab second index se jaega -> p = "b"
            bool not_take=solve(s,p,i,j+2);
            // ab maine asterisk le liya mtlb s ek aage bhad jaega
            bool take_asterisk=first_char_matched && solve(s,p,i+1,j);

            return dp[i][j]=not_take || take_asterisk;
        }
        return dp[i][j]=first_char_matched && solve(s,p,i+1,j+1);
    }
    public:
    bool isMatch(string s,string p){
        memset(dp,-1,sizeof(dp));
        return solve(s,p,0,0);
    }
};
int main(){
    // OP - false
    string s1="aa",p1="a";
    // OP - true
    string s2="aa",p2="a*";
    // OP - true
    string s3="ab",p3=".*";
    WithMemo sol;
    cout<<sol.isMatch(s1,p1)<<endl;
    cout<<sol.isMatch(s2,p2)<<endl;
    cout<<sol.isMatch(s3,p3);
    return 0;
}