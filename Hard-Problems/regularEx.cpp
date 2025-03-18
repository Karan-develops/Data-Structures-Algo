// LC - 10 - HARD - Regular Expression Matching
// 2 Approaches - Without Memo - With Memo
#include<iostream>
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
            bool take_asterisk=solve(s,p.substr(2));
            // ab maine asterisk le liya mtlb s ek aage bhad jaega
            bool not_take=first_char_matched && solve(s.substr(1),p);

            return take_asterisk || not_take;
        }
        return first_char_matched && solve(s.substr(1),p.substr(1));
    }
    public:
    bool isMatch(string s,string p){
        return solve(s,p);
    }
};
int main(){
    // OP - false
    string s1="aa",p1="a";
    // OP - true
    string s2="aa",p2="a*";
    // OP - true
    string s3="ab",p3=".*";
    WithoutMemo sol;
    cout<<sol.isMatch(s1,p1)<<endl;
    cout<<sol.isMatch(s2,p2)<<endl;
    cout<<sol.isMatch(s3,p3);
    return 0;
}