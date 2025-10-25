// LC - 2140 - Medium - Solving Questions With Brainpower
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    long long solve(vector<vector<int>>&questions,vector<int>&dp,int i){
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i];

        int take=questions[i][0]+solve(questions,dp,i+questions[i][1]+1);
        int skip=solve(questions,dp,i+1);
        
        return dp[i]=max(take,skip);
    }
    public:
    long long mostPoints(vector<vector<int>>&questions){
        n=questions.size();
        vector<int>dp(n+1,-1);
        
        return solve(questions,dp,0);
    }
};
int main(){
    // Output: 5
    vector<vector<int>>questions={{3,2},{4,3},{4,4},{2,5}};
    // Output: 7
    vector<vector<int>>questions2={{1,1},{2,2},{3,3},{4,4},{5,5}};
    
    DP sol;
    cout<<sol.mostPoints(questions2);
    return 0;
}