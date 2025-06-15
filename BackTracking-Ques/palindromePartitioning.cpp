// LC - 131 - Medium - Palindrome Partitioning
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    int n;
    bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans,vector<string>curr,string s,int idx){
        if(idx>=n){
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(ans,curr,s,i+1);
                curr.pop_back();
            }
        }
    }
    public:
    vector<vector<string>> partition(string s){
        n=s.length();
        vector<vector<string>>ans;
        vector<string>curr;

        solve(ans,curr,s,0);
        return ans;
    }
};
int main(){
    // Output: [["a","a","b"],["aa","b"]]
    string s="aab";
    // Output: [["a"]]
    string s2="a";

    BackTracking sol;
    vector<vector<string>>ans=sol.partition(s);
    for(auto &vec:ans){
        cout<<"{";
        for(auto &s:vec) cout<<s<<",";
        cout<<"} ";
    }
    return 0;
}