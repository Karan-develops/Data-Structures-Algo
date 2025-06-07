// LC - 22 - Medium - Generate Parentheses
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    void solve(vector<string>&ans,int n,int open,int close,string output){
        if(open==0 && close==0){
            ans.push_back(output);
            return;
        }
        // include open bracket
        if(open>0){
            output.push_back('(');
            solve(ans,n,open-1,close,output);
            output.pop_back();
        }
        // include closing bracket
        if(close>open){
            output.push_back(')');
            solve(ans,n,open,close-1,output);
        }
    }
    public:
    vector<string> generateParenthesis(int n){
        vector<string>ans;
        if(n==1) return {"()"};

        int open=n,close=n;
        string output="";

        solve(ans,n,open,close,output);
        return ans;
    }
};
int main(){
    // Output: ["((()))","(()())","(())()","()(())","()()()"]
    int n=3;
    // Output: ["()"]
    int n2=1;

    BackTracking sol;
    vector<string>ans=sol.generateParenthesis(n);
    for(string &s:ans) cout<<s<<" ";
    return 0;
}