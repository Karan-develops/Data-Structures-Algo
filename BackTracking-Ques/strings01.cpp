// LC - 3211 - Medium - Generate Binary Strings Without Adjacent Zeros
#include<iostream>
#include<vector>
using namespace std;
class Recursion{
    int N;
    void solve(vector<string>&ans,string temp){
        if(temp.size()==N){
            ans.push_back(temp);
            return;
        }

        if(temp.empty() || temp.back()=='1'){
            solve(ans,temp+'0');
        }
        solve(ans,temp+'1');
    }
    public:
    vector<string> validStrings(int n){
        N=n;
        vector<string>ans;

        solve(ans,"");
        return ans;
    }
};
int main(){
    // Output: ["010","011","101","110","111"]
    int n=3;
    // Output: ["0","1"]
    int n2=1;

    Recursion sol;
    vector<string>ans=sol.validStrings(n);
    for(string &i:ans) cout<<i<<" ";
    return 0;
}