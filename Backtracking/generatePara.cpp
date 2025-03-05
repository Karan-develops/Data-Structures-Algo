// Inclusion-exclusion concept involved
// Take open and close to keep track over the number of brackets available at each call
#include<iostream>
#include<vector>
using namespace std;
void solve(vector<string>&ans,int n,int open,int close,string output){
    // Base case
    if(open==0 && close==0){
        ans.push_back(output);
        return;
    }
    // include open bracket
    if(open>0){
        output.push_back('(');
        solve(ans,n,open-1,close,output);
        // Backtracking
        output.pop_back();
    }
    // include closing bracket
    if(close>open){
        output.push_back(')');
        solve(ans,n,open,close-1,output);
        // Backtracking
        output.pop_back();
    }
}
int main(){
    vector<string>ans;
    int n=3;
    int open=n,close=n;
    string output="";
    solve(ans,n,open,close,output);
    for(auto i:ans){
        cout<<"[";
        cout<<i;
        cout<<"] ";
    }
    return 0;
}