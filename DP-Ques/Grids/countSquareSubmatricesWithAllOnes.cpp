// LC - 1277 - Medium - Count Square Submatrices with All Ones
// 2 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 1 - Top Down ( Rec+Memo )
class DP{
    int m,n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&matrix,int i,int j){
        if(i>=m || j>=n) return 0;

        if(matrix[i][j]==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(matrix,i,j+1);
        int diagonal=solve(matrix,i+1,j+1);
        int bottom=solve(matrix,i+1,j);

        return dp[i][j]=1+min({right,diagonal,bottom});
    }
    public:
    int countSquares(vector<vector<int>>&matrix){
        m=matrix.size();
        n=matrix[0].size();

        int ans=0;
        dp.resize(m+1,vector<int>(n+1,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    ans+=solve(matrix,i,j);
                }
            }
        }
        return ans;
    }
};
// Approach 2 - Bottom Up
class BottomUp{
    public:
    int countSquares(vector<vector<int>>&matrix){
        if(matrix.size()==0) return 0;

        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j];
                } else if(matrix[i][j]==1){
                    // Because, if you have any 0, then you cannot expand side of square
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
int main(){
    // Output: 15
    vector<vector<int>>matrix={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    // Output: 7
    vector<vector<int>>matrix2={{1,0,1},{1,1,0},{1,1,0}};

    DP sol;
    cout<<sol.countSquares(matrix)<<endl;
    cout<<sol.countSquares(matrix2);
    return 0;
}