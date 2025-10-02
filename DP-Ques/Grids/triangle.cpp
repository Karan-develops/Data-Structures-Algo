// LC - 120 - Medium - Triangle
// 3 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Top Down (Rec+Memo) - TLE
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&triangle,int i,int j){
        if(i>=n || j>=triangle[i].size()) return 1e9;

        if(i==n-1) return triangle[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int bottom=solve(triangle,i+1,j);
        int bottomRight=solve(triangle,i+1,j+1);

        return dp[i][j]=triangle[i][j]+min(bottom,bottomRight);
    }
    public:
    int minimumTotal(vector<vector<int>>&triangle){
        n=triangle.size();
        dp.assign(n,vector<int>(n,-1));

        return solve(triangle,0,0);
    }
};
// Approach 2 - Bottom Up - ACCEPTED
class BottomUp{
    public:
    int minimumTotal(vector<vector<int>>&triangle){
        int n=triangle.size();

        vector<vector<int>>dp=triangle;

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};
// Approach 3 - Space Optimized
class Optimized{
    public:
    int minimumTotal(vector<vector<int>>&triangle){
        int n=triangle.size();
        
        vector<int>dp=triangle.back();

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            }
        }

        return dp[0];
    }
};
int main(){
    // Output: 11
    vector<vector<int>>triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    // Output: -10
    vector<vector<int>>triangle2={{-10}};

    BottomUp sol;
    cout<<sol.minimumTotal(triangle)<<endl;
    cout<<sol.minimumTotal(triangle2);
    return 0;
}