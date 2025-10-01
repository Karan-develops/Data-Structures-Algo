// LC - 931 - Medium - Minimum Falling Path Sum
// 2 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 1 - Top Down (Rec+Memo) - TLE
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&matrix,int i,int j){
        if(i>=n || j<0 || j>=n) return 1e9;

        if(i==n-1) return matrix[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int bottom=solve(matrix,i+1,j);
        int bottomLeft=solve(matrix,i+1,j-1);
        int bottomRight=solve(matrix,i+1,j+1);

        return dp[i][j]=matrix[i][j]+min({bottom,bottomLeft,bottomRight});
    }
    public:
    int minFallingPathSum(vector<vector<int>>&matrix){
        n=matrix.size();
        dp.assign(n,vector<int>(n,-1));

        int ans=INT_MAX;

        for(int col=0;col<n;col++){
            ans=min(ans,solve(matrix,0,col));
        }

        return ans;
    }
};
// Approach 2 - Bottom Up - ACCEPTED
class BottomUp{
    public:
    int minFallingPathSum(vector<vector<int>>&matrix){
        int n=matrix.size();

        vector<int>prev(matrix[n-1]);

        for(int i=n-2;i>=0;i--){
            vector<int>curr(n);
            for(int j=0;j<n;j++){
                int bottom=prev[j];
                int bottomLeft=(j>0)?prev[j-1]:1e9;
                int bottomRight=(j+1<n)?prev[j+1]:1e9;

                curr[j]=matrix[i][j]+min({bottom,bottomLeft,bottomRight});
            }
            prev=curr;
        }

        return *min_element(begin(prev),end(prev));
    }
};
int main(){
    // Output: 13
    vector<vector<int>>matrix={{2,1,3},{6,5,4},{7,8,9}};
    // Output: -59
    vector<vector<int>>matrix2={{-19,57},{-40,-5}};

    BottomUp sol;
    cout<<sol.minFallingPathSum(matrix)<<endl;
    cout<<sol.minFallingPathSum(matrix2);
    return 0;
}