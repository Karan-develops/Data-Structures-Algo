// LC - 221 - Medium - Maximal Square
// 2 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 1 - Top Down ( Rec+Memo )
class DP{
    int m,n;
    vector<vector<int>>dp;
    int solve(vector<vector<char>>&matrix,int i,int j){
        if(i>=m || j>=n) return 0;

        if(matrix[i][j]=='0') return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int bottom=solve(matrix,i+1,j);
        int diagonal=solve(matrix,i+1,j+1);
        int right=solve(matrix,i,j+1);

        return dp[i][j]=1+min({bottom,diagonal,right});
    }
    public:
    int maximalSquare(vector<vector<char>>&matrix){
        m=matrix.size();
        n=matrix[0].size();

        int ans=0;
        dp.resize(m+2,vector<int>(n+1,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    int sqSide=solve(matrix,i,j);
                    ans=max(ans,sqSide*sqSide);
                }
            }
        }
        return ans;
    }
};
// Approach 2 - Bottom Up
class BottomUp{
    public:
    int maximalSquare(vector<vector<char>>&matrix){
        if(matrix.size()==0) return 0;

        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));

        int side=matrix[0][0]=='0'?0:1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j]=='0'?0:1;
                } else if(matrix[i][j]=='1'){
                    // Because, if you have any 0, then you cannot expand side of square
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                side=max(side,dp[i][j]);
            }
        }
        return side*side;
    }
};
int main(){
    // Output: 4
    vector<vector<char>>matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    // Output: 1
    vector<vector<char>>matrix2={{'0','1'},{'1','0'}};
    // Output: 0
    vector<vector<char>>matrix3={{'0'}};

    DP sol;
    cout<<sol.maximalSquare(matrix)<<endl;
    cout<<sol.maximalSquare(matrix2)<<endl;
    cout<<sol.maximalSquare(matrix3);
    return 0;
}